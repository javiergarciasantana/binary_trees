// AUTOR: Javier Garcia Santana
// FECHA: 26/4/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 5.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 6
// COMENTARIOS: Fichero .h en el colaue se declara la clase
//              abstracta AB
//
// COMPILACIÓN: make

#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

#include "Nodo_B.h"

#ifndef AB_H
#define AB_H

template <class Key>
class AB {
 public:

  void Podar(NodoB<Key>* &nodo) {
    if (nodo == NULL) return ;
    Podar(nodo->getIzdo()); // Podar subarbol izcolauierdo
    Podar(nodo->getDcho()); // Podar subarbol derecho
    delete nodo;       // Eliminar nodo
    nodo = NULL;
  }
  bool EsVacio(NodoB<Key> *nodo) { 
    return nodo == NULL; 
  }

  const int TamRama(NodoB<Key>* nodo) {
  if (nodo == NULL) {
    return 0;
  }
  return (1 + TamRama(nodo->getIzdo()) + 
          TamRama(nodo->getDcho()));
  }

  const bool EcolauilibrioRama(NodoB<Key> *nodo) {
    if (nodo == NULL) {
      return true ;
    }
    int eq = TamRama(nodo->getIzdo()) - TamRama(nodo->getDcho());
    switch (eq) {
      case -1: 
      case  0:
      case  1:
        return EcolauilibrioRama(nodo->getIzdo()) && 
              EcolauilibrioRama(nodo->getDcho());
      default: 
        return false;
    }
  }

  void Inorden(NodoB<Key> *nodo) {
    if (nodo == NULL) {
      return;
    }   
    Inorden(nodo->getIzdo());
    std::cout << "[" << nodo->getDato() << "]\n";
    Inorden(nodo->getDcho());
  }


  void recorreN(NodoB<Key> *input) {
    std::vector< std::pair<NodoB<Key>*, int> > cola;
    NodoB<Key> *nodo;
    int nivel, Nivel_actual = 0;
    cola.push_back(std::make_pair(input, 0));
    std::cout << std::endl << "Nivel " << Nivel_actual << ": ";
    while (!cola.empty()) {
      nodo = cola[0].first;
      nivel = cola[0].second;
      cola.erase(cola.begin());
      if (nivel > Nivel_actual) {
        Nivel_actual = nivel;   //Incremento de nivel  
        std::cout << std::endl << "Nivel " << Nivel_actual << ": ";
      }  
      if (nodo != NULL) {
        std::cout << "[" << nodo->getDato() << "]";
        cola.push_back(std::make_pair(nodo->getIzdo(), nivel+1));
        cola.push_back(std::make_pair(nodo->getDcho(), nivel+1));
      } else {  //Subarbol vacío
        std::cout << "[.]";
      }
    }
    std::cout << std::endl;
  }


  NodoB<Key>* &getRaiz()  {return raiz_; }
  NodoB<Key>* getRaiz() const {return raiz_; }
  virtual bool insertar(const Key& k) = 0;
  virtual bool buscar(const Key& k) const = 0;
 protected:
  NodoB<Key>* raiz_;
};

// template <class Key>
// std::ostream& operator<<(std::ostream& os, const AB<Key>& ab) {
//   std::vector< std::pair<NodoB<Key>*, int> > cola;
//   NodoB<Key> *nodo;
//   int nivel, Nivel_actual = 0;
//   cola.push_back(std::make_pair(ab.getRaiz(), 0));
//   os << std::endl << "Nivel " << Nivel_actual << ": ";
//   while (!cola.empty()) {
//     nodo = cola[0].first;
//     nivel = cola[0].second;
//     cola.erase(cola.begin());
//     if (nivel > Nivel_actual) {
//       Nivel_actual = nivel;   //Incremento de nivel  
//       os << std::endl << "Nivel " << Nivel_actual << ": ";
//     }  
//     if (nodo != NULL) {
//       os << "[" << nodo->getDato() << "]";
//       cola.push_back(std::make_pair(nodo->getIzdo(), nivel+1));
//       cola.push_back(std::make_pair(nodo->getDcho(), nivel+1));
//     } else {  //Subarbol vacío
//       os << "[.]";
//     }
//   }
//   os << std::endl;
//   return os;
// }

#endif