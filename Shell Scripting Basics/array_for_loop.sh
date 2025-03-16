#!/bin/bash

echo "Arguments are: "
array=($@)
for item in "${array[@]}"; do
    echo $item
done