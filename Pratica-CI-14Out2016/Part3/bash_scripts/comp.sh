#! /bin/bash


LIST="./calgary";

echo $LIST

    eval "time ./lzw.sh"
    eval "rm ./calgary/*.lzw"
    eval "time ./lzrw1.sh"
    eval "rm ./calgary/*.lzwr1"
    eval "time bzip2 -kfq $LIST/*"
    eval "rm ./calgary/*.bz2"
    eval "time gzip -kfq $LIST/*"
    eval "rm ./calgary/*.gz"
