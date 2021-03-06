#! /bin/bash
clear

numeroPro=0

echo $'\t\t\t'"Estructura de Datos"
echo $'\n'"Seleccione programa a ejecutar:"$'\n'

# PROGRAMAS=(
#     '00.Repaso - Manejo de Arreglos' 
#     '01.Repaso - Funciones' 
#     '3.test' 
#     '4.jar')

PROGRAMAS2=(
    '1.Repaso-Manejo-Arreglos' 
    '2.Repaso-Funciones' 
    '3.test')

for i in ${PROGRAMAS2[@]};
do
    echo "$i"
done

read -p $'\n''Elige numero de programa: ' numeroPro
cd "${PROGRAMAS2[$numeroPro-1]}"

#make for macOS and clang for Repl.it
clang++-7 -pthread -std=c++17 -o main main.cpp || make main && ./main

#|| make main 


