#/bin/bash

echo "-------------" > ./files.txt

# Directories identity
for a in $( ls -d ./test/*/ ); do
	tar -cf $a $a | md5sum >> ./files.txt
done

# Files identity
for a in $( find ./test/ -maxdepth 1 -type f ); do
	md5sum $a >> ./files.txt
done

cat ./files.txt | sort 
