#!/bin/sh
## tcp_syncookies_switch.sh for tcp_syncookies_switch
## 
## Made by SRJanel
## Login SRJanel <n******.******s@epitech.eu>
## 
## Started on  Tue Sep 19 15:27:00 2017 
## Last update Tue Sep 19 15:38:41 2017 
##

## CODE REPETITION | change code
TCP_SYNCOOKIES=`cat /proc/sys/net/ipv4/tcp_syncookies`
RED="\033[1;31m"
GREEN="\033[1;32m"
NO_COLOR="\033[0m"

if [ $TCP_SYNCOOKIES -eq 0 ]; then
    echo 1 > /proc/sys/net/ipv4/tcp_syncookies &> /dev/null
    if [ $? -eq 0 ]; then
	echo -e $RED"TCP SynCookies enabled"$NO_COLOR
    else
	echo "Run as root ?"
    fi
else
    echo 0 > /proc/sys/net/ipv4/tcp_syncookies &> /dev/null
    if [ $? -eq 0 ]; then
	echo -e $GREEN"TCP SynCookies disabled"$NO_COLOR
    else
	echo "Run as root ?"
    fi
fi
