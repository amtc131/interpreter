#!/bin/bash

count=1

while [ $count -le 10 ]
do
#  echo $count
  ./lexer_test
  ((count++))
done
