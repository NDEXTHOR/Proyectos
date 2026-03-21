# Proyectos - Operador de matrices

Este programa es un operador de matrices en consola. Es bastante basico, pero resuelve tres operaciones: suma, resta y multiplicacion. No muestra procedimiento paso a paso ni tiene todas las validaciones posibles, pero para practicar y hacer operaciones funciona bien.

Estructura general:

- No usa clases, todo esta hecho con funciones y variables globales para ir operando.
- Tiene un menu principal que se repite hasta que elijas salir.

Funciones importantes:

- IngresarMatriz(T1, T2=None): sirve para capturar una matriz desde teclado.
	- Si solo mandas T1, crea una matriz cuadrada de tamaño T1xT1.
	- Si mandas T1 y T2, crea una matriz de T1 filas por T2 columnas.
- MostrarMatriz(matriz): imprime la matriz resultante con un formato sencillo.
- SumarMatriz(matriz): suma una matriz a la matriz resultado.
- RestarMatriz(matriz): resta una matriz a la matriz resultado.
- MultiplicarMatriz(matriz, T1, T2): hace multiplicacion de matrices con la regla fila por columna.

Como funciona cada operacion:

- Suma y resta:
	- Pide cuantas matrices vas a usar (minimo 2) y el tamaño.
	- Captura cada matriz y va acumulando directo en la matriz resultado.
	- En resta, la primera matriz se toma como base y a esa se le van restando las demas.

- Multiplicacion:
	- Pide dimensiones de las dos matrices.
	- Valida que columnas de la primera = filas de la segunda.
	- Si cumple, hace la multiplicacion y guarda el resultado.
	- Si no cumple, muestra error.

Flujo general del programa:

1. Muestra el menu.
2. Lee opcion (sumar, restar, multiplicar o salir).
3. Ejecuta la operacion elegida.
4. Muestra matriz resultante.
5. Espera enter, limpia pantalla y regresa al menu.

Nota: El codigo usa variables globales, una mejora seria usar clases para un mejor manejo de las matrices

# Proyectos - 8-PUZZLE

Este programa resuelve el 8-PUZZLE con tres formas: amplitud (BFS), profundidad (DFS) y heuristica (prioriza los tableros que se ven mas cerca de la meta). En teoria trabaja con un estado inicial y uno final, pero por ahora ambos estan escritos directo en el codigo.

Se maneja principalmente con dos clases:

- puzzle: aqui se guarda el tablero 3x3, la posicion del espacio vacio, una evaluacion para la heuristica y tambien la lista de movimientos que se han hecho.
- problema_puzzles: aqui se guarda el estado inicial y el meta, y estan los metodos que hacen las busquedas.

Funciones importantes de puzzle:

- buscar(): encuentra donde esta el espacio vacio.
- imprimir(): muestra el tablero en consola.
- evaluacion(): cuenta cuantas fichas estan fuera de lugar (sin contar el espacio vacio), y eso se usa en la heuristica.
- mov_espacio_izquierda/derecha/arriba/abajo(): generan nuevos estados moviendo el espacio vacio, y van guardando el historial de movimientos para luego imprimir la ruta final.

Funciones importantes de problema_puzzles:

- esta_historial(): revisa si un estado ya aparecio para no repetir y evitar ciclos.
- Amplitud(): recorre por niveles.
- Profundidad(): recorre por ramas.
- Heuristica(): usa cola de prioridad para intentar llegar mas rapido a la meta.

Flujo general del programa:

1. Se crea el puzzle inicial y el puzzle meta en main().
2. Se crea el objeto problema_puzzles con esos dos estados.
3. Se ejecuta el metodo de busqueda (ahorita solo esta funcionando la heuristica).
4. En cada iteracion se toma un estado, se revisa si ya es la meta y si no lo es, se generan hijos con los movimientos posibles.
5. Cuando se encuentra la solucion, se imprime la ruta de movimientos paso por paso.

Nota: BFS y DFS estan comentadas en el codigo por comodidad, porque imprimen bastante informacion y puede tardar mas en algunos casos.

# Proyectos - Sudoku

Este programa resuelve un Sudoku usando busqueda por amplitud (BFS) y busqueda por profundidad (DFS). Igual que en el 8-PUZZLE, el tablero inicial por ahora esta definido directo en el codigo.

Se maneja principalmente con dos clases:

- sudoku: aqui se guarda la matriz 9x9 y se hacen las validaciones de filas, columnas y regiones 3x3.
- problemaSudoku: aqui se guarda el sudoku inicial y estan los metodos que resuelven el tablero con amplitud y profundidad.

Funciones importantes de sudoku:

- imprimir(): muestra el tablero en consola.
- verificarFila(num, fila): revisa si un numero ya existe en una fila.
- verificarColumna(num, columna): revisa si un numero ya existe en una columna.
- verificarRegion(num, region): revisa si un numero ya existe en una region 3x3.
- verificarResolucion(): comprueba que filas, columnas y regiones tengan todos los numeros del 1 al 9.

Funciones importantes de problemaSudoku:

- Amplitud(): prueba opciones usando una cola (recorrido por niveles).
- Profundidad(): prueba opciones usando pila (recorrido por ramas).

Flujo general del programa:

1. Se crea la matriz del Sudoku en main().
2. Se crea el objeto sudoku con esa matriz.
3. Se crea el objeto problemaSudoku.
4. Se ejecutan Amplitud() y Profundidad().
5. Cada metodo toma un estado, busca la primera celda vacia y prueba numeros del 1 al 9 que cumplan reglas de fila, columna y region.
6. Si el tablero queda completo y valido, imprime la solucion y el numero de iteraciones.
