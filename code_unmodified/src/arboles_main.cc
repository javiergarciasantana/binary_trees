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

void OptionsMenu(AB<long>* arbol) {
  while (true) {
    std::cout << "\nElija una opcion:\n" 
              <<  "[0] Salir\n" 
              <<  "[1] Insertar clave\n"
              <<  "[2] Buscar clave\n"
              <<  "[3] Mostrar árbol inorden\n";
    char option;
    std::cin >> option;
    switch(option) {
      case '0':
        return;
      case '1':
        long clave;
        std::cin >> clave;
        arbol->insertar(clave);
        break;
      case '2':
        long clave_b;
        std::cin >> clave_b;
        if (arbol->buscar(clave_b)) {
          std::cout << "Se ha encontrado la clave en el arbol\n";
        } else {
          std::cout << "No se ha encontrado la clave en el arbol\n";
        }
        break;
      case '3':
        arbol->Inorden(arbol->getRaiz());
        break;
      default:
        std::cout << "Parametro incorrecto, por favor:\n";
        break;
    }
  }
}

int main() {
  //ABB<long> arbol;
  // AVL<long> arbol_2;
  // arbol_2.insertar(30);
  // arbol_2.insertar(25);
  // arbol_2.insertar(15);
  // arbol_2.insertar(40);
  std::cout << "\n     PR6 ARBOLES || Javier Garcia Santana\n";
  while (true) {
    std::cout << "\nElija el tipo de arbol binario que desea crear\n" 
              << "[0] Salir\n" 
              << "[1] De Busqueda\n"
              << "[2] Balanceado\n\n";
    char option;
    std::cin >> option;
    switch (option) {
      case '0':
        exit(EXIT_SUCCESS);
        break;
      case '1':
        {
        AB<long>* arbol = new ABB<long>;
        OptionsMenu(arbol);
        break;
        }
      case '2':
      {
        AB<long>* arbol_2 = new AVL<long>;
        OptionsMenu(arbol_2);
        break;
      }
      default:
        std::cout << "Parametro incorrecto, por favor:\n";
        break;
    }                                      
  }
  return 0;
}
