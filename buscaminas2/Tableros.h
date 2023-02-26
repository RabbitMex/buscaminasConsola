/**
 * Cabecera de clase para modelar los tableros.
 * Los tableros tienen mas cacillas es decir
 * esta rodeado de casillas por lo cual tendremos
 * mas filas y columnas.
*/

/* #define TABLERO_USU         1   //Referencia para tablero de usuario
#define TABLERO_MIN         2   //Referencia para tablero minado */

/* #define GAME_ON             0
#define GAME_WINNER         1
#define GAME_OVER           2 */

class Tableros
{
private:
    int row;
    int col;
    int minas;
    char **tableroUsuario;  //Tablero a mostrar al usuario
    char **tableroMinado;   //Tablero con minas y cantidad de minas
    void colocarMinas();    //Colocar las minas en el tableroMinado
    void colocarNumeros();  //Colocar numero de minas en las cacillas
public:
    Tableros(int r, int c, int m);
    ~Tableros();
    void iniTabUsuario();
    void iniTabMinado();
    void displayTablero(int tipo);
    void mostrarCoordenada(int x, int y);
    int evaluarJuego();
    const static int TABLERO_USU = 1;
    const static int TABLERO_MIN = 2;
    const static int GAME_ON = 0;
    const static int GAME_WINNER = 1;
    const static int GAME_OVER = 2;
};
