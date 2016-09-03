#/bin/bash

mkdir -p ./test
mkdir -p ./test/test1
mkdir -p ./test/test2
mkdir -p ./test/test3

echo "I am A file" > ./test/test1/A
echo "I am A file" > ./test/test2/A
echo "I am B file" > ./test/test2/B
echo "I am C file" > ./test/test3/C

echo "I am A file" > ./test/A
echo "I am A file" > ./test/AA

echo "I am B file" > ./test/B
echo "I am B file" > ./test/BB

echo "I am C file" > ./test/C
echo "I am C file" > ./test/CC

echo "I am D file" > ./test/D
echo "I am DD file" > ./test/DD