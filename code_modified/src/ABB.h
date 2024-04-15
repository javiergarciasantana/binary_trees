// AUTOR: Javier Garcia Santana
// FECHA: 26/4/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 5.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 6
// COMENTARIOS: Fichero .h en el que se declara la clase
//              abstracta ABB
//
// COMPILACIÓN: make

#include "AB.h"

#ifndef ABB_H
#define ABB_H

template<class Key>
class ABB : public AB<Key> {
 public:
  ABB() {
    AB<Key>::raiz_ = nullptr;
    //std::cout << "Arbol Vacio" << *this;
  }

  bool InsertarRama(NodoB<Key>* &nodo, const Key dato) {
    if (nodo == NULL) {
      nodo = new NodoB<Key>(dato);
      return true;
    } else if (dato < nodo->getDato()) {
      InsertarRama(nodo->getIzdo(), dato);
      return true;
    } else if (dato > nodo->getDato()) {
      InsertarRama(nodo->getDcho(), dato);
      return true;
    } else {
      //std::cout << "\nNo se ha podido insertar la clave provista";
      return false; //Caso elemento repetido
    }
  }
  bool BuscarRama(NodoB<Key>* nodo, const Key dato) const {
    if (nodo == NULL) { 
      return false;
    }
    if (dato == nodo->getDato()) {
      return true;
    }
    if (dato < nodo->getDato()) {
      return BuscarRama(nodo->getIzdo(), dato);
    } else {
      return BuscarRama(nodo->getDcho(), dato);
    }
  } 

  bool insertar(const Key& k) {
    //si elemento repetido, devolver false
    if (AB<Key>::raiz_ == NULL) {
      AB<Key>::raiz_ = new NodoB<Key>(k, NULL, NULL);
      //std::cout << "\nInsertar " << k << *this;
    } else {
      if (InsertarRama(AB<Key>::raiz_, k)) {
        //std::cout << "\nInsertar " << k << *this;
        return true;
      } else {
        return false;
      }
    } 
  }

  bool buscar(const Key& k) const {
    return BuscarRama(AB<Key>::raiz_, k); 
  }
};

#endif