#include <bits/stdc++.h>

using namespace std;

class puzzle {
private:
	char matriz[3][3];
	int eval = 0;
	int columna = 0;
	int fila = 0;
	list<int> movimientos;

public:

	bool operator<(const puzzle& other) const {
		return eval > other.eval;
	}

	puzzle();
	puzzle(char mtzUsuario[3][3]);
	puzzle(char, char, char, char, char, char, char, char, char);
	static void ingresarPuzzle(char mtz[3][3]);
	void imprimir();
	void buscar();
	int evaluacion(puzzle, puzzle);
	puzzle mov_espacio_izquierda();
	puzzle mov_espacio_arriba();
	puzzle mov_espacio_derecha();
	puzzle mov_espacio_abajo();

	friend class problema_puzzles;
};

puzzle::puzzle() {
	matriz[0][0] = '1';
	matriz[0][1] = '2';
	matriz[0][2] = '3';
	matriz[1][0] = '4';
	matriz[1][1] = '5';
	matriz[1][2] = '6';
	matriz[2][0] = '7';
	matriz[2][1] = '8';
	matriz[2][2] = ' ';
}
puzzle::puzzle(char mtzUsuario[3][3]){
	for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = mtzUsuario[i][j];
        }
	}
	buscar();
}
puzzle::puzzle(char c11, char c12, char c13, char c21, char c22, char c23, char c31, char c32, char c33) {
	matriz[0][0] = c11;
	matriz[0][1] = c12;
	matriz[0][2] = c13;
	matriz[1][0] = c21;
	matriz[1][1] = c22;
	matriz[1][2] = c23;
	matriz[2][0] = c31;
	matriz[2][1] = c32;
	matriz[2][2] = c33;
	buscar();
}
void puzzle::buscar() {
	for (int i = 0; i < 3; i++) {//filas
		for (int j = 0; j < 3; j++) {//columnas
			if (matriz[i][j] == ' ') {
				fila = i;
				columna = j;
				break;
			}
		}
	}
}
void puzzle::ingresarPuzzle(char mtz[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
			cin >> mtz[i][j];
			if (mtz[i][j] == '0') {// Usamos el 0 como espacio vacio
				mtz[i][j] = ' ';
			}
        }
	}
}
// void puzzle::imprimir(){
// 	for (int i = 0; i < 3; i++) {//filas
// 		for (int j = 0; j < 3; j++) {//columnas
// 			cout << matriz[i][j];
// 		}
// 		cout << endl;
// 	}
// 	cout << endl;
// }
void puzzle::imprimir(){
	//Mejore el formato con el que muestra las matrices/puzzles
	for (int i = 0; i < 3; i++) {//filas
		cout << "-------------" << endl;
		for (int j = 0; j < 3; j++) {//columnas
			if (j < 2) {
                cout << "| " << matriz[i][j] << " ";
            } else {
                cout << "| " << matriz[i][j] << " |";
            }
		}
		cout << endl;
	}
	cout << "-------------" << endl;
}
int puzzle::evaluacion(puzzle h, puzzle m) {
		int iguales = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (h.matriz[i][j] != m.matriz[i][j] && h.matriz[i][j] != ' ') {
					iguales++;
				}
			}
		}
		return iguales;
}
puzzle puzzle::mov_espacio_izquierda(){
	puzzle cambio(*this);
	if (columna != 0) {
		char aux;
		aux = cambio.matriz[cambio.fila][cambio.columna - 1];
		cambio.matriz[cambio.fila][cambio.columna - 1] = ' ';
		cambio.matriz[cambio.fila][cambio.columna] = aux;
		cambio.columna--;
		cambio.movimientos = this->movimientos;
		cambio.movimientos.push_back(4);
	}
	return cambio;
}
puzzle puzzle::mov_espacio_arriba(){
	puzzle cambio(*this);
	if (fila != 0) {
		char aux;
		aux = cambio.matriz[cambio.fila - 1][cambio.columna];
		cambio.matriz[cambio.fila - 1][cambio.columna] = ' ';
		cambio.matriz[cambio.fila][cambio.columna] = aux;
		cambio.fila--;
		cambio.movimientos = this->movimientos;
		cambio.movimientos.push_back(1);
	}
	return cambio;
}
puzzle puzzle::mov_espacio_derecha(){
	puzzle cambio(*this);
	if (columna != 2) {
		char aux;
		aux = cambio.matriz[cambio.fila][cambio.columna + 1];
		cambio.matriz[cambio.fila][cambio.columna + 1] = ' ';
		cambio.matriz[cambio.fila][cambio.columna] = aux;
		cambio.columna++;
		cambio.movimientos = this->movimientos;
		cambio.movimientos.push_back(3);
	}
	return cambio;
}
puzzle puzzle::mov_espacio_abajo(){
	puzzle cambio(*this);
	if (fila != 2) {
		char aux;
		aux = cambio.matriz[cambio.fila + 1][cambio.columna];
		cambio.matriz[cambio.fila + 1][cambio.columna] = ' ';
		cambio.matriz[cambio.fila][cambio.columna] = aux;
		cambio.fila++;
		cambio.movimientos = this->movimientos;
		cambio.movimientos.push_back(2);
	}
	return cambio;
}

