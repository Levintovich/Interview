#/bin/bash

# Executing ./config $1 $2
# where $1 - key name; $2 - value
# If key exists need to modify value only
# If not - to create a new key with the new value
#######################################################

#################################################
#Checking parameters
#############################################

# Parameters existing checking
if [ $# -eq 0 ]; then
	echo "No arguments supplied. Program is terminated"
	exit 1
fi

# Value Parameter existing checking
if [ -z "$2" ]; then
    echo "No value. Please define a value. Program is terminated"
fi

# Checking that first parameter (key) is OK
if [[ $1 =~ ^key[0-9]+$ ]]; then
	echo "Checking parameter $1"	
else
	echo "Incorrect parameter $1. Program is terminated"
	exit 1
fi

cat ./config.ini > ./config2.ini
# Checking entering key existence 
if grep -q "^$1=" "./config.ini"; then
	echo "Parameter $1 exists. Updating value"	
#	sed -i ./config2.ini -e 's/^key[0-9]*/kooooo/g'
	sed -i ./config2.ini -e "s/^$1=.*$/$1=$2/g"
else
	echo "Parameter $1 doesn't exist. Creating new value"
	echo "$1=$2" >> ./config2.ini
fi


