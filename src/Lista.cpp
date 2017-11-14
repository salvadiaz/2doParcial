#include "Lista.h"
//
// Created by salvadiaz on 13/11/17.
//


/**
 * Constructor de la clase Lista
 * @tparam T
 */

Lista::Lista() {
    inicio = nullptr;
    id = 1;
}


/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */

Lista::Lista(const Lista &li) {
    inicio = nullptr;
    Nodo *auxli = li.inicio;
    if (auxli == nullptr)
        return;

    Nodo *auxnn = inicio = new Nodo(auxli->getDato(), nullptr, auxli->getDato().id);
//    Nodo *auxnn = inicio;
    auxli = auxli->getNext();

    while (auxli != nullptr) {
        auxnn->setNext(new Nodo(auxli->getDato(), nullptr, auxli->getDato().id));

        auxnn = auxnn->getNext(); // auxnn = newNode;
        auxli = auxli->getNext();
    }
}


/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
 * utilizados en la lista
 * @tparam T
 */

Lista::~Lista() {
    vaciar();
}


/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */

bool Lista::esVacia() {
    return inicio == nullptr;
}


/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */

int Lista::getTamanio() {
    Nodo *aux = inicio;
    int cont = 0;

    while (aux != nullptr) {
        cont++;
        aux = aux->getNext();
    }

    return cont;
}


/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */

void Lista::insertar(email m) {

    Nodo *aux = inicio;

    if (esVacia()) {
        Nodo *nn = new Nodo(m, inicio, id);
        inicio = nn;
        return;
    }

    while (aux->getDato().date > m.date && aux != nullptr) {

        aux = aux->getNext();
    }

    if (aux == nullptr)
        throw 1;

    Nodo *nn = new Nodo(m, aux->getNext(), id);
    id++;
    aux->setNext(nn);
}


/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */

//void Lista::insertarPrimero(email dato) {
//    Nodo *nn = new Nodo (dato, inicio, id);
//    inicio = nn;
//}


/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
//template<class T>
//void Lista<T>::insertarUltimo(T dato) {
//    if (NULL == inicio) {
//        inicio = new Nodo<T>(dato, NULL);
//        return;
//    }
//
//    Nodo<T> *aux = inicio;
//    while (aux->getNext() != NULL) {
//        aux = aux->getNext();
//    }
//    Nodo<T> *nn = new Nodo<T>(dato, NULL);
//    aux->setNext(nn);
//}


/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */

void Lista::remover(unsigned long int id) {
    int cont = 0;
    Nodo *aux = inicio;

    if (id == 1) {

        if (inicio == nullptr)
            throw 1;

        inicio = inicio->getNext();
        delete[] aux;
        return;
    }

    while (cont < id - 1 && aux->getNext() != nullptr) {
        cont++;
        aux = aux->getNext();
    }
    if (aux->getNext() == nullptr)
        throw 1;

    Nodo *tmp = aux->getNext();
    aux->setNext(tmp->getNext());
    delete[] tmp;
}


/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */

email Lista::getDato(int pos) {
    int i = 0;
    Nodo *aux = inicio;
    while (i < pos && aux != nullptr) {
        aux = aux->getNext();
        i++;
    }

    if (aux == nullptr)
        throw 1;

    return aux->getDato();
}


/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */

//void Lista::reemplazar(int pos, email dato) {
//    int i = 0;
//    Nodo *aux = inicio;
//    while (i < pos && aux != NULL) {
//        aux = aux->getNext();
//        i++;
//    }
//
//    if (aux == NULL)
//        throw 1;
//
//    aux->setDato(dato);
//}


/**
 * Función que vacia la lista enlazada
 * @tparam T
 */

void Lista::vaciar() {
    Nodo *borr;
    Nodo *aux = inicio;

    while (aux != nullptr) {
        borr = aux;
        aux = aux->getNext();
        delete[] borr;
    }
    inicio = nullptr;
}


//void Lista::insertAfter2(email oldValue, int n, email newValue) {
//    int cont = 0;
//    Nodo *aux = inicio;
//    while (NULL != aux) {
//        if (aux->getDato() == oldValue) {
//            cont++;
//            if (cont == n) {
//                cont = 0;
//                Nodo *nuevoNodo = new Nodo(newValue, aux->getNext());
//                aux->setNext(nuevoNodo);
//            }
//        }
//        aux = aux->getNext();
//    }
//}

Nodo* Lista::getInicio() {
    return inicio;
}