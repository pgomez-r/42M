#!/bin/sh
cat /etc/passwd | grep -v -e "#" | awk "NR % 2 == 0" | cut -d':' -f1 | rev | sort -rn