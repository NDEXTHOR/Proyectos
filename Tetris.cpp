#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

#define VecPar vector<pair<int, int>>
#define fo(i, n) for (i = 0; i < n; i++)

map<char, string> piezas = {{'I', "🟦"}, {'O', "🟧"}, {'T', "🟪"}, {'S', "🟩"}, {'Z', "🟥"}, {'J', "🟫"}, {'L', "🟨"}};

class Pieza {
  private:
    VecPar coordenadas; // Guardamos las coords de cada parte de una pieza
    int coordX, coordY; // Coordenadas de la pieza en el tablero
    int rotacion;       // Rotacion en grados
    char tipo;          // I, O, T, S, Z, J, L

    // Rotaciones
    vector<VecPar> rotaciones;
    int rotacionActual; // 1 de 4 rotaciones posibles

  public:
    Pieza(vector<VecPar> rots, int x, int y, char tip);
    Pieza(int x, int y, char tip); // Constructor simple sin rotaciones
    VecPar obtenerCoordenadas();
    char obtenerTipo();
    // Funciones para mover la pieza(derecha, izquierda y abajo)
    void rotar(); // Va a estar en chino jaja
    void moverIzquierda();
    void moverDerecha();
    void moverAbajo();
};

Pieza::Pieza(vector<VecPar> rots, int x, int y, char tip) {
    rotaciones = rots;
    coordX = x;
    coordY = y;
    rotacionActual = 0;
    tipo = tip;
}
Pieza::Pieza(int x, int y, char tip) {
    VecPar forma = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}; // Lo tuve que poner forzosamente
    rotaciones = {forma, forma, forma, forma};
    coordX = x;
    coordY = y;
    rotacionActual = 0;
    tipo = tip;
}
VecPar Pieza::obtenerCoordenadas() {
    VecPar coordsCompletas;
    for (auto coord : rotaciones[rotacionActual]) {
        coordsCompletas.push_back({coord.first + coordX, coord.second + coordY});
    }
    return coordsCompletas;
}
char Pieza::obtenerTipo() {
    return tipo;
}
void Pieza::rotar() {
    // No estuvo en chino, igual copilot me ayudo jaja
    rotacionActual = (rotacionActual + 1) % 4;
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
    int puntuacion = 0;
    Tablero(); // Hacemos el tablero vacio
    void colocarPieza(Pieza pieza);
    void fijarPiezaEnTablero(Pieza pza);
    void mostrarPiezasFijas();
    void mostrarTablero();          // Tablero con bordes
    void reiniciarTablero();        // Vaciamos el tablero
    bool estaOcupado(int x, int y); // Revisa si ya hay una pieza ahi
    void eliminarFila();            // Eliminamos la fila y bajamos las piezas
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
    cout << "\nScore: " << puntuacion << "pts\n";
}
void Tablero::fijarPiezaEnTablero(Pieza pieza) {
    VecPar coords = pieza.obtenerCoordenadas();
    for (auto coord : coords) {
        piezasEnTablero.push_back({coord, piezas[pieza.obtenerTipo()]}); // Obtenemos el emoji correspodiente jaja
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
void Tablero::eliminarFila() {
    // La hizo chat
    int fila = 0;
    fo(fila, 20) {
        int count = 0;
        for (auto pz : piezasEnTablero) {
            if (pz.first.first == fila) // Es un vector de pares de pares
                count++;
        }
        if (count == 10) {                                          // Fila llena
            for (int i = piezasEnTablero.size() - 1; i >= 0; i--) { // Itera de atras hacia adelante, no se por que
                // Segun es por los indices
                if (piezasEnTablero[i].first.first == fila) {           // Si el bloque pertenece a la fila que queremos borrar
                    piezasEnTablero.erase(piezasEnTablero.begin() + i); // Se borra el bloque
                }
            }
            // Aumentamos la puntuacion por eliminar una fila
            puntuacion += 100;

            // Hay que hacer bajar las piezas que estan arriba de la fila eliminada
            for (auto &pieza : piezasEnTablero) {
                if (pieza.first.first < fila) {
                    pieza.first.first++; // Bajar 1 fila
                }
            }
        }
    }
}

// Funciones para el funcionamiento del juego
Pieza generarPieza() {
    int tipo = rand() % 7; // Número del 0 al 6
    switch (tipo) {
        // Me las dio copilot
        // rotaciones, x, y, tipo
    case 0: // I
        return Pieza({{{0, 0}, {0, 1}, {0, 2}, {0, 3}}, {{0, 0}, {1, 0}, {2, 0}, {3, 0}}, {{0, 0}, {0, 1}, {0, 2}, {0, 3}}, {{0, 0}, {1, 0}, {2, 0}, {3, 0}}}, 0, 4, 'I');
    case 1:                      // O
        return Pieza(0, 4, 'O'); // Es otra construcctora por que no tiene rotaciones
    case 2:                      // T
        return Pieza({{{0, 1}, {1, 0}, {1, 1}, {1, 2}}, {{0, 1}, {1, 0}, {1, 1}, {2, 1}}, {{0, 0}, {0, 1}, {0, 2}, {1, 1}}, {{0, 0}, {1, 0}, {1, 1}, {2, 0}}}, 0, 4, 'T');
    case 3: // S
        return Pieza({{{0, 1}, {0, 2}, {1, 0}, {1, 1}}, {{0, 0}, {1, 0}, {1, 1}, {2, 1}}, {{0, 1}, {0, 2}, {1, 0}, {1, 1}}, {{0, 0}, {1, 0}, {1, 1}, {2, 1}}}, 0, 4, 'S');
    case 4: // Z
        return Pieza({{{0, 0}, {0, 1}, {1, 1}, {1, 2}}, {{0, 1}, {1, 0}, {1, 1}, {2, 0}}, {{0, 0}, {0, 1}, {1, 1}, {1, 2}}, {{0, 1}, {1, 0}, {1, 1}, {2, 0}}}, 0, 4, 'Z');
    case 5: // J
        return Pieza({{{0, 0}, {1, 0}, {1, 1}, {1, 2}}, {{0, 0}, {0, 1}, {1, 1}, {2, 1}}, {{0, 0}, {0, 1}, {0, 2}, {1, 2}}, {{0, 1}, {1, 1}, {2, 0}, {2, 1}}}, 0, 4, 'J');
    case 6: // L
        return Pieza({{{0, 2}, {1, 0}, {1, 1}, {1, 2}}, {{0, 0}, {1, 0}, {2, 0}, {2, 1}}, {{0, 0}, {1, 0}, {1, 1}, {1, 2}}, {{0, 0}, {0, 1}, {1, 1}, {2, 1}}}, 0, 4, 'L');
    }
}

int main() {
    // cout << "🟥🟧🟨🟩🟦🟪"; // Lso emojies se buscan con: windows + .
    srand(time(0)); // Es la semilla para generar piezas aleatorias

    Tablero tablero;
    Pieza piezaActual = generarPieza(); // La primer pieza del juego
    bool jugando = true;                // Hay que cambiarlo a falso cuando el jugador pierda

    while (jugando) {
        system("cls"); // Limpiar terminal
        // tablero.reiniciarTablero();
        tablero.mostrarPiezasFijas();      // Colocamos la piezas que ya estan hasta abajo
        tablero.colocarPieza(piezaActual); // Colocamos la pieza en turno
        tablero.mostrarTablero();          // Renderizamos el tablero

        // Leer la entrada del teclado
        // Se usan dos librerias para esto (conio.h y windows.h)
        if (_kbhit()) {
            char tecla = _getch();
            tecla = toupper(tecla);

            // Cuando guardo le da este formato, luego arreglo eso
            // Es un archivo especial que tengo para el formato del codigo
            // Ese archivo ni siquera se sube al repo
            // Ya lo modifique, se ve mejor, pero no me gusta tanto
            string direccion = (tecla == 'S') ? "Abajo" : (tecla == 'A') ? "Izquierda" : (tecla == 'D') ? "Derecha" : (tecla == 'O') ? "Rotar" : "NoValida";

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

            VecPar coordsSimuladas = coords; // Hacemos una copia de las coords reales

            // Modificamos su posicion dependiendo de la tecla
            if (direccion != "NoValida") {
                if (direccion == "Rotar") {
                    piezaActual.rotar(); // Toma la rotacion que sigue
                } else if (direccion == "Abajo") {
                    piezaActual.moverAbajo();
                } else if (direccion == "Izquierda" && !estaBordeIzquierdo) {
                    // Checaremos si no colisiona con otra pieza a la izquierda
                    int i = 0;
                    fo(i, 4) {
                        if (tablero.estaOcupado(coordsSimuladas[i].first, coordsSimuladas[i].second - 1)) {
                            // Si colisiona, no se mueve
                            break;
                        }
                    }
                    // Si no al if si llega a aqui
                    piezaActual.moverIzquierda();
                } else if (direccion == "Derecha" && !estaBordeDerecho) {
                    // Checaremos si no colisiona con otra pieza a la derecha
                    int i = 0;
                    fo(i, 4) {
                        if (tablero.estaOcupado(coordsSimuladas[i].first, coordsSimuladas[i].second + 1)) {
                            // Si colisiona, no se mueve
                            break;
                        }
                    }
                    piezaActual.moverDerecha();
                }
            }
        }
        Sleep(200);
        // Verificamos si se puede mover en esa direccion o si ya llego hasta abajo
        VecPar coords = piezaActual.obtenerCoordenadas();
        bool estaAbajo = true; // Si ya llego al fondo del tablero

        for (auto coord : coords) { // Revisamos todas las coords de la pieza actual
            if (coord.first > 18) { // Si cualquier bloque de la pieza está en la última fila
                estaAbajo = false;
                break;
            }
        }

        VecPar coordsSimuladas = coords; // Hacemos una copia de las coords reales

        int i = 0;
        fo(i, 4) {
            // Revisamos si la pieza actual choco con otra para ver si la fijamos
            if (tablero.estaOcupado(coordsSimuladas[i].first + 1, coordsSimuladas[i].second)) {
                estaAbajo = false;
                break;
            }
        }

        // Verificamos que las piesas ya hayan llegado hasta abajo y generamos una nueva
        // Falta que cosilionen con los lados y con otras piezas
        if (!estaAbajo) {
            // Fijamos la pieza en el tablero por que ya choco con otra o ya llego hasta abajo
            tablero.fijarPiezaEnTablero(piezaActual);

            // Verificamos si hay filas llenas y las eliminamos
            tablero.eliminarFila();

            piezaActual = generarPieza();
            // Aqui checaremos si ya llego al limite y ya no se pueden generar piezas
            bool generar = true; // Si se puede generar una nueva pieza

            VecPar coords = piezaActual.obtenerCoordenadas();
            for (auto coord : coords) {
                if (tablero.estaOcupado(coord.first, coord.second)) {
                    // No se puede generar una nueva pieza por que ya choco con otra
                    generar = false;
                    break;
                }
            }

            // Se puede hacer con un if para que se entienda mejor
            jugando = generar; // Si no se puede generar, el jugador pierde
        } else {
            // Sigue bajando la pieza en turno
            piezaActual.moverAbajo();
        }
        // Vaciamos el tablero para volver a poner la piezas
        tablero.reiniciarTablero();
    }

    // Si se salio del while es por que ya perdio el jugador
    // Deberiamos mostrar la puntuacion final
    // https://www.asciiart.eu/text-to-ascii-art
    cout << "\n\n";
    cout << " ________  ________  _____ ______   _______      \n";
    cout << "|\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\     \n";
    cout << "\\ \\  \\___|\\  \\  \\|\\  \\ \\  \\\\__\\ \\  \\ \\   __/|    \n";
    cout << " \\ \\  \\  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/__  \n";
    cout << "  \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\ \n";
    cout << "   \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\\n";
    cout << "    \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______|\n";
    cout << " ________  ___      ___ _______   ________       \n";
    cout << "|\\   __  \\|\\  \\    /  /|\\  ___ \\ |\\   __  \\      \n";
    cout << "\\ \\  \\|\\  \\ \\  \\  /  / | \\   __/|\\ \\  \\|\\  \\     \n";
    cout << " \\ \\  \\\\\\  \\ \\  \\/  / / \\ \\  \\_|/_\\ \\   _  _\\    \n";
    cout << "  \\ \\  \\\\\\  \\ \\    / /   \\ \\  \\_|\\ \\ \\  \\\\  \\|   \n";
    cout << "   \\ \\_______\\ \\__/ /     \\ \\_______\\ \\__\\\\ _\\   \n";
    cout << "    \\|_______|\\|__|/       \\|_______|\\|__|\\|__|  \n";
    cout << "\n\nPuntuacion Final: " << tablero.puntuacion << " pts\n";
    cout << "Gracias por jugar!\n";

    return 0;
}