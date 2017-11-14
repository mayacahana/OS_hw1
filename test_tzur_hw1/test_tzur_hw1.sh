#!/bin/bash

n=0

export HW1DIR=test_tzur_hw1
export HW1TF=peter_pan.txt

./hw1_subs a B | diff - ${HW1DIR}/peter_pan_a_B.txt
if [ "$?" != "0" ]; then echo "Error! test $n"; exit; fi
echo "Passed test ${n}!"
n=$(expr "$n" + "1")

./hw1_subs is "" | diff - ${HW1DIR}/peter_pan_is_.txt
if [ "$?" != "0" ]; then echo "Error! test $n"; exit; fi
echo "Passed test ${n}!"
n=$(expr "$n" + "1")

./hw1_subs lala kaka | diff - ${HW1DIR}/peter_pan_lala_kaka.txt
if [ "$?" != "0" ]; then echo "Error! test $n"; exit; fi
echo "Passed test ${n}!"
n=$(expr "$n" + "1")

./hw1_subs Peter "" | diff - ${HW1DIR}/peter_pan_Peter_.txt
if [ "$?" != "0" ]; then echo "Error! test $n"; exit; fi
echo "Passed test ${n}!"
n=$(expr "$n" + "1")

./hw1_subs $'.\r\n' " ENTER " | diff - ${HW1DIR}/peter_pan_dotCRLF_ENTER.txt
if [ "$?" != "0" ]; then echo "Error! test $n"; exit; fi
echo "Passed test ${n}!"
n=$(expr "$n" + "1")

./hw1_subs $'then Michael.\r\n\r\n' "" | diff - ${HW1DIR}/peter_pan_CRLF_then_Michael_CRLF_CRLF.txt
if [ "$?" != "0" ]; then echo "Error! test $n"; exit; fi
echo "Passed test ${n}!"
n=$(expr "$n" + "1")

export HW1TF=empty_file.txt
./hw1_subs asd "" | diff - ${HW1DIR}/empty_file.txt
if [ "$?" != "0" ]; then echo "Error! test $n"; exit; fi
echo "Passed test ${n}!"
n=$(expr "$n" + "1")

export HW1TF=empty_file_terminated.txt
./hw1_subs asd "" | diff - ${HW1DIR}/empty_file_terminated.txt
if [ "$?" != "0" ]; then echo "Error! test $n"; exit; fi
echo "Passed test ${n}!"
n=$(expr "$n" + "1")

export HW1TF=asd_file.txt
./hw1_subs asd "" | diff - ${HW1DIR}/empty_file_terminated.txt
if [ "$?" != "0" ]; then echo "Error! test $n"; exit; fi
echo "Passed test ${n}!"
n=$(expr "$n" + "1")
