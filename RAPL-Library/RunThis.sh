#!/bin/bash

sudo modprobe msr

out=MiltonOutput.txt

sudo ./test > $out
echo '--------------------' >> $out
./cpu-model >> $out

cat $out
