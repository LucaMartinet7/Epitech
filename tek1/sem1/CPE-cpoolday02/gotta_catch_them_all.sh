#!/bin/bash
cut -d: -f 5 | cut -d" " -f 2 | grep -c -i "^$1"
