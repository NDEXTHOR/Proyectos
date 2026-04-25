#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

#define VecPar vector<pair<int, int>>
#define fo(i, n) for (i = 0; i < n; i++)

map<char, string> piezas = {{'I', "🟦"}, {'O', "🟧"}, {'T', "🟪"}, {'S', "🟩"},
                            {'Z', "🟥"}, {'J', "🟫"}, {'L', "🟨"}};

class Pieza {
  private:
    VecPar coordenadas; // Guardamos las coords de cada parte de una pieza
    int coordX, coordY; // Coordenadas de la pieza en el tablero
    int rotacion;       // Rotacion en grados
    char tipo;          // I, O, T, S, Z, J, L

  public:
    Pieza(VecPar coords, int x, int y, int rot, char tip);
    VecPar obtenerCoordenadas();
    char obtenerTipo();
    // Funciones para mover la pieza(derecha, izquierda y abajo)
    void rotar(); // Va a estar en chino jaja
    void moverIzquierda();
    void moverDerecha();
    void moverAbajo();
};

Pieza::Pieza(VecPar coords, int x, int y, int rot, char tip) {
    coordenadas = coords;
    coordX = x;
    coordY = y;
    rotacion = rot;
    tipo = tip;
}
VecPar Pieza::obtenerCoordenadas() {
    VecPar coordsCompletas;
    for (auto coord : coordenadas) {
        coordsCompletas.push_back({coord.first + coordX, coord.second + coordY});
        // Es para que de la coords de la pieza en el tablero, no solo las propias de la pieza
    }
    return coordsCompletas;
}
char Pieza::obtenerTipo() {
    return tipo;
}
void Pieza::rotar() {
    // En pocas palabras, va a estar en chino jaja          -           23/04/26 9:00 PM aprox jaja
}
void Pieza::moverIzquierda() {
    coordY--;
}
void Pieza::moverDerecha() {
    coordY++;
}
void Pieza::moverAbajo() {
    coordX++;
}

class Tablero {
  private:
    string tablero[20][10];                               // Es string para guardar emojis
    vector<pair<pair<int, int>, string>> piezasEnTablero; // Coordenadas + emoji

  public:
    Tablero(); // Hacemos el tablero vacio
    void colocarPieza(Pieza pieza);
    void fijarPiezaEnTablero(Pieza pza);
    void mostrarPiezasFijas();
    void mostrarTablero();          // Tablero con bordes
    void reiniciarTablero();        // Vaciamos el tablero
    bool estaOcupado(int x, int y); // Revisa si ya hay una pieza ahi
};

Tablero::Tablero() {
    int i = 0, j = 0;
    fo(i, 20) {
        fo(j, 10) {
            tablero[i][j] = "  "; // Tablero vacio
        }
    }
}
void Tablero::mostrarTablero() {
    int i = 0, j = 0;
    fo(i, 20) {
        fo(j, 10) {
            if (j == 0) {
                cout << "⬛" << tablero[i][j];
            } else if (j == 9) {
                cout << tablero[i][j] << "⬛";
            } else {
                cout << tablero[i][j];
            }
        }
        cout << endl;
    }
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛";
}
void Tablero::fijarPiezaEnTablero(Pieza pieza) {
    VecPar coords = pieza.obtenerCoordenadas();
    for (auto coord : coords) {
        piezasEnTablero.push_back(
            {coord, piezas[pieza.obtenerTipo()]}); // Obtenemos el emoji correspodiente jaja
    }
}
void Tablero::mostrarPiezasFijas() {
    for (auto pieza : piezasEnTablero) {
        int x = pieza.first.first;
        int y = pieza.first.second;
        if (x >= 0 && x < 20 && y >= 0 && y < 10) {
            tablero[x][y] = pieza.second;
        }
    }
}
void Tablero::reiniciarTablero() {
    int i = 0, j = 0;
    fo(i, 20) {
        fo(j, 10) {
            tablero[i][j] = "  ";
        }
    }
}
void Tablero::colocarPieza(Pieza pieza) {
    VecPar coordsPieza = pieza.obtenerCoordenadas();
    for (auto coord : coordsPieza) {
        int x = coord.first;
        int y = coord.second;
        if (x >= 0 && x < 20 && y >= 0 && y < 10) {
            // Tuvo que ser asi por que "tipo" es privada
            tablero[x][y] = piezas[pieza.obtenerTipo()];
        }
    }
}
bool Tablero::estaOcupado(int x, int y) {
    for (auto pieza : piezasEnTablero) {
        if (pieza.first.first == x && pieza.first.second == y) {
            return true;
        }
    }
    return false;
}
// Funciones para el funcionamiento del juego
Pieza generarPieza() {
    int tipo = rand() % 7; // Número del 0 al 6
    switch (tipo) {
        // Me las dio copilot
    case 0: // I
        return Pieza({{0, 0}, {0, 1}, {0, 2}, {0, 3}}, 0, 4, 0, 'I');
    case 1: // O
        return Pieza({{0, 0}, {0, 1}, {1, 0}, {1, 1}}, 0, 4, 0, 'O');
    case 2: // T
        return Pieza({{0, 1}, {1, 0}, {1, 1}, {1, 2}}, 0, 4, 0, 'T');
    case 3: // S
        return Pieza({{0, 1}, {0, 2}, {1, 0}, {1, 1}}, 0, 4, 0, 'S');
    case 4: // Z
        return Pieza({{0, 0}, {0, 1}, {1, 1}, {1, 2}}, 0, 4, 0, 'Z');
    case 5: // J
        return Pieza({{0, 0}, {1, 0}, {1, 1}, {1, 2}}, 0, 4, 0, 'J');
    case 6: // L
        return Pieza({{0, 2}, {1, 0}, {1, 1}, {1, 2}}, 0, 4, 0, 'L');
        break;
    }
    return Pieza({{0, 0}, {0, 1}, {0, 2}, {0, 3}}, 0, 4, 0, 'I'); // Por si acaso
}

