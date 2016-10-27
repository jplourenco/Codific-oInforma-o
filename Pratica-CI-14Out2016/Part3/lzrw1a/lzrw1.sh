#! /bin/bash


LIST="./calgary";

echo $LIST

for each in $LIST/*;  
do
    eval "./lzrw1 $each"
done 