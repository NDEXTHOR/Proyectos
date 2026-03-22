#include <iostream>
#include <list>

using namespace std;

class sudoku {
private:
	char matriz[9][9];// Un sudoku tiene 81 espacios
    int F_Inicio = 0;
    int C_Inicio = 0;

public:	
	sudoku();// La matriz se inicializa con espacios vacios
	sudoku(char mtzUsuario[9][9]);// La matriz se inicializa con una matriz definida

    static void ingresarSudoku(char sudoku[9][9]);
	void imprimir();
    
    // Reciben un numero y numero de fila, columna o region y verifican si ese numero falta en esa fila, columna o region
	bool verificarFila(char numAux, int noFila);
	bool verificarColumna(char numAux, int noColumna);
	bool verificarRegion(char numAux, int region);

    // Verifica si el sudoku esta bien resuelto
    bool verificarResolucion();
	
    friend class problemaSudoku;
};

sudoku::sudoku() {
	//Inicializar la matriz con espacios vacíos, cuando se imprime no se ve nada jaja
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			matriz[i][j] = ' ';
		}
	}
}
sudoku::sudoku(char mtzUsuario[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            matriz[i][j] = mtzUsuario[i][j];// Se iguala a la matriz definida
        }
    }
}

void sudoku::ingresarSudoku(char sdk[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
			cin >> sdk[i][j];
            if (sdk[i][j] == '0') {// Usamos el 0 como espacio vacio
				sdk[i][j] = ' ';
			}
        }
	}
}
void sudoku::imprimir() {  
    for (int i = 0; i < 9; i++) {  
        cout << "- - - - - - - - - - - - - - - - - - -" << endl;// Supongo que podria mejorar el formato, pero asi se ve bien
        for (int j = 0; j < 9; j++) {  
            if (j < 8) {
                cout << "| " << matriz[i][j] << " ";
            } else {
                cout << "| " << matriz[i][j] << " |";
            }
        }  
        cout << endl; 
    }  
    cout << "- - - - - - - - - - - - - - - - - - -" << endl;
}

bool sudoku::verificarFila(char numAux, int noFila) {
    for (int i = 0; i < 9; i++) {
        if (matriz[noFila][i] == numAux) {
            return true;
        }
    }
	return false;
}
bool sudoku::verificarColumna(char numAux, int noColumna) {
    for (int i = 0; i < 9; i++) {
        if (matriz[i][noColumna] == numAux) {
            return true;
        }
    }
    return false;
}
bool sudoku::verificarRegion(char numAux, int region) {
    // Queria usar un switch, pero no se por que no funciono
    if (region == 1) {
        F_Inicio = 0;
        C_Inicio = 0;
    } else if (region == 2) {
        F_Inicio = 0;
        C_Inicio = 3;
    } else if (region == 3) {
        F_Inicio = 0;
        C_Inicio = 6;
    } else if (region == 4) {
        F_Inicio = 3;
        C_Inicio = 0;
    } else if (region == 5) {
        F_Inicio = 3;
        C_Inicio = 3;
    } else if (region == 6) {
        F_Inicio = 3;
        C_Inicio = 6;
    } else if (region == 7) {
        F_Inicio = 6;
        C_Inicio = 0;
    } else if (region == 8) {
        F_Inicio = 6;
        C_Inicio = 3;
    } else if (region == 9) {
        F_Inicio = 6;
        C_Inicio = 6;
    }

    for (int i = F_Inicio; i < F_Inicio + 3; i++) {
        for (int j = C_Inicio; j < C_Inicio + 3; j++){
            if (matriz[i][j] == numAux) {
                return true;
            }
        }
    }
	return false;
}

bool sudoku::verificarResolucion() {
    // Verificar filas
    for (int fila = 0; fila < 9; fila++) {// Numero de fila
        for (char num = '1'; num <= '9'; num++) {// Numero a verificar  -  No sabia que se podrian iterar caracteres
            if (!verificarFila(num, fila)) {
                return false;
            }
        }
    }

    // Verificar columnas
    for (int col = 0; col < 9; col++) {// Numero de fila
        for (char num = '1'; num <= '9'; num++) {// Numero a verificar
            if (!verificarColumna(num, col)) {
                return false;
            }
        }
    }

    // Verificar regiones
    for (int region = 1; region <= 9; region++) {// Numero de fila
        for (char num = '1'; num <= '9'; num++) {// Numero a verificar
            if (!verificarRegion(num, region)) {
                return false;
            }
        }
    }

    return true; // Si pasa todas las verificaciones
}

class problemaSudoku {
private:
    sudoku inicial;
public:
    problemaSudoku(sudoku);
    void Amplitud();
    void Profundidad();
};

