#! /bin/bash


LIST="./calgary";

echo $LIST

for each in $LIST/*;  
do
    eval "./lzwr1 $each"
done 