#include <bits/stdc++.h>

#define fo(i, n) for(i = 0; i < n; i++)

using namespace std;

class GeneradorSudoku {
private:
	char sudoku[9][9];
    int F_Inicio;
    int C_Inicio;

public:	
	GeneradorSudoku();// La matriz se inicializa con espacios vacios

	void imprimir();
    void imprimirSinFormato();
    
    bool esValido(int fila, int col, char num);
    bool llenarTablero();
    void generarPuzzle(int dificultad);

    // Retornan verdadero si el numero esta en la fila, columna o region
    bool verificarFila(char num, int noFila);
	bool verificarColumna(char num, int noColumna);
	bool verificarRegion(char num, int region);

    bool contarSoluciones(int& contador);
    bool tieneSolucionUnica();
    void limpiarMatriz();
};

GeneradorSudoku::GeneradorSudoku() {
	//Inicializar la matriz con espacios vacíos
    F_Inicio = 0;
    C_Inicio = 0;
	int i, j;
    fo(i, 9)
		fo(j, 9)
			sudoku[i][j] = ' ';
}

void GeneradorSudoku::imprimir() {  
    int i, j;
    fo(i, 9) {  
        cout << "- - - - - - - - - - - - - - - - - - -\n";
        fo(j, 9) {  
            if (j < 8) {
                cout << "| " << sudoku[i][j] << " ";
            } else {
                cout << "| " << sudoku[i][j] << " |";
            }
        }  
        cout << "\n"; 
    }  
    cout << "- - - - - - - - - - - - - - - - - - -\n";
}
void GeneradorSudoku::imprimirSinFormato() {  
    int i, j;
    fo(i, 9) {  
        fo(j, 9) {  
            if(sudoku[i][j] == ' '){
                cout << "0";
            } else {
                cout << sudoku[i][j];
            }
        }  
        cout << "\n"; 
    }  
}

bool GeneradorSudoku::esValido(int fil, int col, char num){
    int region = (fil/3)*3 + (col/3) + 1;
    return (!verificarFila(num, fil) && !verificarColumna(num, col) && !verificarRegion(num, region));// No esta en la fila, columna ni en la region

}
bool GeneradorSudoku::llenarTablero(){
    int i, j;
    fo(i, 9){
        fo(j, 9){
            if(sudoku[i][j] == ' '){
                for(char num = '1'; num <= '9'; num++) {
                    // Esta un poco dificil para mi esta parte jaja
                    if(esValido(i, j, num)) {
                        sudoku[i][j] = num;// Coloca
                        if(llenarTablero())// Intenta llenar recursivamente
                            return true;// Si funciona, listo
                        sudoku[i][j] = ' ';// Si no funciona, deshaz y prueba siguiente
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void GeneradorSudoku::generarPuzzle(int dificultad){
    // Llenamos el tablero/sudoku
    llenarTablero();
    // Dependiendo el nivel de dificultad habra mas o menos celdas vacias
    int celdasAVaciar = (dificultad == 1) ? 30 :// Facil
                    (dificultad == 2) ? 40 :// Medio
                    50;// Dificil
    //Vaciamos las celdas dependiendo del nivel de dificultad
    bool vaciadas[9][9];
    int i, j;// Inicializamos a falso la matriz
        fo(i, 9)
            fo(j, 9)
                vaciadas[i][j] = false;
    int cont = 0;
    while(cont < celdasAVaciar){
        int fil = rand() % 9;// Número aleatorio entre 0-8
        int col = rand() % 9;// x2
        if(!vaciadas[fil][col]){
            sudoku[fil][col] = ' ';
            vaciadas[fil][col] = true;
            cont++;
        }
    }

}

bool GeneradorSudoku::verificarFila(char numAux, int noFila) {
    int i; 
    fo(i, 9)
        if (sudoku[noFila][i] == numAux) return true;
    return false;
}
bool GeneradorSudoku::verificarColumna(char numAux, int noColumna) {
    int i; 
    fo(i, 9)
        if (sudoku[i][noColumna] == numAux) return true;
    return false;
}
bool GeneradorSudoku::verificarRegion(char numAux, int region) {
    F_Inicio = ((region - 1) / 3) * 3;
    C_Inicio = ((region - 1) % 3) * 3;

    for (int i = F_Inicio; i < F_Inicio + 3; i++) {
        for (int j = C_Inicio; j < C_Inicio + 3; j++){
            if (sudoku[i][j] == numAux)
                return true;
        }
    }
	return false;
}

bool GeneradorSudoku::contarSoluciones(int& contador){
    int i, j;
    fo(i, 9){
        fo(j, 9){
            if(sudoku[i][j] == ' '){
                for(char num = '1'; num <= '9'; num++) {
                    // Esta un poco dificil para mi esta parte, otra vez jaja
                    if(esValido(i, j, num)) {
                        sudoku[i][j] = num;
                        contarSoluciones(contador);
                        if(contador > 1) return false;// Si hay mas de 1 directamente no es de unica solucion
                        sudoku[i][j] = ' ';
                    }
                }
                contador++;
                return false;
            }
        }
    }
    return false;
}
bool GeneradorSudoku::tieneSolucionUnica(){
    char copia[9][9];
    int i, j;
    fo(i, 9)
		fo(j, 9)
			copia[i][j] = sudoku[i][j];
    
    int cont = 0; 
    contarSoluciones(cont);

    bool res = (cont == 1);

    fo(i, 9)
		fo(j, 9)
			sudoku[i][j] = copia[i][j];
    
    return res;
}
void GeneradorSudoku::limpiarMatriz(){
    int i, j;
    fo(i, 9)
        fo(j, 9)
            sudoku[i][j] = ' ';
}

int main(){
    srand(time(0));// Es la semilla para el rand

    GeneradorSudoku generador;

    generador.generarPuzzle(3);
    
    generador.imprimir();
    // Esta funcion es para que me sirva para la entrada de "Sudoku.cpp"
    //generador.imprimirSinFormato();
    
    if(generador.tieneSolucionUnica()){
        cout << "Sudoku con solucion unica!\n";
    } else {
        cout << "Sudoku sin solucion unica\n";
    }
    return 0;
}