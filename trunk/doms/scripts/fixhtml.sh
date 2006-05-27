#!/bin/bash

FILES=`find . -name "*.html"`

for file in $FILES
do
	echo "Fixing $file..."
	sed 's/á/\&aacute;/g' -i $file
	sed 's/é/\&eacute;/g' -i $file
	sed 's/í/\&iacute;/g' -i $file
	sed 's/ó/\&oacute;/g' -i $file
	sed 's/ú/\&uacute;/g' -i $file
	sed 's/ñ/\&ntilde;/g' -i $file
done

