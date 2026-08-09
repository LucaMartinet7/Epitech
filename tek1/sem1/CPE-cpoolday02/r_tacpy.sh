#!/bin/bash
cut -d: -f 1 | sed -n 2~2p | rev | sort -r | head -n $MY_LINE2 | tail -n  $(($MY_LINE2 - $MY_LINE1 +1)) | tr \\n ',' | sed 's/,/, /g' | sed 's/, $/\.\n/' 