problemaSudoku::problemaSudoku(sudoku a) {
    inicial = a;
    cout << "Sudoku a resolver: " << endl;
    inicial.imprimir();
}
void problemaSudoku::Amplitud() {
    list<sudoku> lista;

    int iteracion = 1;
    bool resuelto = false;

    lista.push_front(inicial);

    while (!lista.empty() && !resuelto) {
        sudoku aux = lista.front();
        lista.pop_front();

        if (aux.verificarResolucion()) {
            cout << "Se encontro la resolucion con busqueda por amplitud en " << iteracion <<" iteraciones..." << endl;
            aux.imprimir();
            resuelto = true;
            break;
        }

        // Buscar la primera celda vacía
        bool celdaVaciaEncontrada = false;
        for (int i = 0; i < 9 && !celdaVaciaEncontrada; i++) {// No sabia que se podria hacer esto
            for (int j = 0; j < 9 && !celdaVaciaEncontrada; j++) {
                if (aux.matriz[i][j] == ' ') {
                    // Probar números del 1 al 9
                    for (char num = '1'; num <= '9'; num++) {
                        int region = ((i / 3) * 3) + (j / 3) + 1;// Calcula la region
                        if (!aux.verificarFila(num, i) &&
                            !aux.verificarColumna(num, j) &&
                            !aux.verificarRegion(num, region)) {
                            sudoku nuevo(aux.matriz);
                            nuevo.matriz[i][j] = num;
                            lista.push_back(nuevo);
                        }
                    }
                    celdaVaciaEncontrada = true; // Solo expandimos el primer vacío
                }
            }
        }

        iteracion++;
    }

    if (!resuelto) {
        cout << "No se encontró solución." << endl;
    }
}
void problemaSudoku::Profundidad() {
    list<sudoku> lista;

    int iteracion = 1;
    bool resuelto = false;

    lista.push_front(inicial);

    while (!lista.empty() && !resuelto) {
        sudoku aux = lista.back();
        lista.pop_back();

        if (aux.verificarResolucion()) {
            cout << "Se encontro la resolucion con busqueda por profundidad en " << iteracion << " iteraciones..." << endl;
            aux.imprimir();
            resuelto = true;
            break;
        }

        // Buscar la primera celda vacía
        bool celdaVaciaEncontrada = false;
        for (int i = 0; i < 9 && !celdaVaciaEncontrada; i++) {// No sabia que se podria hacer esto
            for (int j = 0; j < 9 && !celdaVaciaEncontrada; j++) {
                if (aux.matriz[i][j] == ' ') {
                    // Probar números del 1 al 9
                    for (char num = '1'; num <= '9'; num++) {
                        int region = ((i / 3) * 3) + (j / 3) + 1;// Calcula la region
                        if (!aux.verificarFila(num, i) &&
                            !aux.verificarColumna(num, j) &&
                            !aux.verificarRegion(num, region)) {
                            sudoku nuevo(aux.matriz);
                            nuevo.matriz[i][j] = num;
                            lista.push_back(nuevo);
                        }
                    }
                    celdaVaciaEncontrada = true; // Solo expandimos el primer vacío
                }
            }
        }

        iteracion++;
    }

    if (!resuelto) {
        cout << "No se encontró solución." << endl;
    }
}

int main(){

    cout << "Menu:\n (1) Ingresar sudoku\n (2) Usar sudoku de ejemplo\n Eliga una opcion:\n";
    int op;
    cin >> op;

    char matrizAux[9][9];
    sudoku a = sudoku();// Constructora sin argumentos(Solo espacios vacios)
    
    switch (op) {
        case 1:
            cout << "Ingresar sudoku: \n";
            sudoku::ingresarSudoku(matrizAux);
            a = sudoku(matrizAux);
        break;

        case 2:
            cout << "Matriz de ejemplo...: \n";
            // La llaves son por que no se pueden declarar variables en un case, pero con las 
            // llaves delimitamos el alcanze de esas variables y nos dejan usarlas
            {
                char matrizTemp[9][9] = {
                    { '8', ' ', ' ',   ' ', ' ', ' ',   ' ', ' ', ' ' },
                    { ' ', ' ', '3',   '6', ' ', ' ',   ' ', ' ', ' ' },
                    { ' ', '7', ' ',   ' ', '9', ' ',   '2', ' ', ' ' },
                    
                    { ' ', '5', ' ',   ' ', ' ', '7',   ' ', ' ', ' ' },
                    { ' ', ' ', ' ',   ' ', '4', '5',   '7', ' ', ' ' },
                    { ' ', ' ', ' ',   '1', ' ', ' ',   ' ', '3', ' ' },
                    
                    { ' ', ' ', '1',   ' ', ' ', ' ',   ' ', '6', '8' },
                    { ' ', ' ', '8',   '5', ' ', ' ',   ' ', '1', ' ' },
                    { ' ', '9', ' ',   ' ', ' ', ' ',   '4', ' ', ' ' }
                };
                a = sudoku(matrizTemp);
            }
            break;

        default:
            cout << "Opcion no valida!!!";
        break;
    }

    problemaSudoku A(a);

    A.Amplitud();

    A.Profundidad();
}