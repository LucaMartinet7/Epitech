#!/bin/sh
read i < version
if [ "$1" == "+" ]; then
	i_new=$[$i+1]
elif [ "$1" == "-" ]; then
	i_new=$[$i-1]
fi
echo $i_new > version
