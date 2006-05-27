#!/bin/bash

FILES=`find . -name "*.html"`

for file in $FILES
do
	echo "Fixing $file..."
	sed 's/�/\&aacute;/g' -i $file
	sed 's/�/\&eacute;/g' -i $file
	sed 's/�/\&iacute;/g' -i $file
	sed 's/�/\&oacute;/g' -i $file
	sed 's/�/\&uacute;/g' -i $file
	sed 's/�/\&ntilde;/g' -i $file
done

