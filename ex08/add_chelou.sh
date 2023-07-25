#!/bin/sh
NUM1=$(echo "$FT_NBR1" | tr \'\\\\\"\?\! '01234')
NUM2=$(echo "$FT_NBR2" | tr mrdoc '01234')
RES=$(echo "obase=13; ibase=5; $NUM1 + $NUM2" | bc)

echo $RES | tr '0123456789abc' 'gtaio luSnemf'
