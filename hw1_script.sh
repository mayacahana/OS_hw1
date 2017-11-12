#!/bin/bash
directory = $1
find . -name ${HW1DIR} -type d -print0|xargs -0 rm -r --
