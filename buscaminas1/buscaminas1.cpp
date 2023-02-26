/**
 * Juego de buscaminas por consola
*/
#include <iostream>
#include <time.h>//Importante para usar srand(), rand()
#include <stdlib.h>

using namespace std;
//El tablero tendra dos casillas mas, esto hara que paresca
//que el tablero original esta rodeado por casillas
#define MAX     32

void mensaje();
int elegir_nivel();
int elegir_filas(int level);
int elegir_columnas(int level);
int elegir_minas(int level);
void InicializaTablero(int row, int col, char space[MAX][MAX]);
void ColocaMinas(int row, int col, char space[MAX][MAX], int minas);
void ColocaNumeros(int row, int col, char space[MAX][MAX]);
void ImprimeTablero(int jugadaFila, int jugadaColumna, char space[MAX][MAX], char space2[MAX][MAX], int row, int col);
int VerificarGanador(int row, int col, char space[MAX][MAX], int minas);
//utileria
void visualizarArreglo(int row, int col, char space[MAX][MAX]);

int main(){
    int level, row, col, min;
    int jugada_fila, jugada_columna;
    int situacion;//Determina si el jugador perdio, gano o que aun sigue en el juego
    //space muestra el tablero al usuario, valores sin descubrir
    //space2 contiene los valores originales.
    char space[MAX][MAX], space2[MAX][MAX];
    mensaje();
    level = elegir_nivel();
    row = elegir_filas(level);
    col = elegir_columnas(level);
    min = elegir_minas(level);
    InicializaTablero(row, col, space);
    ColocaMinas(row, col, space2, min);

    //visualizarArreglo(row, col, space2);//Solo para depuracion.
    
    ColocaNumeros(row, col, space2);

    //visualizarArreglo(row, col, space2);//Solo para depuracion.
    situacion = 0;
    //for(int i=0;i<3;i++){
    while(situacion==0){
        cout<<"Ingrese la fila y la columna de la casilla que desa boltear: ";
        cin>>jugada_fila>>jugada_columna;
        //Validar que las fila y la columna sean validas
        if((jugada_fila > 0) && (jugada_fila < (row + 1)) && (jugada_columna > 0) && (jugada_columna < (col + 1))){
            ImprimeTablero(jugada_fila, jugada_columna, space, space2, row, col);
            //visualizarArreglo(row, col, space);
            situacion = VerificarGanador(row, col, space, min);
            switch (situacion)
            {
                case 0://Continua el juego
                    break;
                case 1:
                    cout<<"Ha ganado el juego ;-): "<<situacion<<endl;
                    visualizarArreglo(row, col, space2);
                    break;
                case 2:
                    cout<<"Ha perdido el juego suerte para la proxima. "<<situacion<<endl;
                    visualizarArreglo(row, col, space2);
                    break;
                default:
                    cout<<"Situacion no definida: "<<situacion<<endl;
                    break;
            }
        }
        else{
            cout<<"Valores incorrectos para la fila o columna."<<endl;
        }
    }
    cout<<endl<<"Fin del programa"<<endl;
    return 0;
}

/**
 * Mensaje inicial de la aplicacion
*/
void mensaje(){
    cout<<"Bienvenido al juego Buscaminas ;-)"<<endl;
    cout<<"Los niveles son:"<<endl;
    cout<<"(1) Nivel principiante"<<endl;
    cout<<"(2) Nivel intermedio"<<endl;
    cout<<"(3) Nivel Experto"<<endl;
    cout<<"(4) Nivel personalizado"<<endl;
}

/**
 * Elegir el nivel de juego
*/
int elegir_nivel()
{
    int l;
    while(true){
        cout<<"Ingrese el nivel(1,2,3,4): ";
        cin>>l;
        if((l==1)||(l==2)||(l==3)||(l==4)){
            break;//Finaliza porque ya se cuenta con un valor correcto.
        }
        //Si el valor no es correcto entonces solicitamos nuevamente 
    }
    return l;
}

/**
 * Elegir las filas
*/
int elegir_filas(int level)
{
    int solicitarFilas();
    int fila;
    switch (level)
    {
        case 1:
            fila = 8;
            break;
        case 2:
        case 3:
            fila = 16;
            break;
        case 4:
            fila = solicitarFilas();
            break;
    default:
        break;
    }
    return fila;
}

/**
 * solicitar al usuario las filas y verificar el valor
 * filas, retornar la cantidad de filas.
*/
int solicitarFilas(){
    int f;
    cout<<"Ingrese el numero de filas(1 - 30): ";
    cin>>f;
    if((f>0)&&(f<=30)){
        cout<<"Parametro valido: "<<f<<endl;
    }
    else{
        f=30;
        cout<<"Valor no valid, ajuste filas = "<<f<<endl;
    }
    return f;
}

/**
 * Elegir la cantidad de columnas por el usuario.
*/
int elegir_columnas(int level)
{
    int solicitarColumnas();
    int col;
    switch (level)
    {
        case 1:
            col = 8;
            break;
        case 2:
            col = 16;
            break;
        case 3:
            col = 30;
            break;
        case 4:
            col = solicitarColumnas();
            break;
    default:
        break;
    }
    return col;
}

/**
 * Solicitar las columnas en el caso de que el juego sea personalizado.
*/
int solicitarColumnas(){
    int col;
    cout<<"Ingrese el numero de Columnas(1 - 30): ";
    cin>>col;
    if((col>0)&&(col<=30)){
        cout<<"Parametro valido: "<<col<<endl;
    }
    else{
        col=30;
        cout<<"Valor no valid, ajuste columnas = "<<col<<endl;
    }
    return col;
}

