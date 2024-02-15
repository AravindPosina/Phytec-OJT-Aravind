#!/bin/bash

if [[ $# -ne 2 ]]; then
	echo "you dint enter exactl;y 2 args"
	echo "usage : $0 <file1> <file2>"
	exit 1
fi
