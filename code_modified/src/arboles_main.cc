// AUTOR: Javier Garcia Santana
// FECHA: 26/4/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 5.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 6
// COMENTARIOS: Fichero .cc main del programa "Arboles"
//
// COMPILACIÓN: make

#include <iostream>

#include "ABB.h"
#include "AVL.h"

int main() {
  srand(time(NULL));
  long insertion_val;
  ABB<long> arbol;
  AVL<long> arbol_2;
  
  for (int i = 0; i < 5000; ++i) {
    insertion_val = rand() % 50000 + 0;
    arbol.insertar(insertion_val);
    arbol_2.insertar(insertion_val);
  }
  std::cout << "\nABB Num Nodos S.Izq: " << arbol.TamRama(arbol.getRaiz()->getIzdo());
  std::cout << "\nABB Num Nodos S.Der: " << arbol.TamRama(arbol.getRaiz()->getDcho());
  std::cout << "\nAVL Num Nodos S.Izq: " << arbol_2.TamRama(arbol_2.getRaiz()->getIzdo());
  std::cout << "\nAVL Num Nodos S.Der: " << arbol_2.TamRama(arbol_2.getRaiz()->getDcho()) << std::endl;
                  
  
  return 0;
}
