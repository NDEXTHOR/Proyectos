# Mejor documentacion
https://ndexthor-proyectos.mintlify.app/introduction

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

Este programa resuelve el 8-PUZZLE con tres formas: amplitud (BFS), profundidad (DFS) y heuristica (prioriza los tableros que se ven mas cerca de la meta).

Se maneja principalmente con dos clases:

- puzzle: aqui se guarda el tablero 3x3, la posicion del espacio vacio, una evaluacion para la heuristica y tambien la lista de movimientos que se han hecho.
- problema_puzzles: aqui se guarda el estado inicial y el meta, y estan los metodos que hacen las busquedas.

Funciones importantes de puzzle:

- ingresarPuzzle(mtz[3][3]): metodo estatico que permite capturar un puzzle desde teclado. El usuario ingresa 9 digitos donde 0 representa el espacio vacio.
- buscar(): encuentra donde esta el espacio vacio.
- imprimir(): muestra el tablero en consola(Ya cuenta con un formato mejorado).
- evaluacion(): cuenta cuantas fichas estan fuera de lugar (sin contar el espacio vacio), y eso se usa en la heuristica.
- mov_espacio_izquierda/derecha/arriba/abajo(): generan nuevos estados moviendo el espacio vacio, y van guardando el historial de movimientos para luego imprimir la ruta final.

Funciones importantes de problema_puzzles:

- esta_historial(): revisa si un estado ya aparecio para no repetir y evitar ciclos.
- Amplitud(): recorre por niveles.
- Profundidad(): recorre por ramas.
- Heuristica(): usa cola de prioridad para intentar llegar mas rapido a la meta.

Flujo general del programa:

1. **Menu inicial**: el programa muestra un menu donde puedes elegir entre ingresar un puzzle personalizado o usar el puzzle de ejemplo predefinido.
2. Si eliges ingresar puzzle: captura el estado inicial y el estado meta desde teclado (9 digitos cada uno, donde 0 es el espacio vacio).
3. Si eliges el ejemplo: usa matrices predefinidas (estado inicial: 1 2 3 4 5 6 7 8 espacio | estado meta: espacio 8 7 6 5 4 3 2 1).
4. **Menu de busqueda**: despues, muestra otro menu para elegir el metodo de resolucion (amplitud, profundidad o heuristica).
5. Se crea el objeto problema_puzzles con los estados elegidos.
6. Se ejecuta el metodo de busqueda seleccionado.
7. En cada iteracion se toma un estado, se revisa si ya es la meta y si no lo es, se generan hijos con los movimientos posibles.
8. Cuando se encuentra la solucion, se imprime la ruta de movimientos paso por paso.

Mejoras recientes:

- Se agregó ingresarPuzzle() como metodo estatico para permitir entrada desde teclado.
- Se implementó un sistema de menus para elegir entre puzzle personalizado o ejemplo.
- Se agregó otro menu para elegir el algoritmo de busqueda.
- Se implementó scope local en los cases del switch con llaves {} para mejor manejo de variables.

Nota: BFS y DFS se pueden usar sin problema, pero es mucho mas recomendado usar la heuristica ya que hay una mejora notable en el tiempo de resolucion.

# Proyectos - Sudoku

Este programa resuelve un Sudoku usando busqueda por amplitud (BFS) y busqueda por profundidad (DFS).

Se maneja principalmente con dos clases:

- sudoku: aqui se guarda la matriz 9x9 y se hacen las validaciones de filas, columnas y regiones 3x3.
- problemaSudoku: aqui se guarda el sudoku inicial y estan los metodos que resuelven el tablero con amplitud y profundidad.

Funciones importantes de sudoku:

- ingresarSudoku(sudoku[9][9]): metodo estatico que permite capturar un sudoku desde teclado. El usuario ingresa 81 digitos (9 filas de 9) donde 0 representa los espacios vacios.
- imprimir(): muestra el tablero en consola.
- verificarFila(num, fila): revisa si un numero ya existe en una fila.
- verificarColumna(num, columna): revisa si un numero ya existe en una columna.
- verificarRegion(num, region): revisa si un numero ya existe en una region 3x3.
- verificarResolucion(): comprueba que filas, columnas y regiones tengan todos los numeros del 1 al 9.

Funciones importantes de problemaSudoku:

- Amplitud(): prueba opciones usando una cola (recorrido por niveles).
- Profundidad(): prueba opciones usando pila (recorrido por ramas).

Flujo general del programa:

1. **Menu inicial**: el programa muestra un menu donde puedes elegir entre ingresar un sudoku personalizado desde teclado o usar el sudoku predefinido.
2. Si eliges ingresar sudoku: captura 81 digitos (donde 0 son espacios vacios) para formar la matriz 9x9.
3. Si eliges el ejemplo: usa un sudoku predefinido en el codigo.
4. Se crea el objeto sudoku con la matriz elegida.
5. Se crea el objeto problemaSudoku.
6. Se ejecutan Amplitud() y Profundidad().
7. Cada metodo toma un estado, busca la primera celda vacia y prueba numeros del 1 al 9 que cumplan reglas de fila, columna y region.
8. Si el tablero queda completo y valido, imprime la solucion y el numero de iteraciones.

