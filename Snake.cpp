#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

#define fo(i, n) for(i = 0; i < n; i++)

using namespace std;

class Snake;
class Comida;
class Tablero;

// Clases
class Snake{
    private:
        string direccion;
    public:
        deque< pair<int, int> > coords;
        Snake();
        void crecer();
        int obtenerTamano();
        string obtenerDireccion();
        void mover(string direccion);
        pair<int, int> obtenerCabeza();
        bool estaEnSerpiente(pair<int, int> pos);
};

class Comida{
    private:
        int fila;
        int columna;
    public:
        Comida(Snake& serpiente);
        void generarPosicion(Snake& serpiente);
        pair<int, int> obtenerPosicion();
};

class Tablero{
    private:
        char matriz[21][21];
    public:
        Tablero();
        void inicializar();
        void renderizar(Snake serpiente, Comida comida);
        bool verificarColision(pair<int, int> cabeza);
        bool verificarComida(pair<int, int> cabeza, pair<int, int> posComida);
};

// Funciones de Snake
Snake::Snake(){
    coords.push_back({10, 10});
    coords.push_back({10, 11});
    coords.push_back({10, 12});
    direccion = "Arriba";
}
void Snake::crecer(){
    coords.push_back(coords.back());
}
void Snake::mover(string direccion){
    pair<int, int> nuevaCabeza = coords.front();
    if (direccion == "Arriba") {
        coords.push_front({nuevaCabeza.first - 1, nuevaCabeza.second});
    } else if (direccion == "Derecha") {
        coords.push_front({nuevaCabeza.first, nuevaCabeza.second + 1});
    } else if (direccion == "Abajo") {
        coords.push_front({nuevaCabeza.first + 1, nuevaCabeza.second});
    } else if (direccion == "Izquierda"){
        coords.push_front({nuevaCabeza.first, nuevaCabeza.second - 1});
    }
    coords.pop_back();
    this->direccion = direccion; 
}
pair<int, int> Snake::obtenerCabeza(){
    return coords.front();
}
int Snake::obtenerTamano(){
    return coords.size();
}
bool Snake::estaEnSerpiente(pair<int, int> pos){
    for(size_t i = 1; i < coords.size(); i++){
        if(coords[i] == pos)
            return true;
    }
    return false;
}
string Snake::obtenerDireccion(){
    return this->direccion;
}

// Funciones de Comida
Comida::Comida(Snake& serpiente){
    generarPosicion(serpiente);
}
void Comida::generarPosicion(Snake& serpiente){
    pair<int, int> coordsAux;
    do {
        coordsAux.first = rand()%21;
        coordsAux.second = rand()%21;
    } while(serpiente.estaEnSerpiente(coordsAux));
    
    fila = coordsAux.first;
    columna = coordsAux.second;
}
pair<int, int> Comida::obtenerPosicion(){
    return {fila, columna};
}

// Funciones de Tablero
Tablero::Tablero(){
    inicializar();
}
void Tablero::inicializar(){
    int i, j;
    fo(i, 21)
		fo(j, 21)
			matriz[i][j] = ' ';
}
bool Tablero::verificarColision(pair<int, int> cabeza){
    return (cabeza.first < 0 || cabeza.first >= 21 || cabeza.second < 0 || cabeza.second >= 21);
}
bool Tablero::verificarComida(pair<int, int> cabeza, pair<int, int> posComida){
    return (cabeza == posComida);
}
void Tablero::renderizar(Snake serpiente, Comida comida){
    system("cls");
    int i, j;

    inicializar();

    fo(i, serpiente.obtenerTamano()){
        pair<int, int> seg = serpiente.coords[i];
        matriz[seg.first][seg.second] = 'O';
    }

    pair<int, int> posComida = comida.obtenerPosicion();
    matriz[posComida.first][posComida.second] = '*';

    fo(i, 23){
		fo(j, 23){
            if(i == 0 || i == 22 || j == 0 || j == 22)
                cout << "#";
            else
		        cout << matriz[i-1][j-1];
        }
        cout << "\n";
    }
}

bool esOpuesta(string dir1, string dir2){
    return((dir1 == "Arriba" && dir2 == "Abajo") || (dir1 == "Abajo" && dir2 == "Arriba")) ||
          ((dir1 == "Derecha" && dir2 == "Izquierda") || (dir1 == "Izquierda" && dir2 == "Derecha"));
}

int main(){
    srand(time(0));//Es para la semilla del rand()

    Snake serpiente = Snake();
    Comida comida = Comida(serpiente);
    Tablero tabInicial = Tablero();
    tabInicial.renderizar(serpiente, comida);

    bool juego = true;
    string dirActual = "Arriba";
    int contador = 0;

    while (juego){
        contador++;
        if(contador % 5 == 0) cout << "Iteracion: " << contador << endl; // Debug
        
        // Leer entrada si hay disponible
        if(_kbhit()){
            char tecla = _getch();
            tecla = toupper(tecla);
        
            string dirNueva = (tecla == 'W')? "Arriba": 
            (tecla == 'S')? "Abajo":
            (tecla == 'A')? "Izquierda":
            (tecla == 'D')? "Derecha": "NoValida";
        
            if(dirNueva != "" && !esOpuesta(dirActual, dirNueva)){
                dirActual = dirNueva;
            }
        }
        serpiente.mover(dirActual);
        if(tabInicial.verificarColision(serpiente.obtenerCabeza()))
            juego = false;
        if(serpiente.estaEnSerpiente(serpiente.obtenerCabeza()))
            juego = false;
        if(tabInicial.verificarComida(serpiente.obtenerCabeza(), comida.obtenerPosicion())){
            serpiente.crecer();
            comida.generarPosicion(serpiente);
        }
        tabInicial.renderizar(serpiente, comida);
        Sleep(100);
    }

    cout << "Puntuacion: " << serpiente.obtenerTamano();

    return 0;
}