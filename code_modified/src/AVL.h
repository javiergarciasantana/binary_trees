// AUTOR: Javier Garcia Santana
// FECHA: 26/4/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 5.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 6
// COMENTARIOS: Fichero .h en el que se declara la clase
//              hija AVL
//
// COMPILACIÓN: make

#include "ABB.h"
#include "Nodo_AVL.h"

#ifndef AVL_H
#define AVL_H

//#define M_TRAZA 

template<class Key>
class AVL : public ABB<Key> {
 public:

  bool insertar(const Key& k) {
    //se redefine el comportamiento del metodo instertar
    NodoAVL<Key>* nuevo = new NodoAVL<Key>(k);
    if (this->buscar(nuevo->getDato())) {
      //std::cout << "\nNo se ha podido insertar la clave provista";
      return false;
    }
    bool crece = false;
    //std::cout << "\nInsertar " << k;
    inserta_bal(reinterpret_cast<NodoAVL<Key>*&>(AB<Key>::raiz_), nuevo, crece);
    //std::cout << *this;
    return true;
  }

  void inserta_bal(NodoAVL<Key>* &nodo, NodoAVL<Key>* nuevo, bool &crece) {
    if (nodo == NULL) {
      nodo = nuevo; 
      crece = true;
    } else if (nuevo->getDato() < nodo->getDato()) {
      inserta_bal(reinterpret_cast<NodoAVL<Key>*&>(nodo->getIzdo()), nuevo, crece);
      if (crece) {
        insert_re_balancea_izda(nodo, crece);
      }
    } else {
      inserta_bal(reinterpret_cast<NodoAVL<Key>*&>(nodo->getDcho()), nuevo, crece);
      if (crece) {
        insert_re_balancea_dcha(nodo, crece);
      }
    }
  }

  void insert_re_balancea_izda(NodoAVL<Key>* &nodo, bool &crece) {
    //la var "crece" tiene alguna utilidad aqui?
    switch (nodo->getBal()) {
      case -1:  
        nodo->setBal(0);
        crece = false;
        break; 
      case 0: 
        nodo->setBal(1);
        break; 
      case  1: 
        NodoAVL<Key>* nodo1 = reinterpret_cast<NodoAVL<Key>*&>(nodo->getIzdo());
        if (nodo1->getBal() == 1) {
          rotacion_II(nodo);
        } else { 
          rotacion_ID(nodo);
        }
        crece = false;
    }
  }

  void rotacion_II(NodoAVL<Key>* &nodo) {
    #ifdef M_TRAZA
      std::cout << "\nDesbalanceo:" << *this;
    #endif
    NodoAVL<Key>* nodo1 = reinterpret_cast<NodoAVL<Key>*&>(nodo->getIzdo());
    nodo->getIzdo() = nodo1->getDcho();
    nodo1->getDcho() = nodo;
    if (nodo1->getBal() == 1) {
      nodo->setBal(0);
      nodo1->setBal(0);
    } else { // nodo1->bal == 0
      nodo->setBal(1);
      nodo1->setBal(-1);
    }
    #ifdef M_TRAZA
      std::cout << "\nRotacion II en[" << nodo->getDato() << "]:";
    #endif
    nodo = nodo1;
  }

  void rotacion_ID(NodoAVL<Key>* &nodo) {
    #ifdef M_TRAZA
      std::cout << "\nDesbalanceo:" << *this;
    #endif
    NodoAVL<Key>* nodo1 = reinterpret_cast<NodoAVL<Key>*&>(nodo->getIzdo());
    NodoAVL<Key>* nodo2 = reinterpret_cast<NodoAVL<Key>*&>(nodo1->getDcho());
    nodo->getIzdo() = nodo2->getDcho();
    nodo2->getDcho() = nodo; 
    nodo1->getDcho() = nodo2->getIzdo();
    nodo2->getIzdo() = nodo1; 
    if (nodo2->getBal() == -1) {
      nodo1->setBal(1);
    } else {
      nodo1->setBal(0);
    }
    if (nodo2->getBal() == 1) {
      nodo->setBal(-1);
    } else {
      nodo->setBal(0);
    }
    nodo2->setBal(0);
    #ifdef M_TRAZA
      std::cout << "\nRotacion ID en[" << nodo->getDato() << "]:";
    #endif
    nodo = nodo2; 
  }

  void insert_re_balancea_dcha(NodoAVL<Key>* &nodo, bool &crece) {
    //la var "crece" tiene alguna utilidad aqui?
    switch (nodo->getBal()) {
      case 1: 
        nodo->setBal(0);
        crece = false;
        break; 
      case 0: 
        nodo->setBal(-1);
        break; 
      case -1: 
        NodoAVL<Key>* nodo1 = reinterpret_cast<NodoAVL<Key>*&>(nodo->getDcho()); 
        if (nodo1->getBal() == -1) {
          rotacion_DD(nodo);
        } else {
          rotacion_DI(nodo);
        }
        crece = false;
    }
  }

  void rotacion_DD(NodoAVL<Key>* &nodo) {
    #ifdef M_TRAZA
      std::cout << "\nDesbalanceo:" << *this;
    #endif
    NodoAVL<Key>* nodo1 = reinterpret_cast<NodoAVL<Key>*&>(nodo->getDcho());
    nodo->getDcho() = nodo1->getIzdo();
    nodo1->getIzdo() = nodo; 
    if (nodo1->getBal() == -1) {
      nodo->setBal(0);
      nodo1->setBal(0);
    } else { // nodo1->bal == 0
      nodo->setBal(-1);
      nodo1->setBal(1);
    }
    #ifdef M_TRAZA
      std::cout << "\nRotacion DD en[" << nodo->getDato() << "]:";
    #endif
    nodo = nodo1; 
  }

  void rotacion_DI(NodoAVL<Key>* &nodo) {
    #ifdef M_TRAZA
      std::cout << "\nDesbalanceo:" << *this;
    #endif
    NodoAVL<Key>* nodo1 = reinterpret_cast<NodoAVL<Key>*&>(nodo->getDcho());
    NodoAVL<Key>* nodo2 = reinterpret_cast<NodoAVL<Key>*&>(nodo1->getIzdo());
    nodo->getDcho() = nodo2->getIzdo();
    nodo2->getIzdo() = nodo; 
    nodo1->getIzdo() = nodo2->getDcho();
    nodo2->getDcho() = nodo1; 
    if (nodo2->getBal() == 1) {
      nodo1->setBal(-1);
    } else {
      nodo1->setBal(0);
    }
    if (nodo2->getBal() == -1) {
      nodo->setBal(1); 
    } else {
      nodo->setBal(0);
    }
    nodo2->setBal(0);
    #ifdef M_TRAZA
      std::cout << "\nRotacion DI en[" << nodo->getDato() << "]:";
    #endif
    nodo = nodo2; 
  }
};

#endif