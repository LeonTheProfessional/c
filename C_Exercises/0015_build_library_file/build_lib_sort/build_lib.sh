#!/bin/zsh
#########################################################################
# File Name: build_lib.sh
# Author: Sam Wong
# Mail: ncepuwanghui@gmail.com
# Blog: http://samwong.im
# Created Time: Sun 18 Jan 2015 05:56:27 PM CST
#########################################################################

echo "========================================"
echo "*********************************"
echo "	1.create static lib	"
echo "	2.create shared lib "
echo "*********************************"
echo "========================================"
echo "please input your operator:"
read op

SRCDIR="./source/"
case $op in
	"1")
        rm $SRCDIR*.o
        for i in `ls $SRCDIR`
        do
            gcc -c $SRCDIR$i -o $SRCDIR$i.o
        done
        rm ./lib/libsort.a
		ar crsv -o ./lib/libsort.a $SRCDIR*.o
        rm $SRCDIR*.o
		;;
	"2")
        rm $SRCDIR*.o
        for i in `ls $SRCDIR`
        do
            gcc -c $SRCDIR$i -o $SRCDIR$i.o
        done
        rm ./lib/libsort.so
		gcc -shared -fPIC -o ./lib/libsort.so ${SRCDIR}*.o
        rm $SRCDIR*.o
		;;
	*)
		exit 3
		;;
esac

