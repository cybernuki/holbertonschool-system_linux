#!/bin/sh

if [ $# -eq 1  ]
then
	kill -QUIT $1
else
	echo "Usage: $0 <pid>"
	exit 1
fi
