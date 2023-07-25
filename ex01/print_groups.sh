#!/bin/bash
STR=$(id -Gn $FT_USER)
echo ${STR// /,}
