#!/bin/bash

# This line is a comment and will not execute
### This line is another comment and will not execute


get_statistics()
{
	echo "This function is placeholder for statistics"
}

script_name=$0
command_line_args1=$1
command_line_args2=$2

get_statistics
echo "Script Name is $script_name"
echo "Script Name is ${script_name} brace use"
echo "First args = ${command_line_args1}"
echo "Second args = ${command_line_args2}"

NUM=23
if [ $NUM -eq 23 ]
then
	echo "Match"
fi

## This tells what is the exit status from Shell
## It need not be zero. But zero usually means sucess
## Non-zero are errors.
exit 0
#This function is placeholder for statistics
#Script Name is ./01_generic.sh
#Script Name is ./01_generic.sh brace use
#First args = 
#Second args = 

