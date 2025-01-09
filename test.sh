#!/bin/bash

ARG="1 3 6 3 1 04"
./push_swap "$ARG" > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}7.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}7.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}7.[KO] ${DEF_COLOR}\n";
fi