int main() {
    // cout << "🟥🟧🟨🟩🟦🟪"; // Lso emojies se buscan con: windows + .
    srand(time(0)); // Es la semilla para generar piezas aleatorias

    Tablero tablero;
    Pieza piezaActual = generarPieza();
    bool jugando = true;

    while (jugando) {
        system("cls"); // Limpiar terminal
        // tablero.reiniciarTablero();
        tablero.mostrarPiezasFijas();      // Colocamos la piezas que ya estan hasta abajo
        tablero.colocarPieza(piezaActual); // Colocamos la pieza en turno
        tablero.mostrarTablero();          // Renderizamos el tablero

        // Leer la entrada del teclado
        if (_kbhit()) {
            char tecla = _getch();
            tecla = toupper(tecla);

            // Cuando guardo le da este formato, luego arreglo eso
            // Es un archivo especial que tengo para el formato del codigo
            // Ese archivo ni siquera se sube al repo
            string direccion = (tecla == 'S')   ? "Abajo"
                               : (tecla == 'A') ? "Izquierda"
                               : (tecla == 'D') ? "Derecha"
                                                : "NoValida";

            VecPar coords = piezaActual.obtenerCoordenadas();
            bool estaBordeDerecho = false;   // Si esta tocando el borde derecho del tablero
            bool estaBordeIzquierdo = false; // Si esta tocando el borde izquierdo del tablero

            for (auto coord : coords) {
                if (coord.second <= 0) { // Si cualquier bloque de la pieza esta tocando el borde
                    estaBordeIzquierdo = true;
                    break;
                }
                if (coord.second >= 9) { // Si cualquier bloque de la pieza esta tocando el borde
                    estaBordeDerecho = true;
                    break;
                }
            }

            VecPar coordsSimuladas = coords;
            ;

            // Modificamos su posicion dependiendo de la tecla
            if (direccion != "NoValida") {
                if (direccion == "Abajo") {
                    piezaActual.moverAbajo();
                } else if (direccion == "Izquierda" && !estaBordeIzquierdo) {
                    piezaActual.moverIzquierda();
                } else if (direccion == "Derecha" && !estaBordeDerecho) {
                    piezaActual.moverDerecha();
                }
            }
        }
        Sleep(300);
        // Verificamos si se puede mover en esa direccion o si ya llego hasta abajo
        VecPar coords = piezaActual.obtenerCoordenadas();
        bool estaAbajo = true; // Si ya llego al fondo del tablero

        for (auto coord : coords) {
            if (coord.first >= 19) { // Si cualquier bloque de la pieza está en la última fila
                estaAbajo = false;
                break;
            }
        }

        // Verificamos que las piesas ya hayan llegado hasta abajo y generamos una nueva
        // Falta que cosilionen con los lados y con otras piezas
        if (!estaAbajo) {
            tablero.fijarPiezaEnTablero(piezaActual);
            piezaActual = generarPieza();
        } else {
            // Sigue bajando la pieza en turno
            piezaActual.moverAbajo();
        }
        // Vaciamos el tablero para volver a poner la piezas
        tablero.reiniciarTablero();
    }

    return 0;
}