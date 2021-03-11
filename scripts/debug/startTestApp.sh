#!/bin/bash
if [ $# -eq 0 ] 
then
       	printf "Запуск с параметрами по умолчанию"
fi

cd ../../
CURRENT_DIR=$(pwd)/lib.linux/
LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${CURRENT_DIR}
export LD_LIBRARY_PATH

#echo $LD_LIBRARY_PATH

cd bin/debug/TestApp
./TestApp $1 $2 

