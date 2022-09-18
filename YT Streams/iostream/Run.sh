#!/bin/bash

if (($# < 1))
then
sh ./Build.sh debug
else
sh ./Build.sh $1
fi
echo -----------------------
echo Running...
echo -----------------------
if (($# < 1))
then
./bin/debug-linux-x86_64/Testing
else
./bin/$1-linux-x86_64/Testing
fi
