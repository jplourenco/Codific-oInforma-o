#! /bin/bash


LIST="./calgary";

echo "BZ"
eval "time bzip2 -kfq $1"
eval "rm $1.bz2"
echo ""
echo "Gz"
eval "time gzip -kfq $1"
eval "rm $1.gz"

echo "LZW"
eval "time ./lzw $1"
eval "rm $1.lzw"
echo "LZRW1"
eval "time ./lzrw1 $1"
eval "rm $1.lzwr1"

