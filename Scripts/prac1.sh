#!/bin/bash

FILE = /home/Rahul/Desktop/Thesis/Problem-Set/Basic/CREDE2/ip
 
#[ -f "$FILE" ] || continue

iconv -c -f UTF8 -t ASCII "$FILE" > /tmp/$$ && cat /tmp/$$ > "$FILE"


rm -f /tmp/$$