/**
 * Elegir las minas
*/
int elegir_minas(int level)
{
    int solicitarMinas();
    int min;
    switch (level)
    {
        case 1:
            min = 10;
            break;
        case 2:
            min = 40;
            break;
        case 3:
            min = 99;
            break;
        case 4:
            min = solicitarMinas();
            break;
    default:
        break;
    }
    return min;
}

/**
 * Solicita la cantidad de minas en el caso de que el juego
 * sea personalizado.
*/
int solicitarMinas(){
    int min;
    cout<<"Ingrese el numero de Minas(1 - 200): ";
    cin>>min;
    if((min>0)&&(min<=200)){
        cout<<"Parametro valido: "<<min<<endl;
    }
    else{
        min=200;
        cout<<"Valor no valid, ajuste de minas = "<<min<<endl;
    }
    return min;
}

/**
 * Inicializa el tablero con ceros 0
*/
void InicializaTablero(int row, int col, char space[MAX][MAX]){
    for(int i=0;i<row+2;i++){
        for(int j=0;j<col+2;j++){
            space[i][j] = '0';
        }
    }
    cout<<endl<<"El tablero ha sido creado, puede empezar a jugar: "<<endl;
    cout<<"El tablero actual es:"<<endl<<endl;
    for(int i=1;i<row+1;i++){
        for(int j=1;j<col+1;j++){
            cout<<space[i][j];
        }
        cout<<endl;
    }
}

/**
 * Colocar las minas en el tablero
*/
void ColocaMinas(int row, int col, char space[MAX][MAX], int minas){
    int pcol, pfila;//pfila aleatoria, pcol aleatoria
    srand(time(NULL));//Iniciar para nuemeros aleatorios

    for(int i=0;i<row+2;i++){
        for(int j=0;j<col+2;j++){
            space[i][j] = '0';
        }
    }

    while(minas>0){
        pcol = 1 + rand()%row;
        pfila = 1 + rand()%col;
        if(space[pcol][pfila]=='0'){
            //Es posible colocar una mina
            space[pcol][pfila] = 'M';
            minas--;
        }
    }
    
}

/**
 * Visualiza el tablero en consola.
*/
void visualizarArreglo(int row, int col, char space[MAX][MAX]){
    cout<<endl<<"Visualizar el arreglo: "<<endl<<endl;
    for(int i=1;i<row+1;i++){
        for(int j=1;j<col+1;j++){
            cout<<space[i][j];
        }
        cout<<endl;
    }
}

/**
 * Coloca los numero de minas, si la posicion tiene un 0 
 * entoncescontar cuantas minas tiene al rededor.
*/
void ColocaNumeros(int row, int col, char space[MAX][MAX]){
    int minas;
    for(int i=1;i<row+1;i++){
        for(int j=1;j<col+1;j++){
            if(space[i][j] == '0'){
                minas = 0;
                //Contar las minas que tiene en rededor
                if(space[i-1][j-1]=='M')minas++;
                if(space[i-1][j]=='M')minas++;
                if(space[i-1][j+1]=='M')minas++;
                if(space[i][j-1]=='M')minas++;
                if(space[i][j+1]=='M')minas++;
                if(space[i+1][j-1]=='M')minas++;
                if(space[i+1][j]=='M')minas++;
                if(space[i+1][j+1]=='M')minas++;
                //Si la cantidad es cero, es decri no hay minas
                //Colocar un espacio vacio o caracter de espacio
                if(minas==0){
                    space[i][j] = ' ';
                }
                else{
                    //space[i][j] = (minas + 48);
                    //Esto convierte el entero en su equivalente a char
                    space[i][j] = minas + '0';
                }
            }
            
        }
    }
}

/**
 * Realiza la jugada del usuario y descubres la casilla seleccionada
*/
void ImprimeTablero(int jugadaFila, int jugadaColumna, char space[MAX][MAX], char space2[MAX][MAX], int row, int col){
    //Copiar la casilla seleccionada y mostrar al usuario
    space[jugadaFila][jugadaColumna] = space2[jugadaFila][jugadaColumna];
    //Imprimir el arreglo con su nuevo valor
    for(int i=1;i<row+1;i++){
        for(int j=1;j<col+1;j++){
            cout<<space[i][j];
        }
        cout<<endl;
    }
}

int VerificarGanador(int row, int col, char space[MAX][MAX], int minas)
{
    int situacion = 0;
    int casillas_faltan = 0, cantidad_minas = 0;
    for (int i = 1; i < row + 1; i++)
    {
        for (int j = 1; j < col + 1; j++)
        {
            if(space[i][j] == 'M'){
                cantidad_minas++;
                //cout<<"Se encontro mina en: "<<i<<", "<<j<<", cantidad de minas: "<<cantidad_minas<<endl;
            }
            else if(space[i][j] == '0')casillas_faltan++;
        }
        
    }

    //Se ha volteado almenos una mina, el jugador va a perder
    if(cantidad_minas!=0) situacion = 2;//el jugador va a perder
    //Si la cantidad de casillas que faltan por voltear es igual
    //Al numero de minas, entonces el jugador ha ganado porque 
    //Ya no faltan mas casillas por voltear, porque tienen mina
    else if(casillas_faltan == minas) situacion = 1;
    //else if(casillas_faltan == cantidad_minas) situacion = 1;

    return situacion;
}

void cambioRealizado2(){
    cout<<"Cambio realizado en local 1.0";
}