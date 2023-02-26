/**
 * Cabecera para modelar los campos
 * Nivel: nivel del juego.
 * Filas: Cantidad de filas del tablero.
 * Columnas: Cantidad de columnas del tablero.
 * Minas: cantidad de minas asignadas al tablero.
*/
#ifndef PARAMETROS_H
#define PARAMETROS_H

#include "Mensajes.h"

#define NIVEL_DEFAULT           1   //Nivel por default
#define ROW_MIN                 3   //Cantidad de lineas como minimo
#define ROW_MAX                 20  //Cantidad de lineas como maximo
#define COL_MIN                 4   //Cantidad minima de columnas
#define COL_MAX                 35  //Cantidad maxima de columnas
//NIVELES
#define NIVEL_1                 1
#define NIVEL_2                 2
#define NIVEL_3                 3
#define NIVEL_4                 4
//Cantidad de filas segun el nivel
#define ROW_NIV_1               8
#define ROW_NIV_2               16
#define ROW_NIV_3               16
//Cantidad de columnas segun el nivel
#define COL_NIV_1               8
#define COL_NIV_2               16
#define COL_NIV_3               30
//Cantidad de minas segun el nivel
#define MIN_NIV_1               10
#define MIN_NIV_2               40
#define MIN_NIV_3               99
//Cantidad minima y maximas de minas en porcentaje
#define MIN_MIN                 22
#define MIN_MAX                 33
class Parametros
{
private:
    int nivel;
    int row;
    int col;
    int minas;
    Mensajes out;
public:
    Parametros(Mensajes mensajes);
    ~Parametros();
    void iniNivel();
    void iniRow();
    void iniCol();
    void iniMinas();
    int getRow();
    int getCol();
    int getMinas();
    void toString();
};

#endif