#!/bin/bash

export RTIMEHOME=/home/don/rti_connext_dds_micro-2.4.12
export RTIMEARCH=x64Linux5gcc9.3.0

$RTIMEHOME/resource/scripts/rtime-make --config Release --build --name $RTIMEARCH --target Linux --source-dir . -G "Unix Makefiles" --delete