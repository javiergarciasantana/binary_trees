// AUTOR: Javier Garcia Santana
// FECHA: 26/4/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 5.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 6
// COMENTARIOS: Fichero .h en el que se declara la clase
//              abstracta NodoB
//
// COMPILACIÓN: make

#include <iostream>

#ifndef NODO_B_H
#define NODO_B_H

template<class Key>
class NodoB {
 public:
  NodoB(const Key dat, NodoB<Key> *izq=NULL, NodoB<Key> *der=NULL) :
        dato_(dat), izdo_(izq), dcho_(der) {}
  
  Key getDato() const { return dato_; }
  NodoB<Key>* getIzdo() const {return izdo_; }
  NodoB<Key>* getDcho() const {return dcho_; }
  NodoB<Key>* &getIzdo()  {return izdo_; }
  NodoB<Key>* &getDcho()  {return dcho_; }

 protected:
  Key dato_;
  NodoB<Key>* izdo_;
  NodoB<Key>* dcho_;
};

#endif