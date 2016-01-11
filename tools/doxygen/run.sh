#!/bin/sh

set -ex
#cd $(dirname $0)/../..

rm -rf Docs/ref/
mkdir -p Docs/ref/
doxygen tools/doxygen/Doxyfile
