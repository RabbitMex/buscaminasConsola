/**
 * Tableros.cpp
 * Implementacion de la clase crear de forma dinamica los espacios para
 * los tableros, gestinar la inicializacion de minas y el conteo de las
 * mismas, para poder generar el tablero oculto o minado y el tablero
 * que se le muestra al usuario.
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#include "Tableros.h"

/**
 * El contructor inicializa la cantidad de filas, columnas, minas y 
 * el especio en memoria para los tableros.
*/
Tableros::Tableros(int r, int c, int m){
    //Iniciar los parametros de los tableros
    row = r;
    col = c;
    minas = m;
    //Nota: recuerde que el tablero esta rodeado de cacillas
    //Esto facilita la gestion del conteo de minas
    //Iniciar en memoria el tablero para el usuario
    tableroUsuario  = new char*[row+2];//Iniciar las filas
    //Iniciar en memoria el tablero oculto o minado
    tableroMinado = new char*[row+2];//Inicar las filas

    //Iniciar las columnas
    for (int i = 0; i < (row+2); i++)
    {
        tableroUsuario[i] = new char[col+2];
        tableroMinado[i] = new char[col+2];
    }
    
}

Tableros::~Tableros(){}

/**
 * Iniciar el tablero de usuario, incluyendo las celdas externas
 * con valor de '0'
*/
void Tableros::iniTabUsuario(){
    for (int i = 0; i < row+2; i++){
        for (int j = 0; j < col+2; j++){
            tableroUsuario[i][j] = '0';
        }   
    }
}

/**
 * Iniciar el tablero minado, esto consiste en realizar lo siguiento
 * Colocar las minas
 * Colocar numero de minas
*/
void Tableros::iniTabMinado(){
    colocarMinas();     //Colocar las minas en el tablero minado
    colocarNumeros();   //Colocar la cantidad de minas en las casillas.
}

/**
 * Colocar las minas en el tablero minado
*/
void Tableros::colocarMinas(){
    int cantidadMinas = minas;
    int columna, fila;
    srand(time(NULL));//Iniciar los numero aleatorios
    //Iniciar el tablero minado a '0'
    for (int i = 0; i < row+2; i++){
        for (int j = 0; j < col+2; j++){
            tableroMinado[i][j] = '0';
        }
    }
    while (cantidadMinas>0){
        fila = 1 + rand()%row;
        columna = 1 + rand()%col;
        if(tableroMinado[fila][columna] == '0'){
            //Es posible colocar una mina
            tableroMinado[fila][columna] = 'M';
            //Decrementar valor de la mina
            cantidadMinas--;
        }
    }
    
    //displayTablero(TABLERO_MIN);
}

/**
 * Colocar la cantidad de minas 
*/
void Tableros::colocarNumeros(){
    int minas;
    for (int i = 1; i < row+1; i++){
        for (int j = 1; j < col+1; j++){
            minas = 0;
            if(tableroMinado[i][j]=='0'){
                //Contar las mians que estan al rededor de esta celda
                //Las tres del lado izquierdo
                if(tableroMinado[i-1][j-1]=='M')minas++;
                if(tableroMinado[i][j-1]=='M')minas++;
                if(tableroMinado[i+1][j-1]=='M')minas++;
                //Las dos, una de arriba y otra abajo
                if(tableroMinado[i-1][j]=='M')minas++;
                if(tableroMinado[i+1][j]=='M')minas++;
                //tres, del lado derechao
                if(tableroMinado[i-1][j+1]=='M')minas++;
                if(tableroMinado[i][j+1]=='M')minas++;
                if(tableroMinado[i+1][j+1]=='M')minas++;
                if(minas==0){
                    //No hay minas alrededor de esta casilla por lo cual
                    //Colcoar un espacio
                    tableroMinado[i][j]='|';
                }
                else{
                    //Colcor la cantidad de minas que hay
                    tableroMinado[i][j]= minas + 48;
                }
            }
        }//Fin del for interno
    }//Fin del for principal
}

/**
 * Desplegar el tablero seleccionado en la consola
*/
void Tableros::displayTablero(int tipo){
    char **tablero;
    switch (tipo){
    //case ::TABLERO_USU:
    case TABLERO_USU:
        tablero = tableroUsuario;
        break;
    //case this.TABLERO_MIN:
    case TABLERO_MIN:
        tablero = tableroMinado;
        break;
    default:
        break;
    }
    //desplegar en la consola
    cout<<endl;
    //Desplegar etiquetas en la parte de arriba
    cout<<"   ";
    for (int i = 1; i < col+1; i++){
        cout<<(i%10);
    }
    cout<<endl<<"   ";
    for (int i = 1; i < col+1; i++){
        cout<<"!";
    }
    cout<<endl;

    for (int i = 1; i < row+1; i++){
        if(i<10)cout<<" ";
        cout<<i<<">";
        for (int j = 1; j < col+1; j++){
            cout<<tablero[i][j];
        }
        cout<<"<"<<i;
        cout<<endl;
    }
    //Desplegar etiquetas en la parte de abajo
    cout<<"   ";
    for (int i = 1; i < col+1; i++){
        cout<<"^";
    }
    cout<<endl<<"   ";
    for (int i = 1; i < col+1; i++){
        cout<<(i%10);
    }
    cout<<endl;
}

/**
 * Mostrar la coordenada seleccionada por el usuario
*/
void Tableros::mostrarCoordenada(int x, int y){
    //Pasa la seleccion del usuario del tablero minado a el tablero de usuario
    tableroUsuario[x][y] = tableroMinado[x][y];
    displayTablero(TABLERO_USU);
}

/**
 * Evaluar el estado del juego, si el usuario ha descubierto alguna mina
 * entonces ha perdido el juego, si ha descubierto todas las casillas pero 
 * ninguna mina entonces ha ganado, si no ha descubierto ninguna mina 
 * y aun faltan casillas el juego continua.
 * 0: el juego continua
 * 1: El jugador gana
 * 2: El jugador perdio.
*/
int Tableros::evaluarJuego(){
    int cantidadMinas = 0;//cantidad de minas descubiertas
    int cantidadCelFal = 0;//Cantidad de casillas que faltan por voltear
    int resultado;
    //ver cada casilla del tablero de usuario
    for (int i = 1; i < row+1; i++){
        for (int j = 1; j < col+1; j++){
            //Verificar y contar las minas descubiertas
            if(tableroUsuario[i][j] == 'M'){
                //Se ha encontrado una mina
                cantidadMinas++;
            }
            //Contar la cantidad de ceros en el tablero
            if(tableroUsuario[i][j] == '0'){
                cantidadCelFal++;
            }
        }
    }//Fin del primer for
    //Ahora tenemos que evaluar si hay minas 
    if(cantidadMinas>0){
        //Se detecto una mina. el usuario perdio el juego
        resultado = GAME_OVER;
    }
    else if(cantidadCelFal==minas){
        //La cantidad de fichas o casillas que faltan por voltear 
        //Es igual a la cantidad de minas, eso significa que 
        //el usuario gano el juego.
        resultado = GAME_WINNER;
    }
    else{
        //El juego continua, no se han descubierto minas
        //y faltan fichas o casillas por voltear.
        resultado = GAME_ON;
    }
    return resultado;
}
