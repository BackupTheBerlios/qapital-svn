#!/bin/bash

find $1 -iname "$2" -print -follow | sed "s/ /\\\ /g" | xargs egrep -H -n -e "$3"

