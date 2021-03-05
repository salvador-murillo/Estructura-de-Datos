#! /bin/bash
clear

numeroPro=0

echo $'\t\t\t'"Estructura de Datos"
echo $'\n'"Seleccione programa a ejecutar:"$'\n'

echo "00.Repaso - Manejo de Arreglos"
echo "01.Repaso - Funciones"
echo "3.test" $'\n'

cd test



clang++-7 -pthread -std=c++17 -o main main.cpp && ./main


