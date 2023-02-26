/**
 * Cabecera de la clase para el objeto Mensajes, en el cual se definen
 * los mensajes del programa, tales como el menu de inicio y los mensajes
 * finales del juego.
*/
#ifndef MENSAJES_H
#define MENSAJES_H

#include <string>
using std::string;
//using namespace std;

class Mensajes
{
public:
    Mensajes(/* args */);
    ~Mensajes();
    void menuPrincipal();
    void solicitarNivel();
    void print(string mensaje);
    void println(string mensaje);
    void printIntln(string mensaje, int entero);
    void disIniTablero();
    void pedirCoordenada();
};

#endif