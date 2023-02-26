/**
 * Juego de buscaminas por consola
*/
#include <iostream>
#include <time.h>//Importante para usar srand(), rand()
#include <stdlib.h>
using namespace std;

//Clases del proyecto
#include "Mensajes.h"       //Se encarga de visulizar los mensajes por consola
#include "Parametros.h"     //Pide y resguarda los parametros del programa
#include "Tableros.h"       //Gestiona los tableros y su informacion.

Mensajes out;       //Objeto out para poer desplegar los mensajes

int main(){
    int jugada_fila, jugada_columna;
    int estado;
    //Desplegar menu principal y obtener los parametros.
    out.menuPrincipal();
    //Pedor los parametros y desplegar los mensajes correspondientes.
    Parametros param(out);
    param.iniNivel();
    param.iniRow();
    param.iniCol();
    param.iniMinas();
    param.toString();

    //Iniciar los tableros
    Tableros tablero(param.getRow(), param.getCol(), param.getMinas());
    tablero.iniTabUsuario();
    tablero.iniTabMinado();
    out.disIniTablero();
    tablero.displayTablero(Tableros::TABLERO_USU);//Imprimir el tablero del usuario.
    //tablero.displayTablero(Tableros::TABLERO_MIN);//Imprimir el tablero minado.

    estado = 0;
    while(estado==0){
        out.pedirCoordenada();
        cin>>jugada_fila>>jugada_columna;
        //Validar que las fila y la columna sean validas
        if(    (jugada_fila > 0) 
            && (jugada_fila < (param.getRow() + 1)) 
            && (jugada_columna > 0) 
            && (jugada_columna < (param.getCol() + 1)) ){
            tablero.mostrarCoordenada(jugada_fila, jugada_columna);//Mostrar la coordenada seleccionada por el usuario
            estado = tablero.evaluarJuego();
            
            switch (estado)
            {
                case Tableros::GAME_ON://Continua el juego
                    break;
                case Tableros::GAME_WINNER:
                    out.printIntln("\nHa ganado el juego ;-): ", estado);
                    tablero.displayTablero(tablero.TABLERO_MIN);
                    break;
                case Tableros::GAME_OVER:
                    out.printIntln("\nHa perdido el juego suerte para la proxima: ", estado);
                    tablero.displayTablero(tablero.TABLERO_MIN);
                    break;
                default:
                    out.printIntln("\nHa perdido el juego suerte para la proxima: ", estado);
                    break;
            }
        }
        else{
            out.println("Valores incorrectos para la fila o columna.");
        }
    }
    cout<<endl<<"Fin del programa"<<endl;
    return 0;
}