# Proyectos - Tic-Tac-Toe con IA

Es el juego del gato, pero contra la computadora. La IA nunca pierde, juega de forma perfecta. Si juegas bien, solo puedes empatar; si cometes un error, la IA te gana.

Como funciona:

- El juego se juega en un tablero 3x3.
- Tu colocas X y la IA coloca O.
- La IA usa un algoritmo que prueba todos los movimientos posibles y elige el mejor.

Lo interesante del programa:

- La IA no es random, calcula cual es el movimiento optimo analizando todas las posibilidades.
- Valida que los movimientos sean validos (no fuera del tablero, no en una casilla ocupada).
- Es bastante grafico para ser en terminal.

Como se juega:

1. Se muestra el tablero vacio.
2. Tu ingresas donde quieres poner tu X (coordenadas de 0 a 2).
3. Si el movimiento es valido, aparece tu X en el tablero.
4. La IA calcula su mejor movimiento y coloca su O.
5. Se repite hasta que alguien gane o se llene el tablero (empate).
6. Se muestra quien gano.


# Proyectos - Snake

Es el clásico juego de la serpiente en consola. La serpiente crece cada vez que come una manzana, y pierdes si golpeas una pared o tu propia cola.

Como funciona:

- La serpiente se controla con las teclas de dirección (o W/A/S/D) en tiempo real.
- La comida aparece en posiciones aleatorias del tablero.
- Cada vez que comes, la serpiente crece un segmento.
- El juego termina si chocas con una pared o con tu propia cola.

Características:

- Sistema de collisiones para paredes y autocolisión.
- Generador de comida en posiciones aleatorias.
- Tablero con bordes definidos.
- Puntuación que aumenta con cada comida consumida.
- Velocidad que aumenta conforme avanzas (juego más desafiante).

Controles:

- Flechas del teclado o W/A/S/D para mover la serpiente.
- ESC para salir del juego.

Flujo general del programa:

1. Se dibuja el tablero inicial con la serpiente en el centro.
2. La comida aparece en una posición aleatoria.
3. El juego entra en un loop donde:
   - Lee la entrada del usuario (dirección).
   - Mueve la serpiente en esa dirección.
   - Revisa si comió (si está en la misma posición que la comida).
   - Si comió, crece la cola y aparece nueva comida.
   - Revisa colisiones (paredes o autocuerpo).
   - Redibuja el tablero con la posición actualizada.
4. Cuando pierdes, muestra tu puntuación final.

Mejoras futuras:

- Sistema de niveles con tableros diferentes.
- Obstáculos que aumentan la dificultad.
- Puntuaciones máximas guardadas en archivo.
- Diferentes velocidades de juego.


# Proyectos - Tetris

Tetris en consola. Bloques que caen del cielo, los rotamos, los alineamos y desaparecen. Es un trabajo en progreso con las mecánicas básicas ya implementadas.

Componentes principales:

- **Piezas (Tetrominos)**: las 7 piezas estándar de Tetris (I, O, T, S, Z, J, L).
- **Tablero de juego**: matriz que representa el campo donde caen las piezas.
- **Sistema de rotación**: cada pieza puede rotarse para encajar mejor.
- **Detección de líneas completas**: cuando una fila se llena, desaparece.

Características implementadas:

- Generación aleatoria de piezas.
- Movimiento lateral de las piezas (izquierda/derecha).
- Sistema de rotación de piezas.
- Detección de colisiones para evitar que las piezas se salgan del tablero.
- Eliminación de líneas completas.
- Sistema de puntuación básico.
- Tablero visual en consola.
- Velocidad de caída que puede aumentar.

Controles:

- Flechas izquierda/derecha para mover la pieza.
- Flecha arriba para rotar la pieza.
- Flecha abajo para acelerar la caída.
- ESC para pausar o salir.

Flujo general del programa:

1. Se inicializa el tablero vacío.
2. Se genera una pieza aleatoria en la parte superior.
3. El juego entra en un loop principal donde:
   - La pieza desciende automáticamente cada cierto tiempo.
   - Lee entrada del usuario (movimiento o rotación).
   - Valida que los movimientos no causen colisiones.
   - Dibuja el tablero actualizado.
4. Cuando una pieza toca el fondo o otra pieza, se fija en el tablero.
5. Se revisa si hay líneas completas y se eliminan.
6. Se genera una nueva pieza en la parte superior.
7. El juego termina cuando una nueva pieza no puede colocarse (lleno hasta arriba).
8. Se muestra la puntuación final.
