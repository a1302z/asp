#!/bin/sh
gcc -marm -mfpu=neon -o main matQuad.S main.c && ./main $@
