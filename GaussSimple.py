# Con este programa se espera solucionar sistemas de ecuaciones lineales
# Se usara Gauss simple
# Para simplificar la entrada, tal cual sera la matriz y no el sistema

import numpy as np

#Funciones...
def IngresarMatriz(T1, matriz):#Solo se pueden ingresar matrices cuadradas
    for i in range(T1):
        for j in range(T1):
            matriz[i][j] = int(input(f"Valor en (fila: {i},columna: {j}): "))
    return matriz

def IngresarRes(T1, res):#Solo se pueden ingresar matrices cuadradas
    for i in range(T1):
        res[i][0] = int(input(f"Valor en (fila: {i},columna: {0}): "))
        #Podia ser una lista tal cual, pero para calcular e imprimir se me hace mas comodo
    return res

def MostrarMatriz(matriz):#Como es un foreach(Eso creo) funciona para cuarlquier matriz
    for m in matriz:
        print(*m)# El apuntador es para el formato (No se imprimen las , ni los [])

#Este comentarios es para dividir, pero no se me ocurrio que poner jaja
T = int(input("Ingrese el tamaño de la matriz: "))
matriz = np.zeros((T, T))#Inicializamos la matriz vacia
res = np.zeros((T, 1))#x2

print("Ingreso de coeficientes: ")
IngresarMatriz(T, matriz)

print("Ingreso de resultados: ")
IngresarRes(T, res)

print("Coeficientes: ")
MostrarMatriz(matriz)

print("Resultados: ")
MostrarMatriz(res)

print("Solucion: ")
resultado = np.linalg.solve(matriz, res)   # Resuelve Ax = b
MostrarMatriz(resultado)