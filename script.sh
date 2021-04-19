#! /bin/bash
salir=1

SECCIONES=(
        '0.Debug' 
        '1.R1-Manejo-Arreglos' 
        '2.R2-Funciones' 
        '3.P1-Estructura-Simple' 
        '4.P2-Estructura-Anidada' 
        '5.P3-Estructura-Arreglos-Funciones' 
        '6.P4-Punteros' 
        '7.P5-Par-Impar' 
        '8.P6-Aritmetica-Int' 
        '9.P7-Aritmetica-Double' 
        '10.P8-Apuntador-Char' 
        '11.P9-Funciones-Strings' 
        '12.P10-Apuntadores_y_Cadenas'
)

repaso=(

)

mostrarTitulo(){
    clear
    echo $'\033[36m'$'ESTRUCTURA DE DATOS '$'\033[0m'' | '$'\033[33m''Universidad de Guadalajara'
    echo $'\033[0m'
}

mostrarSalida(){
    clear
    echo -n $'\n\t\t\t''    Creado por: '$'\033[34m'$'
              ____        _                _            
             / ___|  __ _| |_   ____ _  __| | ___  _ __ 
             \___ \ / _` | \ \ / / _` |/ _` |/ _ \| __|
              ___) | (_| | |\ V / (_| | (_| | (_) | |   
             |____/ \__,_|_| \_/ \__,_|\__,_|\___/|_|   
     '
     echo $'\033[33m'$'
                                       _ _ _       
                  _ __ ___  _   _ _ __(_) | | ___  
                 | `_ ` _ \| | | | `__| | | |/ _ \ 
                 | | | | | | |_| | |  | | | | (_) |
                 |_| |_| |_|\__,_|_|  |_|_|_|\___/ 
    '     
    echo $'\033[0m'$'\n\t¿Estas en '$'\033[31m''REPLIT'$'\033[0m''? Presiona '$'\033[32m''RUN'$'\033[0m'$' para volver a ejecutar\n'
}

while true
do
    mostrarTitulo
    #TODO Cambiar modo de ingreso a programas por secciones
    echo $"Seleccione programa a ejecutar:"$'\n'
    for i in ${SECCIONES[@]};
    do
        echo $'\033[32m'"$i"
    done

    numeroPro=0
    read -p $'\033[0m'$'\n''Elige numero de programa: ' numeroPro
    echo $'\n''Cargando...' $'\033[33m'"#${SECCIONES[$numeroPro]}"
    cd "${SECCIONES[$numeroPro]}"
    echo $'\033[0m'
    #TODO Hacer funcion para validar que el numero ingresado exista
    # if (( numeroPro >=0 && numeroPro <= ))
    # fi
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