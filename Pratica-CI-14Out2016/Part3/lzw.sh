#! /bin/bash


LIST="./calgary";

echo $LIST

for each in $LIST/*;  
do
    eval "./lzw $each"
done 