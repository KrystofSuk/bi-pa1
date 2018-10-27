#!/bin/bash
CODE=C:/Users/sukkr/source/repos/Progtest/$1/prog.c
EXPORT=C:/Users/sukkr/source/repos/Progtest/$1/prog.exe

GREEN='\033[1;32m'
CYAN='\033[1;36m'
NC='\033[0m'

echo `gcc -Wall -pedantic $CODE -o $EXPORT`
echo -e "${GREEN}Compiling finished"
if [ $2 == "test" ]
then
    echo -e "${CYAN}Test initialized:"
    echo -e "${NC}"
    printf "$(./Tester.sh $1 $3)"
else
    echo "No testing parameter"
    echo -e "${NC}"
fi