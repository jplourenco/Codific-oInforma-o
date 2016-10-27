#! /bin/bash


LIST="./calgary";

echo $LIST

    eval "time ./lzw.sh"
    eval "rm ./calgary/*.lzw"
    eval "time ./lzwr1.sh"
    eval "rm ./calgary/*.lzw"
    eval "bzip2 -kfq $LIST"
    eval "gzip -kfq $LIST"
