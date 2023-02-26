/**
 * Puesta en marcha de Parametros.h
*/
#include <iostream>
using namespace std;

#include "Parametros.h"

Parametros::Parametros(Mensajes mensajes)
{
    out = mensajes;
}

Parametros::~Parametros()
{
}

/**
 * Inicializa el campo para el nivel del juego
 * Soicita al usuario el nivel de juego, si el parametro 
 * no es valido inicializa el nivel a un valor consistente.
*/
void Parametros::iniNivel(){
    //solicitar al usuario el nivel
    out.solicitarNivel();
    cin>>nivel;
    //Verificar que el nivel este en un rango aceptable
    if( ( nivel>0 ) && ( nivel<=4 ) ){
        //Esta dentro del rango
        out.printIntln("Nivel dentro del rango: ", nivel);
    }
    else{
        nivel = NIVEL_DEFAULT;
        //Rango invalido iniciar a un valor consistente        
        out.println("Nivel invalido, Nivel iniciado a: 1");
    }
}

/**
 * Iniciar el valor de las filas conrespecto al nivel o definido
 * por el usuario.
*/
void Parametros::iniRow(){
    switch (nivel){
        case NIVEL_1:
            row = ROW_NIV_1;
            break;
        case NIVEL_2:
        case NIVEL_3:
            row = ROW_NIV_2;
            break; 
        case NIVEL_4://El usuario tiene que ingresar el valor de row
            //out.print("Ingrese el numero de filas: ");
            cout<<"Ingrese el numero de filas ("<<ROW_MIN<<" - "<<ROW_MAX<<"): ";
            cin>>row;
            if( ( row>=ROW_MIN ) && ( row<=ROW_MAX ) ){
                //Esta dentro del rango
                out.printIntln("Filas dentro del rango: ", row);
            }
            else{
                //No se encuentra en el rango, Iniciar a un valor consistente
                row = ROW_MIN;
                out.printIntln("Filas invalidas, iniciadas a: ", ROW_MIN);
            }
            break;
        default:
            row = ROW_MIN;
            out.printIntln("Inconsistencia en row valor minimo", ROW_MIN);
            break;
    }
}

/**
 * Iniciar las columnas, si el usuario selecciona la opcion 4 entonces el debe de 
 * colocar el valor para las columnas.
*/
void Parametros::iniCol(){
    switch (nivel){
        case NIVEL_1:
            col = COL_NIV_1;
            break;
        case NIVEL_2:
            col = COL_NIV_2;
            break;
        case NIVEL_3:
            col = COL_NIV_3;
            break;
        case NIVEL_4:
            //Seleccion por el usuario
            cout<<"Ingrese las columnas ("<< COL_MIN <<" - "<< COL_MAX <<"): ";
            cin>>col;
            if(col>=COL_MIN && col<=COL_MAX){
                //Se encuentra en el rango
                out.printIntln("Columnas dentro del rango: ", col);
            }
            else{
                col = COL_MIN;
                out.printIntln("Fuera de rango iniciado a : ", COL_MIN);
            }
            break;
        default:
            col = COL_MIN;
            out.printIntln("Inconsistencia en col, valor minimo: ", COL_MIN);
            break;
    }
}

/**
 * Inciar las minas a un valor consistente, en caso de que el nivel sea 4
 * el usuario introduce el valor.
 * el calculo de las minas es con respecto a la cantidad de filas y columnas
 * se obtienen el total de cacillas y se obtiene el porcentaje de 22% para
 * el valor minimo de minas y el 33% para la cantidad mayor de minas.
*/
void Parametros::iniMinas(){
    switch(nivel){
        case NIVEL_1:
            minas = MIN_NIV_1;
            break;
        case NIVEL_2:
            minas = MIN_NIV_2;
            break;
        case NIVEL_3:
            minas = MIN_NIV_3;
            break;
        case NIVEL_4:
            //Obtener la cantidad minima de minas
            int minMinas;
            minMinas = ( (row * col) * MIN_MIN ) / 100;
            int maxMinas;
            maxMinas = ( (row * col) * MIN_MAX ) / 100;
            //Solicitar al usuario la cantidad de minas
            cout<<"Ingrese la cantidad de minas ("<<minMinas<<" - "<<maxMinas<<"): ";
            cin>>minas;
            if(minas>=minMinas && minas<=maxMinas){
                //Valor consistente para las minas
                out.printIntln("Minas validas: ", minas);
            }
            else{
                minas = minMinas;
                out.printIntln("Valor no valido, el valor asignado es: ", minas);
            }
            break;
        default:
            break;
    }
}

/**
 * Obtener la cantidad de filas
*/
int Parametros::getRow(){
    return row;
}

/**
 * Obtener la cantidad columnas
*/
int Parametros::getCol(){
    return col;
}

/**
 * Obtener la cantidad de minas
*/
int Parametros::getMinas(){
    return minas;
}

void Parametros::toString(){
    out.println("\n***|Los parametros del juego son|***");
    out.printIntln("    Nivel de juego: ", nivel);
    out.printIntln("  Numero de lineas: ", row);
    out.printIntln("Numero de columnas: ", col);
    out.printIntln(" Cantidad de Minas: ", minas);
}