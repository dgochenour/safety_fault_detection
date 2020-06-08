cmake_minimum_required(VERSION 2.8.4)

project(motion_controller C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(RTIDDSGEN $ENV{RTIMEHOME}/rtiddsgen/scripts/rtiddsgen)
set_property(GLOBAL PROPERTY RULE_MESSAGES OFF)

set(IDL_SOURCE_C ./idl/Engagement_t.idl)

set(IDL_GEN_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/gen)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/objs/${RTIME_TARGET_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/objs/${RTIME_TARGET_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/objs/${RTIME_TARGET_NAME})

if(NOT EXISTS gen)
    execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory gen)
endif()

set(RTI_LIB_PREFIX rti_me)
set(RTI_LIB_SUFFIX)

if(NOT (DEFINED RTI_SHARED_LIB))
    if(${CMAKE_BUILD_TYPE} MATCHES "[Rr]elease")
        set(RTI_LIB_SUFFIX "z")
        set(RTI_DEBUG_BUILD FALSE)
        add_definitions(-DNDEBUG)
    else()
        set(RTI_LIB_SUFFIX "zd")
        set(RTI_DEBUG_BUILD TRUE)
    endif()
else()
    if(${CMAKE_BUILD_TYPE} MATCHES "[Rr]elease")
        set(RTI_LIB_SUFFIX "")
        set(RTI_DEBUG_BUILD FALSE)
        add_definitions(-DNDEBUG)
    else()
        set(RTI_LIB_SUFFIX "d")
        set(RTI_DEBUG_BUILD TRUE)
    endif()
endif()

set(MICRO_C_LIBS rti_me_rhsm${RTI_LIB_SUFFIX} 
                 rti_me_whsm${RTI_LIB_SUFFIX} 
                 rti_me_discdpse${RTI_LIB_SUFFIX} 
                 rti_me${RTI_LIB_SUFFIX}
                                                   )

message("RTIME_TARGET_NAME = ${RTIME_TARGET_NAME}")
include_directories(gen/ $ENV{RTIMEHOME}/include $ENV{RTIMEHOME}/include/rti_me)
link_directories($ENV{RTIMEHOME}/lib/${RTIME_TARGET_NAME})

foreach(idl ${IDL_SOURCE_C})
    get_filename_component(filename ${idl} NAME)
    string(REGEX REPLACE "\\.idl" "" basename ${filename})
    list(APPEND IDL_GEN_C ${IDL_GEN_ROOT}/${basename}.c
                          ${IDL_GEN_ROOT}/${basename}Plugin.c
                          ${IDL_GEN_ROOT}/${basename}Support.c)
                          
    list(APPEND IDL_GEN_H ${IDL_GEN_ROOT}/${basename}.h
                          ${IDL_GEN_ROOT}/${basename}Plugin.h  
                          ${IDL_GEN_ROOT}/${basename}Support.h)
                          
    add_custom_command(OUTPUT ${IDL_GEN_C} ${IDL_GEN_H} 
                       COMMAND ${RTIDDSGEN} -verbosity 1 -language C -micro 
                               -replace 
                               -d ${IDL_GEN_ROOT}/. ${CMAKE_CURRENT_SOURCE_DIR}/${idl}
                       DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${idl}
                       COMMENT "Regeneration type support plugin from ${idl}"
    )    
    set_source_files_properties(${IDL_GEN_C} ${IDL_GEN_H} PROPERTIES GENERATED 1)
endforeach()

add_executable(motion_controller
               ${CMAKE_CURRENT_SOURCE_DIR}/motion_controller.c
                                             ${IDL_GEN_C} ${IDL_GEN_H})

add_executable(throttle_system 
               ${CMAKE_CURRENT_SOURCE_DIR}/throttle_system.c
                                             ${IDL_GEN_C} ${IDL_GEN_H})

target_link_libraries(throttle_system ${MICRO_C_LIBS} ${PLATFORM_LIBS})
target_link_libraries(motion_controller ${MICRO_C_LIBS} ${PLATFORM_LIBS})