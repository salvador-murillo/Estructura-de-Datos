#! /bin/bash
salir=1
while true
do
    clear
    echo $'\t\t\t'"CUCEA | Estructura de Datos | Salvador Murillo Arias"
    echo $'\n'"Seleccione programa a ejecutar:"$'\n'

    PROGRAMAS=(
        '0.Debug' 
        '1.R1-Manejo-Arreglos' 
        '2.R2-Funciones' 
        '3.P1-Estructuras'
    )

    for i in ${PROGRAMAS[@]};
    do
        echo "$i"
    done

    numeroPro=0
    read -p $'\n''Elige numero de programa: ' numeroPro
    echo $'\n'"Cargando: Programa #${PROGRAMAS[$numeroPro]}"
    cd "${PROGRAMAS[$numeroPro]}"
    
    clang++ -pthread -std=c++17 -o main main.cpp || make main && ./main

    read -p $'Volver a seleccion de programas? 1-SI 2-NO : ' salir
    if (($salir > 1))
        then
            exit
    fi
    cd ..
done