#include <bits/stdc++.h>

using namespace std;

struct Nodo {
    string pregunta;      // La pregunta que se hace ("¿Esta vivo?")
    string respuesta;     // La respuesta final si es una HOJA ("Gato", "Auto", etc)
    Nodo* si;             // Puntero al nodo si la respuesta es SÍ
    Nodo* no;             // Puntero al nodo si la respuesta es NO
    bool esHoja;          // true si es una respuesta final, false si es pregunta
};

class veintePreguntas{
    private:
        Nodo* raiz;
        void recorrer(Nodo* nodo, int numPreguntas);
        void guardarRecursivo(Nodo* nodo, ofstream& archivo);
        Nodo* cargarRecursivo(ifstream& archivo);
    public:
        veintePreguntas();
        void inicializarArbol();
        void jugar();
        void guardarArbol();
        bool cargarArbol();
};

veintePreguntas::veintePreguntas(){
    raiz = NULL;
    if (!cargarArbol()) {
        inicializarArbol();
    }
}
void veintePreguntas::inicializarArbol(){
    raiz = new Nodo();
    raiz->pregunta = "¿Es animal?";
    raiz->esHoja = false;
    
    // Rama SÍ (Gato)
    raiz->si = new Nodo();
    raiz->si->respuesta = "Gato";
    raiz->si->esHoja = true;
    raiz->si->si = NULL;
    raiz->si->no = NULL;
    
    // Rama NO (Auto)
    raiz->no = new Nodo();
    raiz->no->respuesta = "Auto";
    raiz->no->esHoja = true;
    raiz->no->si = NULL;
    raiz->no->no = NULL;
}
void veintePreguntas::jugar(){
    cout << "Piensa en algo. Tengo 20 preguntas para adivinarlo.\n";
    recorrer(raiz, 0);
    guardarArbol();
}
void veintePreguntas::recorrer(Nodo* nodo, int numPreguntas){
    // Si llegamos a una hoja (respuesta final)
    if (nodo->esHoja == true) {
        cout << "¿Es " << nodo->respuesta << "?\n";
        string respuesta;
        cin >> respuesta;
        
        if (respuesta == "si" || respuesta == "Si" || respuesta == "SI") {
            cout << "¡¡¡ACERTE!!!\n";
        } else {
            cout << "Perdí. ¿Cuál era?\n";
            string respuestaCorrecta;
            cin >> respuestaCorrecta;
            
            cout << "¿Qué pregunta diferencia " << nodo->respuesta << " de " << respuestaCorrecta << "?\n";
            string nuevaPregunta;
            getline(cin, nuevaPregunta);
            
            // Crear nuevos nodos (aprender)
            nodo->esHoja = false;
            nodo->pregunta = nuevaPregunta;
            nodo->si = new Nodo();
            nodo->si->respuesta = respuestaCorrecta;
            nodo->si->esHoja = true;
            nodo->no = new Nodo();
            nodo->no->respuesta = nodo->respuesta;
            nodo->no->esHoja = true;
        }
    } else {
        // Si es una pregunta
        if (numPreguntas > 20) {
            cout << "Me rendí. ¿Qué era?\n";
            return;
        }
        
        cout << nodo->pregunta << " (si/no)\n";
        string respuesta;
        cin >> respuesta;
        
        if (respuesta == "si" || respuesta == "Si" || respuesta == "SI") {
            recorrer(nodo->si, numPreguntas + 1);
        } else {
            recorrer(nodo->no, numPreguntas + 1);
        }
    }
}
void veintePreguntas::guardarArbol(){
    ofstream archivo("C:\\Users\\bjrf8\\OneDrive\\TrabajosICBI\\Proyectos\\arbol.txt");
    if (archivo.is_open()) {
        guardarRecursivo(raiz, archivo);
        archivo.close();
        cout << "Árbol guardado.\n";
    } else {
        cout << "Error al guardar el árbol.\n";
    }
}
bool veintePreguntas::cargarArbol(){
    ifstream archivo("C:\\Users\\bjrf8\\OneDrive\\TrabajosICBI\\Proyectos\\arbol.txt");
    if (archivo.is_open()) {
        raiz = cargarRecursivo(archivo);
        archivo.close();
        return true;
    }
    return false;
}
void veintePreguntas::guardarRecursivo(Nodo* nodo, ofstream& archivo){
    if (nodo == NULL) return;
    
    if (nodo->esHoja) {
        archivo << "H " << nodo->respuesta << "\n";
    } else {
        archivo << "P " << nodo->pregunta << "\n";
        guardarRecursivo(nodo->si, archivo);
        guardarRecursivo(nodo->no, archivo);
    }
}
Nodo* veintePreguntas::cargarRecursivo(ifstream& archivo){
    string tipo, contenido;
    if (!getline(archivo, tipo)) return NULL;
    
    if (tipo.empty()) return NULL;
    
    char tipoNodo = tipo[0];
    contenido = tipo.substr(2); // Salta "P " o "H "
    
    Nodo* nodo = new Nodo();
    
    if (tipoNodo == 'H') {
        nodo->respuesta = contenido;
        nodo->esHoja = true;
        nodo->si = NULL;
        nodo->no = NULL;
    } else {
        nodo->pregunta = contenido;
        nodo->esHoja = false;
        nodo->si = cargarRecursivo(archivo);
        nodo->no = cargarRecursivo(archivo);
    }
    
    return nodo;
}

int main(){
    veintePreguntas juego;
    juego.jugar();
    
    return 0;
}