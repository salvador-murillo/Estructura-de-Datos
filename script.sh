#! /bin/bash
salir=1

PROGRAMAS=(
        '0.Debug' 
        '1.R1-Manejo-Arreglos' 
        '2.R2-Funciones' 
        '3.P1-Estructura-Simple' 
        '4.P2-Estructura-Anidada' 
        '5.P3-Estructura-Arreglos-Funciones'
)

mostrarTitulo(){
    clear
    echo $'\033[36m'$'ESTRUCTURA DE DATOS '$'\033[0m'' | '$'\033[33m''Universidad de Guadalajara'
    echo $'\033[0m'
}

mostrarSalida(){
    clear
    echo $'\n\t\t\t\t''    Creado por: '$'\033[34m'$'
        _____       _                _              __  __            _ _ _       
       / ____|     | |              | |            |  \/  |          (_| | |      
      | (___   __ _| __   ____ _  __| | ___  _ __  | \  / |_   _ _ __ _| | | ___  
       \___ \ / _` | \ \ / / _` |/ _` |/ _ \| ''__ | | |\/| | | | | ''__|  | | |/ _ \ 
       ____) | (_| | |\ V | (_| | (_| | (_) | |    | |  | | |_| | |  | | | | (_) |
      |_____/ \__,_|_| \_/ \__,_|\__,_|\___/|_|    |_|  |_|\__,_|_|  |_|_|_|\___/                                                                              
    '     
    echo $'\033[0m'$'\t\t¿Estas en '$'\033[31m''REPLIT'$'\033[0m''? Presiona '$'\033[32m''RUN'$'\033[0m'$' para volver a ejecutar\n'
}

while true
do
    mostrarTitulo
    echo $"Seleccione programa a ejecutar:"$'\n'

    for i in ${PROGRAMAS[@]};
    do
        echo $'\033[32m'"$i"
    done

    numeroPro=0
    read -p $'\033[0m'$'\n''Elige numero de programa: ' numeroPro
    echo $'\n''Cargando...' $'\033[33m'"#${PROGRAMAS[$numeroPro]}"
    cd "${PROGRAMAS[$numeroPro]}"
    echo $'\033[0m'
    clang++ -pthread -std=c++17 -o main main.cpp || make main && ./main
    
    
    echo $'\033[32m'$'\n''Volver a seleccion de programas?' $'\033[31m'
    read -p '1-SI 2-NO : ' salir
    echo $'\033[0m' #Reset Color Blanco
    if (($salir > 1))
        then
            mostrarSalida
            exit
    fi
    cd ..
done