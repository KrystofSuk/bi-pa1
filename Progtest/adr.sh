#!/bin/bash
FILE=./video/*
for f in $FILE
do
	if [ ! -d "./video-$(echo $f|awk -F . '{print $NF}')" ]; then
		mkdir "./video-$(echo $f|awk -F . '{print $NF}')" 
	fi
	mv "$f" "./video-$(echo $f|awk -F . '{print $NF}')"
done
exit 0

