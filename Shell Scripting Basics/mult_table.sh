#!/bin/bash

echo "Enter a number: "
read num

echo "Multiplication Table for $num:"
for i in {1..10}
do
    echo "$num x $i = $((num * i))"
done