class problema_puzzles {
private:
	puzzle inicial;
	puzzle meta;
public:
	problema_puzzles(puzzle, puzzle);
	bool esta_historial(puzzle, list<puzzle>);
	void Amplitud();
	void Profundidad();
	void Heuristica();
};

problema_puzzles::problema_puzzles(puzzle i, puzzle m) {
	inicial = i;
	meta = m;
	cout << "Estado inicial" << endl;
	inicial.imprimir();
	cout << "Estado meta" << endl;
	meta.imprimir();
}
bool problema_puzzles::esta_historial(puzzle x, list<puzzle> historial) {
	list<puzzle>::iterator indice;
	for (indice = historial.begin(); indice != historial.end(); indice++) {
		bool iguales = true;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (x.matriz[i][j] != indice->matriz[i][j]) {
					iguales = false;
					break;
				}
			}
			if (!iguales) {
				break;
			}
		}
		if (iguales) {
			return true;
		}
	}
	return false;
}
void problema_puzzles::Amplitud() {
	list<puzzle> lista;
	list<puzzle> historial;
	list<puzzle>::iterator it;
	int iteracion = 1;
	bool encontrado_meta = false;
	bool iguales = false;

	lista.push_front(inicial);
	historial.push_front(inicial);

	while (!lista.empty() && !encontrado_meta) {
		cout << "\nL(" << iteracion << ") \n";

		for (it = lista.begin(); it != lista.end(); it++) {
			it->imprimir();
		}
		cout << "\n";

		puzzle aux = lista.front();

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (aux.matriz[i][j] == meta.matriz[i][j]) {
					iguales = true;
				} else {
					iguales = false;
					break;
				}
			}
			if (!iguales) {
				break;
			}
		}

		if (iguales) {
			cout << "Se encontro la meta..." << endl;
			encontrado_meta = true;
		} else {
			lista.pop_front();
			puzzle hijo;

			hijo = aux.mov_espacio_izquierda();
			if (!esta_historial(hijo, historial)) {
				lista.push_back(hijo);
				historial.push_back(hijo);
			}
			hijo = aux.mov_espacio_derecha();
			if (!esta_historial(hijo, historial)) {
				lista.push_back(hijo);
				historial.push_back(hijo);
			}
			hijo = aux.mov_espacio_arriba();
			if (!esta_historial(hijo, historial)) {
				lista.push_back(hijo);
				historial.push_back(hijo);
			}
			hijo = aux.mov_espacio_abajo();
			if (!esta_historial(hijo, historial)) {
				lista.push_back(hijo);
				historial.push_back(hijo);
			}
		}

		iteracion++;
	}
	if (encontrado_meta) {
		cout << "ruta:" << endl;
		puzzle aux = lista.front();
		list<int>::iterator it;
		for (it = aux.movimientos.begin(); it != aux.movimientos.end(); it++) {
			int i = *it;
			if (i == 1) {
				cout << "Mover espacio vacio hacia arriba" << endl;
			}
			else if (i == 2) {
				cout << "Mover espacio vacio hacia abajo" << endl;
			}
			else if (i == 3) {
				cout << "Mover espacio vacio hacia la derecha" << endl;
			}
			else if (i == 4) {
				cout << "Mover espacio vacio hacia la izquierda" << endl;
			}
		}
	}
	else {
		cout << "Lista vacia, ERROR!!!" << endl;
	}
}
void problema_puzzles::Profundidad() {
	list<puzzle> lista;
	list<puzzle> historial;
	list<puzzle>::iterator it;
	int iteracion = 1;
	bool encontrado_meta = false;
	bool iguales = false;

	lista.push_front(inicial);
	historial.push_front(inicial);

	while (!lista.empty() && !encontrado_meta) {
		cout << "\nL(" << iteracion << ") \n";

		for (it = lista.begin(); it != lista.end(); it++) {
			it->imprimir();
		}
		cout << "\n";

		puzzle aux = lista.front();

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (aux.matriz[i][j] == meta.matriz[i][j]) {
					iguales = true;
				}
				else {
					iguales = false;
					break;
				}
			}
			if (!iguales) {
				break;
			}
		}

		if (iguales) {
			cout << "Se encontro la meta..." << endl;
			encontrado_meta = true;
		}
		else {
			lista.pop_front();
			puzzle hijo;

			hijo = aux.mov_espacio_abajo();
			if (!esta_historial(hijo, historial)) {
				lista.push_front(hijo);
				historial.push_back(hijo);
			}
			hijo = aux.mov_espacio_arriba();
			if (!esta_historial(hijo, historial)) {
				lista.push_front(hijo);
				historial.push_back(hijo);
			}
			hijo = aux.mov_espacio_derecha();
			if (!esta_historial(hijo, historial)) {
				lista.push_front(hijo);
				historial.push_back(hijo);
			}
			hijo = aux.mov_espacio_izquierda();
			if (!esta_historial(hijo, historial)) {
				lista.push_front(hijo);
				historial.push_back(hijo);
			}
		}

		iteracion++;
	}
	if (encontrado_meta) {
		cout << "ruta:" << endl;
		puzzle aux = lista.front();
		list<int>::iterator it;
		for (it = aux.movimientos.begin(); it != aux.movimientos.end(); it++) {
			int i = *it;
			if (i == 1) {
				cout << "Mover espacio vacio hacia arriba" << endl;
			}
			else if (i == 2) {
				cout << "Mover espacio vacio hacia abajo" << endl;
			}
			else if (i == 3) {
				cout << "Mover espacio vacio hacia la derecha" << endl;
			}
			else if (i == 4) {
				cout << "Mover espacio vacio hacia la izquierda" << endl;
			}
		}
	}
	else {
		cout << "Lista vacia, ERROR!!!" << endl;
	}
}
void problema_puzzles::Heuristica() {
	priority_queue<puzzle> lista;
	list<puzzle> historial;
	int iteracion = 1;
	bool encontrado_meta = false;
	bool iguales = false;

	lista.push(inicial);
	historial.push_front(inicial);

	while (!lista.empty() && !encontrado_meta) {
		cout << "\nL(" << iteracion << ") \n";
		
		puzzle imp = lista.top();
		imp.imprimir();

		cout << "\n";

		puzzle aux = lista.top();

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (aux.matriz[i][j] == meta.matriz[i][j]) {
					iguales = true;
				} else {
					iguales = false;
					break;
				}
			}
			if (!iguales) {
				break;
			}
		}

		if (iguales) {
			cout << "Se encontro la meta..." << endl;
			encontrado_meta = true;
		}
		else {
			lista.pop();
			puzzle hijo;

			hijo = aux.mov_espacio_abajo();
			if (!esta_historial(hijo, historial)) {
				hijo.eval = hijo.evaluacion(hijo, meta);
				lista.push(hijo);
				historial.push_back(hijo);
			}
			hijo = aux.mov_espacio_arriba();
			if (!esta_historial(hijo, historial)) {
				hijo.eval = hijo.evaluacion(hijo, meta);
				lista.push(hijo);
				historial.push_back(hijo);
			}
			hijo = aux.mov_espacio_derecha();
			if (!esta_historial(hijo, historial)) {
				hijo.eval = hijo.evaluacion(hijo, meta);
				lista.push(hijo);
				historial.push_back(hijo);
			}
			hijo = aux.mov_espacio_izquierda();
			if (!esta_historial(hijo, historial)) {
				hijo.eval = hijo.evaluacion(hijo, meta);
				lista.push(hijo);
				historial.push_back(hijo);
			}
		}

		iteracion++;
	}
	if (encontrado_meta) {
		cout << "ruta:" << endl;
		puzzle aux = lista.top();
		list<int>::iterator it;
		for (it = aux.movimientos.begin(); it != aux.movimientos.end(); it++) {
			int i = *it;
			if (i == 1) {
				cout << "Mover espacio vacio hacia arriba" << endl;
			}
			else if (i == 2) {
				cout << "Mover espacio vacio hacia abajo" << endl;
			}
			else if (i == 3) {
				cout << "Mover espacio vacio hacia la derecha" << endl;
			}
			else if (i == 4) {
				cout << "Mover espacio vacio hacia la izquierda" << endl;
			}
		}
	}
	else {
		cout << "Lista vacia, ERROR!!!" << endl;
	}
}

