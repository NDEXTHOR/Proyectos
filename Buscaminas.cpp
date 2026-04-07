#include <bits/stdc++.h>

#define fo(i, n) for(i = 0; i < n; i++)

using namespace std;

class Tablero{
    private:
        char tabUsuario[20][20];
        bool tabPrograma[20][20];
        bool tabMarcadas[20][20];
        int minFil;
        int minCol;
    public:
    Tablero();
    void renderizar();
    void generarMinas();
    void revelarMinas();
    void calcularNumeros();
    void revelar(int fil, int col);
    int floodFill(int fil, int col);
    void marcarMina(int fil, int col);
    bool verificarMina(int fil, int col);
    int contarMinasAlrededor(int fil, int col);
};

Tablero::Tablero() {
    int i, j;
    fo(i, 20){
        fo(j, 20){
            tabUsuario[i][j] = '.';
            tabPrograma[i][j] = false;
            tabMarcadas[i][j] = false;
        }
    }
}
void Tablero::renderizar() {
    system("cls");
    int n, l, i, j;

    cout << "   ";
    fo (n, 20) cout << n << " "; // Numeros del 0 - 19 (columnas)
    cout << "\n   ";
    fo (l, 42) cout << "-"; // separador...
    cout << "\n";
    
    fo (i, 20) {
        (i < 10)? cout << i << "  | " : cout << i << " | "; // Numero de fila
        fo (j, 20) {
            if (tabMarcadas[i][j] && tabUsuario[i][j] == '.') cout << "F "; // Flag
            else cout << tabUsuario[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\".\" = celdas sin revelar...";
}
void Tablero::generarMinas() {
    int minasColocadas = 0;
    while (minasColocadas < 40) { // Hya que hacer esto 40 veces
        int fila = rand()%20;
        int columna = rand()%20;
        if (tabPrograma[fila][columna] == false){ // NO hay mina
            tabPrograma[fila][columna] = true; // Colocamos la mina
            minasColocadas++;
        }
    }
}
void Tablero::revelarMinas(){
    int i, j;
    fo (i, 20) {
        fo (j, 20) {
            if (tabPrograma[i][j] == true) // Si hay una mina
                tabUsuario[i][j] = 'M';
        }
    }
}
void Tablero::calcularNumeros() {
    int i, j; 
    fo (i, 20) {
        fo (j, 20) {
            if (tabPrograma[i][j]== false){
                int minasAlrededor = contarMinasAlrededor(i, j);
                tabUsuario[i][j] = '0' + minasAlrededor; // Se convierte a char, creo es por el ascii
            }
        }
    }
}
void Tablero::revelar(int fil, int col) {
    if (tabUsuario[fil][col] != '.')
        return; // Ya fue revelada
}
void Tablero::marcarMina(int fil, int col){
    tabMarcadas[fil][col] = !tabMarcadas[fil][col]; // Debemos poder marcar o desmarcar
}
int Tablero::floodFill(int fil, int col) {
    if (tabUsuario[fil][col] != '.') return 0; // Caso basem, ya fue revelada
    
    int minasAlrededor = contarMinasAlrededor(fil, col), cont = 1;
    
    if (minasAlrededor == 0) {
        tabUsuario[fil][col] = ' '; // Si no hay minas al rededor la celda esta vacia, pero igual podria ser 0
        // Llamasda recursivas para cada vecino
        for (int i = fil-1; i <= fil+1; i++) {
            for (int j = col-1; j <= col+1; j++) {
                if (i == fil && j == col) continue; // Se salta esta iteracion 
                if (i >= 0 && i <= 19 && j >= 0 && j <= 19) cont += floodFill(i, j); // Revisar rangos...
            } 
        }
    } else {
        tabUsuario[fil][col] = '0' + minasAlrededor;
    }
    return cont;
}
bool Tablero::verificarMina(int fil, int col) {
    return tabPrograma[fil][col]; // Hay o no una mina...
}
int Tablero::contarMinasAlrededor(int fil, int col) {
    int contador = 0;
    for (int i = fil-1; i <= fil+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            if (i == fil && j == col) continue; // Se salta esta iteracion 
            if (i >= 0 && i <= 19 && j >= 0 && j <= 19) { // Revisar rangos...
                if (tabPrograma[i][j] == true) // Si hay mina
                    contador++;
            }
        } 
    }    
    return contador;
}

int main() {
    srand(time(0));//Es para la semilla del rand()

    Tablero tab = Tablero(); // Generamos un tablero vacio
    
    tab.generarMinas();
    
    tab.renderizar();

    int celdasSinMina = 0;
    while (true) {
        int x, y, op;
        
        do {
            cout << "\n(1) Revelar \n(2) Marcar\n Selecione una opcion: ";
            cin >> op;
        } while (op != 1 && op != 2); // Solo con una opcion valida

        do {
            cout << "\nIngrese una celda (fila, columna): \n";
            cin >> x >> y;
        } while (x < 0 || x > 19 || y < 0 || y > 19); // Validamos que este en rango

        if (op == 1) {
            tab.revelar(x, y);

            if (!tab.verificarMina(x, y)){ // No hay una mina
                celdasSinMina += tab.floodFill(x, y);
            } else { // Le dio a una mina
                tab.revelarMinas();
                // Game over, luego pongo el ascci art
                cout << "\nPerdiste!!!!!\n";
                tab.renderizar();
                break;
            }
        } else if (op == 2) {
            tab.marcarMina(x, y); // Marcamos una mina
        }
        tab.renderizar();
        
        if (celdasSinMina == 360){ // Creo deben ser 40 minas entonces deberian 360 celdas sin nada, por que 20x20 = 400
            // Gano, pero no creo que sea la mejor forma de saberlo
            cout << "\nGanaste!!!!!\n";
            tab.renderizar();
            break;
        }
    }

    return 0;
}