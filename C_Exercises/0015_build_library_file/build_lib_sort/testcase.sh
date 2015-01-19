#!/bin/zsh
#########################################################################
# File Name: testcase.sh
# Author: Sam Wong
# Mail: ncepuwanghui@gmail.com
# Blog: http://samwong.im
# Created Time: Sun 18 Jan 2015 07:06:46 PM CST
#########################################################################

case ${1} in
    "--static")
        rm ./bin/testcase
        gcc -o ./bin/testcase  testcase.c --static -L./lib -lsort
        ./bin/testcase ${2} ${3}
        ;;
    "--share")
        rm ./bin/testcase
        export LD_LIBRARY_PATH=./lib;$LD_LIBRARY_PATH;
        gcc -o ./bin/testcase testcase.c -L./lib -I./include -lsort
        ./bin/testcase ${2} ${3}
        ;;
     *)
         echo "Usage: ./testcase.sh --static|--share size range"
esac
