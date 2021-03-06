#! /bin/bash
clear

numeroPro=0

echo $'\t\t\t'"Estructura de Datos"
echo $'\n'"Seleccione programa a ejecutar:"$'\n'

PROGRAMAS=(
    '1.Repaso-Manejo-Arreglos' 
    '2.Repaso-Funciones' 
    '3.test')

for i in ${PROGRAMAS[@]};
do
    echo "$i"
done

read -p $'\n''Elige numero de programa: ' numeroPro
cd "${PROGRAMAS[$numeroPro-1]}"

clang++ -pthread -std=c++17 -o main main.cpp || make main && ./main