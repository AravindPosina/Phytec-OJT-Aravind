#!/bin/bash

df_func()
{
	disk_drive1=$1
	disk_drive2=$2

	echo "..........First Disk free space........"
	df -kh ${disk_drive1}
	echo "..........Second Disk free space........"
	df -kh ${disk_drive2}
}

echo "This program displays the disk free space"

DISK_1=$1
DISK_2=$2

df_func $DISK_1 $DISK_2
