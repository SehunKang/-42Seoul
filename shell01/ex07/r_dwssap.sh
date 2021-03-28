#!/bin/sh

cat /etc/passwd | sed '/#/d' | sed -n 'p;n' | cut -f 1 -d ':' | rev | sort -r |  awk -v FT_LINE1="$FT_LINE1" -v FT_LINE2="$FT_LINE2"  'NR >= FT_LINE1 && NR <= FT_LINE2 {print $0}' | tr '\n' ',' |sed 's/,/, /g' | sed 's/..$/./g'
