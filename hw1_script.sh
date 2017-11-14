#!/bin/bash
#find . -name ${HW1DIR} -type d -print0|xargs -0 rm -r --
rm -rf ${HW1DIR}
mkdir ${HW1DIR} 
chmod 755 ${HW1DIR}
cd ${HW1DIR}
cp ${1} ${HW1TF}
chmod 744 ${HW1TF}
cd ..
./hw1_sub cat dog
