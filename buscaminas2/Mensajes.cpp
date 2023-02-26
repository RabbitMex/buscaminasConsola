/**
 * Mensajes.cpp definiciones de la puesta en marcha para la clase Mensajes
 * Su funcion es desplegar los mensajes tales como el menu principal
 * y mensajes al finalizar el juego.
*/
#include <iostream>
using namespace std;
#include "Mensajes.h"

/**
 * Constructor de la clase Mensajes
*/
Mensajes::Mensajes(){
    //Constructor vacio
}

/**
 * Desctructor de la clase mensajes
*/
Mensajes::~Mensajes(){

}

/**
 * Desplegar el menu de inicio para el usuario
 * Visualizar las opeciones de nivel de juego.
*/
void Mensajes::menuPrincipal(){
    println("\n**********************************");
    println("Bienvenido al juego Buscaminas ;-)");
    println("Los niveles son:");
    println("(1) Nivel principiante");
    println("(2) Nivel intermedio");
    println("(3) Nivel Experto");
    println("(4) Nivel personalizado");
    println("");
}

/*Se considera que no es factible generar un mensaje para cada evento o 
solicitud, en cada operacion se deben de solicitar los mensajes, de esta
forma se enlazan a la tarea, de lo contrario si se definen en Mensajes 
tenemos que saber a que lugar se refiere.
*/

/**
 * Mensaje para solicitar nivel al usuario
*/
void Mensajes::solicitarNivel(){
    print("Ingrese el nivel de juego (1, 2, 3, 4): ");
}

/**
 * 
*/
void Mensajes::print(string cadena){
    cout<<cadena;
}

/**
 * Desplegar un mensaje con salto de linea
*/
void Mensajes::println(string cadena){
    cout<<cadena<<endl;
}

void Mensajes::printIntln(string mensaje, int entero){
    cout<<mensaje<<entero<<endl;
}

/**
 * Desplegar el mensaje de inicio para el tablero
*/
void Mensajes::disIniTablero(){
    println("\nEl tablero ha sido creado, puede empezar a jugar: ");
    println("El tablero actual es:");
}

/**
 * Solicitar mensajes para las coordenadas
*/
void Mensajes::pedirCoordenada(){
    print("\nIngrese la fila y la columna de la casilla que desa boltear: ");
}