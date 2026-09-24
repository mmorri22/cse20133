#!/bin/bash
BASE=https://raw.githubusercontent.com/mmorri22/cse20133/main/homeworks/homework04
for f in hw04.c calibrate.c calibrate.h; do
    wget -q $BASE/$f
done
echo "Downloaded: hw04.c  calibrate.c  calibrate.h"
echo "You must write your own Makefile."
rm setup.sh