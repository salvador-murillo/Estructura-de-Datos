#! /bin/bash
salir=1
numeroSecU=0

SECCIONES=(
    '0.Debug'
    '1.REPASO-FUNDAMENTOS' 
    '2.ESTRUCTURAS' 
    '3.PUNTEROS-INTRODUCCION' 
    '4.PUNTEROS-ARITMETICA' 
    '5.PUNTEROS-STRINGS' 
    '6.PUNTEROS-A-ESTRUCTURAS'
    '7.PILAS' 
    '8.COLAS'
    '9.LISTAS'
    '10.Proyecto-Final'
)
proTema0=(
   'debug')

proTema1=(
    'R1-Manejo-Arreglos' 
    'R2-Funciones')

proTema2=(
    '1.Estructura-Simple' 
    '2.Estructura-Anidada' 
    '3.Estructura-Arreglos-Funciones')

proTema3=(
    '4.Punteros' 
    '5.Par-Impar')

proTema4=(
    '6.Aritmetica-Int' 
    '7.Aritmetica-Double')

proTema5=(
    '8.Apuntador-Char' 
    '9.Funciones-String' 
    '10.Apuntadores_y_Cadenas')

proTema6=(
    '11.Manejo-Memoria-Dinamica-MALLOC' 
    '12.Manejo-Memoria-Dinamica-NEW')

proTema7=(
    '13.Pilas-1')

proTema8=(
    '14.Colas-1')

proTema9=(
    '15.Listas-1'
    '16.Listas-2')

proTema10=(
    '17.Sistema-Renta-Smoking'
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

mostrarSeccion(){
   salirSec1=1
   while [[ $salirSec1 > 0  ]]; 
   do
        mostrarTitulo
        echo $"Secciones a mostrar:"$'\n'
        # j=0 # TEST para ocultar proyecto
        for i in ${SECCIONES[@]};
        do
            
            # if [[ j -eq 10 ]]; then
            #     echo $'\033[8;32m'"$i"
            # else
            echo $'\033[32m'"$i" # FIXME dejar solo esta linea dentro del for
            # fi
            # j=$(($j+1))
        done

        numeroSecU=0
        numeroSec=${#SECCIONES[@]}
        
        read -p $'\033[0m'$'\n''Elige numero de sección: ' numeroSecU
        if [[ $numeroSecU -ge 0 && $numeroSecU -le $numeroSec ]]
            then
                cd "${SECCIONES[$numeroSecU]}"
                salirSec1=0
            else
                echo $'\n\033[31m''Numero N0 Valido'$'\n\033[0m''Regresando a menu...'
                sleep 1.5
                clear
        fi
    done 
}

mostrarProgramas(){
    salirSec2=1
    while [[ $salirSec2 > 0 ]]; 
    do
        mostrarTitulo
        echo $'TEMA '${SECCIONES[$numeroSecU]}$'\n\nProgramas:'
        
        pro=proTema$numeroSecU[@] #Creacion de variable para array indirecto de acuerdo a la categoria
        for j in ${!pro}
        do
            echo $'\033[32m'"$j" #Muestra Programas de acuerdo a la categoria
        done

        numeroPro=0
        if [[ $numeroSecU -ge 0 && $numeroSecU -le 1 ]]; then
            read -p $'\n\033[0m''Escriba LETRA y NUMERO (E1) de programa: ' numeroPro
        else
            read -p $'\n\033[0m''Escriba NUMERO (1) de programa: ' numeroPro
        fi

        #--Determinar calcular programa

        if [[ numeroSecU -eq 0 ]] && [[ $numeroPro == 'debug' || $numeroPro == 'd' ]]; then
            numeroPro=0
            salirSec2=0
        elif [[ numeroSecU -eq 1 ]] && [[ $numeroPro == 'R1' || $numeroPro == 'r1' ]]; then
            numeroPro=0
            salirSec2=0
        elif [[ numeroSecU -eq 1 ]] && [[ $numeroPro == 'R2' || $numeroPro == 'r2' ]]; then
            numeroPro=1
            salirSec2=0
        elif [[ numeroSecU -eq 2 ]] && [[ numeroPro -ge 1 && numeroPro -le 3 ]]; then
            numeroPro=$((numeroPro-1))
            salirSec2=0
        elif [[ numeroSecU -eq 3 ]] && [[ numeroPro -eq 4 || numeroPro -eq 5 ]]; then
            numeroPro=$((numeroPro-4))
            salirSec2=0
        elif [[ numeroSecU -eq 4 ]] && [[ numeroPro -eq 6 || numeroPro -eq 7 ]]; then
            numeroPro=$((numeroPro-6))
            salirSec2=0
        elif [[ numeroSecU -eq 5 ]] && [[ numeroPro -ge 8 && numeroPro -le 10 ]]; then
            numeroPro=$((numeroPro-8))
            salirSec2=0
        elif [[ numeroSecU -eq 6 ]] && [[ numeroPro -eq 11 || numeroPro -eq 12 ]]; then
            numeroPro=$((numeroPro-11))
            salirSec2=0
        elif [[ numeroSecU -eq 7 ]] && [[ numeroPro -eq 13 ]]; then
            numeroPro=$((numeroPro-13))
            salirSec2=0
        elif [[ numeroSecU -eq 8 ]] && [[ numeroPro -eq 14 ]]; then
            numeroPro=$((numeroPro-14))
            salirSec2=0
        elif [[ numeroSecU -eq 9 ]] && [[ numeroPro -eq 15 || numeroPro -eq 16 ]]; then
            numeroPro=$((numeroPro-15))
            salirSec2=0
        elif [[ numeroSecU -eq 10 ]] && [[ numeroPro -eq 17 ]]; then
            numeroPro=$((numeroPro-17))
            salirSec2=0
        else
            echo $'\n\033[31m''Numero NO Valido'$'\n\033[0m''Seleccione de nuevo...'
            sleep 1.5
            clear
        fi
        #--Termina calcular programa
        
        if [[ salirSec2 -eq 0 ]]; then
            ruta=proTema$numeroSecU[$numeroPro]
            echo $'\n''Cargando...'$'\033[33m'"#${!ruta}"$'\033[0m'
            cd "${!ruta}"
            sleep 2
        fi
    done
}

while true
do
    #--Funcion para mostrar SECCIONES
    mostrarSeccion
    
    #--Funcion para mostrar PROGRAMAS
    mostrarProgramas
    
    if [[ numeroSecU -eq 10 ]]; then
        clang++ -pthread -std=c++17 -o main main.cpp  src/intro.cpp src/struct-smoking.cpp src/date-time.cpp || make main && ./main
    else
        clang++ -pthread -std=c++17 -o main main.cpp || make main && ./main
    fi
    echo $'\033[32m'$'\n''Volver a seleccion de programas?' $'\033[31m'
    read -p '1-SI 2-NO : ' salir
    echo $'\033[0m' #Reset Color Blanco
    if (($salir > 1))
        then
            mostrarSalida
            cd ../..
            exit
    fi
    cd ../..
done