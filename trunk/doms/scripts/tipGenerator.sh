#!/bin/bash

NFORTUNES=100
SECTION=""

TIPS="tips_$RANDOM"

echo $TIPS

if [ ! -x "`which fortune`" ]
then
	echo "Please install fortune-mod"
	exit 1
fi

echo "<TipOfDay>" > $TIPS

if [ $1 ]
then
	SECTION=$1
fi

echo .$1.

for i in `seq 1 $NFORTUNES`
do
	FORTUNE=`fortune $SECTION`
	echo "	<tip>${FORTUNE}</tip>" >> $TIPS
done


echo "</TipOfDay>" >> $TIPS