int main(){
	
	int op1, op2; 
	cout << "Menu: \n (1) Ingresar puzzle\n (2) Usar puzzle de ejemplo\n Ingrese una opcion: ";

	cin >> op1;

	puzzle Inicial = puzzle(); // Valor por defecto
    puzzle Final = puzzle(); // x2

	switch (op1) {
		case 1:
			// Puzzles definidos por el usuario
			char mtzInicial[3][3];
			char mtzFinal[3][3];

			cout << "Nota: En donde va el espacio vacio debe ir un 0... \n";
			cout << "Ingreso del puzzle inicial: \n";
			puzzle::ingresarPuzzle(mtzInicial);
			cout << "Ingreso del puzzle final: \n";
			puzzle::ingresarPuzzle(mtzFinal);

			Inicial = puzzle(mtzInicial);
			Final = puzzle(mtzFinal);
		break;

		case 2:
			// Puzzles predefinidos, es solo para un ejemplo de uso en si
			Inicial = puzzle('1', '2', '3', '4', '5', '6', '7', '8', ' ');
			Final = puzzle(' ', '8', '7', '6', '5', '4', '3', '2', '1');
		break;
		default:
			cout << "Opcion no valida...";
		break;
	}
	
	/*       Resolucion       */
	cout << "Menu: \n (1) Amplitud\n (2) Profundidad\n (3) Heuristica\n Ingrese una opcion: ";
	cin >> op2;

	switch (op2) {
		// Lo de las llaves se llama scope local, sirve para que las variables solo existan dentro 
		// de cada case, esta delimitada u existencias en esas llaves

		//Si no se usan da un error que se puede solucionar modificando unas cosas en la clase, 
		// pero es mas facil y comodo de esta manera
		case 1: {
			problema_puzzles Amp(Inicial, Final);
			cout << "Recorido por amplitud" << endl;
			Amp.Amplitud();
		}
		break;
		case 2: {
			problema_puzzles Pro(Inicial, Final);
			cout << "Recorido por profundidad" << endl;
			Pro.Profundidad();
		}
		break;
		case 3: {
			problema_puzzles A(Inicial, Final);
			cout << "Busqueda heuristica" << endl;
			A.Heuristica();
		}
		break;
		default:
			cout << "Opcion no valida...";
		break;
	}

	return 0;
}