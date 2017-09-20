#!/bin/sh
## tcp_syncookies_switch.sh for tcp_syncookies_switch
## 
## Made by SRJanel
## Login SRJanel <n******.******s@epitech.eu>
## 
## Started on  Tue Sep 19 15:27:00 2017 
## Last update Wed Sep 20 20:05:32 2017 
##

TCP_SYNCOOKIES=`cat /proc/sys/net/ipv4/tcp_syncookies`
RED="\033[1;31m"
GREEN="\033[1;32m"
NO_COLOR="\033[0m"

check()
{
    if [ $1 -eq 0 ]; then
	echo -e $2"TCP SynCookies "$3$NO_COLOR
    else
	echo "Run as root ?"
    fi
}

if [ $TCP_SYNCOOKIES -eq 0 ]; then
    bash -c 'echo "1" > /proc/sys/net/ipv4/tcp_syncookies'
    check $? $RED "enabled"
else
    bash -c 'echo "0" > /proc/sys/net/ipv4/tcp_syncookies'
    
    check $? $GREEN "disabled"
    
fi
