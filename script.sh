#! /bin/bash
salir=1
while true
do
    clear
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

    numeroPro=0
    read -p $'\n''Elige numero de programa: ' numeroPro
    echo $'\n'"Cargando: Programa #${PROGRAMAS[$numeroPro-1]}"
    cd "${PROGRAMAS[$numeroPro-1]}"
    
    clang++ -pthread -std=c++17 -o main main.cpp || make main && ./main

    read -p $'Volver a seleccion de programas? 1-SI 2-NO : ' salir
    if (($salir > 1))
        then
            exit
    fi
    cd ..
done