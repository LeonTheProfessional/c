#!/bin/zsh
#########################################################################
# File Name: calculate.sh
# Author: Sam Wong
# Mail: ncepuwanghui@gmail.com
# Blog: http://samwong.im
# Created Time: Sat 17 Jan 2015 11:36:15 PM CST
#########################################################################

echo "========================================"
echo "*********************************"
echo "  1.create static lib "
echo "  2.create shared lib "
echo "*********************************"
echo "========================================"
echo "please input your operator:"
read op

case $op in
    "1")
        gcc -c ${1}.c
        ar crsv lib${1}.a ${1}.o
        gcc -o ${2} ${2}.c -L. -l${1}
        ./${2}
        rm *.o *.a ${2}
        ;;
    "2")
        gcc -fpic -c ${1}.c
        gcc -shared -o lib${1}.so ${1}.o
        gcc -o ${2} ${2}.c -L. -l${1}
        sudo cp lib${1}.so /usr/lib/
        ./${2}
        sudo rm /usr/lib/lib${1}.so
        rm *.so *.o ${2}
        ;;
    *)
        exit 3
        echo "Usage: ./calculate calculate main"
        ;;
esac
