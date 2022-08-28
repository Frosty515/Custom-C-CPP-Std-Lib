#!/bin/sh

sh ./Clean.sh
sh ./GenerateProjects.sh
make all config=$1