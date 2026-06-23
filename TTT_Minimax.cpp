#include <bits/stdc++.h>

#define fo(i, n) for(i = 0; i < n; i++) 

using namespace std;

class TicTacToe{
    private:
        char tablero[3][3];
    
    public:
        TicTacToe();
        void Imprimir();
        bool movValido(int f, int c);
        void hacerMov(int f, int c, string tirador);
        void deshacerMov(int f, int c);
        char verGanador();
        bool esEmpate();

        // Algoritmo Minimax

        int minimax(int profundidad, bool esMaximizante);
        pair<int, int> mejorMov();
};

TicTacToe::TicTacToe(){
    int i, j;
    fo(i, 3) {
        fo(j, 3) {
            tablero[i][j] = ' ';
        }
    }
}
void TicTacToe::Imprimir(){
    int i, j;
    cout << "\n";
    fo(i, 3) {
        fo(j, 3) {
            cout << " " << tablero[i][j];
            if(j < 2) cout << " |";
        }
        cout << " \n";
        if (i < 2) cout << "-----------\n";
    }
    cout << "\n";
}
bool TicTacToe::movValido(int f, int c){
    return f >= 0 && f < 3 && c >= 0 && c < 3 && tablero[f][c] == ' ';
}
void TicTacToe::hacerMov(int f, int c, string tirador){
    if(movValido(f, c)){
        (tirador == "Jugador")? tablero[f][c] = 'X' : tablero[f][c] = 'O';
    } else {
        cout << "Fuera de rango\n";
    }
}
void TicTacToe::deshacerMov(int f, int c){
    tablero[f][c] = ' ';
}
char TicTacToe::verGanador(){
    int i;
    bool columna, fila, diagonal = false;
    fo(i, 3) {
        columna = (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != ' ');
        if (columna) return tablero[i][0];
    }
    fo(i, 3) {
        fila = (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != ' ');
        if (fila) return tablero[0][i];
    }
    // Diagonal si es directa, no se ocupan ciclos
    diagonal = (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != ' ') || 
                (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != ' ');

    if (diagonal) return tablero[1][1];// Retorna 'X' o 'O'
    return ' ';// Sin ganador
}
bool TicTacToe::esEmpate(){
    int i, j;
    fo(i, 3) {
        fo(j, 3) {
            if (tablero[i][j] == ' ') return false;
            // return !(tablero[i][j] == ' ');
        }
    }
    return true;// Es empate, no hay celdas vacias
}

// Algoritmo Minimax

int TicTacToe::minimax(int profundidad, bool esMaximizante){
    char ganador = verGanador();
    if (ganador == 'O') return 10 - profundidad;
    if (ganador == 'X') return -10 + profundidad;
    if (esEmpate()) return 0;

    if (esMaximizante) {
        int mejorValor = INT_MIN, i, j;

        fo(i, 3) {
            fo(j, 3) {
                if (tablero[i][j] == ' ') {
                    hacerMov(i, j, "IA");
                    int varAux = minimax(profundidad + 1, false);
                    deshacerMov(i, j);
                    mejorValor = max(mejorValor, varAux);
                }
            }
        }
        return mejorValor;
    } else {
        int mejorValor = INT_MAX, i, j;
        fo(i, 3) {
            fo(j, 3) {
                if (tablero[i][j] == ' ') {
                    hacerMov(i, j, "Jugador");
                    int varAux = minimax(profundidad + 1, true);
                    deshacerMov(i, j);
                    mejorValor = min(mejorValor, varAux);
                }
            }
        }
        return mejorValor;
    }
}
pair<int, int> TicTacToe::mejorMov(){
    int i, j, mejorValor = INT_MIN;
    pair<int, int> mejorCelda;

    fo(i, 3) {
        fo(j, 3) {
            if (tablero[i][j] == ' ') {
                hacerMov(i, j, "IA");
                int varAux = minimax(0, false);
                deshacerMov(i, j);
                if (varAux > mejorValor) {
                    mejorValor = varAux;
                    mejorCelda = {i, j};
                }
            }
        }
    }
    return mejorCelda;
}

int main(){
    TicTacToe Tablero = TicTacToe();

    while (true) {
        int fil, col;

        Tablero.Imprimir();
        if (Tablero.verGanador() != ' ' || Tablero.esEmpate()) break;
        
        do {
            cout << "Ingrese fila y columna (0-2): ";
            cin >> fil >> col;
            cin.clear();
            cin.ignore(10000, '\n');
            if (fil < 0 || fil > 2 || col < 0 || col > 2) {
                cout << "Fila y/o columna invalida!!\n";
            } else if (!Tablero.movValido(fil, col)) {
                cout << "Celda ocupada!!\n";
            } else {
                break;
            }
        } while (true);
        
        Tablero.hacerMov(fil, col, "Jugador");

        if (Tablero.verGanador() != ' ' || Tablero.esEmpate()) break;

        pair<int, int> movIA = Tablero.mejorMov();
        Tablero.hacerMov(movIA.first, movIA.second, "IA");
        cout << "IA juega en (" << movIA.first << ", " << movIA.second << ")\n";

        if (Tablero.verGanador() != ' ' || Tablero.esEmpate()) break;
    }
    
    Tablero.Imprimir();

    char ganador = Tablero.verGanador();

    if (ganador == 'X') {
        cout << "\n¡¡¡GANASTE!!!\n";
    } else if (ganador == 'O') {
        cout << "\nLa IA GANO. Mejor suerte la próxima vez.\n";
    } else {
        cout << "\n¡EMPATE!\n";
    }
    return 0;
}