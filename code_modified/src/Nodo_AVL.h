// AUTOR: Javier Garcia Santana
// FECHA: 26/4/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 5.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 6
// COMENTARIOS: Fichero .h en el que se declara la clase
//              hija NodoAVL
//
// COMPILACIÓN: make

#include "Nodo_B.h"

#ifndef NODO_AVL_H
#define NODO_AVL_H

template<class Key>
class NodoAVL : public NodoB<Key> {
 public:
  NodoAVL(const Key dato) : bal_(0), NodoB<Key>(dato) {}
  
  int getBal() const { return bal_; }
  void setBal(const int bal) { bal_ = bal; }

 private:
  int bal_;
};


#endif