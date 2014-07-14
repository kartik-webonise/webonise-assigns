#!/bin/bash
var=$(cd /home/webonise-assignment/ | ls -R   | head -4)
for file in $var;
do
mv $file /home/webonise-assignment/public_html/
done
echo $var
