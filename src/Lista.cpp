#include "Lista.h"
//
// Created by salvadiaz on 13/11/17.
//


/**
 * Constructor de la clase Lista
 * @tparam T
 */

Lista::Lista() {
    iniciodate = nullptr;
    iniciofrom = nullptr;
    id = 1;

}


/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */

//Lista::Lista(const Lista &li) {
//    iniciodate = nullptr;
//    Nodo *auxli = li.iniciodate;
//    if (auxli == nullptr)
//        return;
//
//    Nodo *auxnn = iniciodate = new Nodo(auxli->getDato(), nullptr, auxli->getDato().id);
////    Nodo *auxnn = iniciodate;
//    auxli = auxli->getNext();
//
//    while (auxli != nullptr) {
//        auxnn->setNext(new Nodo(auxli->getDato(), nullptr, auxli->getDato().id));
//
//        auxnn = auxnn->getNext(); // auxnn = newNode;
//        auxli = auxli->getNext();
//    }
//}


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
        return iniciodate == nullptr || iniciofrom == nullptr;

}


/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */

int Lista::getTamanio() {
    Nodo *aux = iniciodate;
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

    insertaDate(m, id);
    insertaFrom(m, id);
    id++;
}

void Lista::insertaDate(email m, unsigned long int iddate){
    Nodo *auxdate = iniciodate;

    if (esVacia()) {
        Nodo *nn = new Nodo(m, iniciodate, iddate);
        iniciodate = nn;
        return;
    }

    if (m.date > iniciodate->getDato().date) {
        Nodo *nn = new Nodo(m, auxdate, iddate);
        iniciodate = nn;
        return;
    }

    while (auxdate->getNext() != nullptr && m.date < auxdate->getNext()->getDato().date) {

        auxdate = auxdate->getNext();
    }

    if (auxdate == nullptr)
        throw 1;

    Nodo *nn = new Nodo(m, auxdate->getNext(), iddate);
    auxdate->setNext(nn);
}

void Lista::insertaFrom(email m, unsigned long int idfrom){
    Nodo *auxfrom = iniciofrom;

    if (esVacia()) {
        Nodo *nn = new Nodo(m, iniciofrom, idfrom);
        iniciofrom = nn;
        return;
    }

    if (m.from < iniciofrom->getDato().from) {
        Nodo *nn = new Nodo(m, auxfrom, idfrom);
        iniciofrom = nn;
        return;
    }

    while (auxfrom->getNext() != nullptr && m.from > auxfrom->getNext()->getDato().from) {
        auxfrom = auxfrom->getNext();
    }

    if (auxfrom == nullptr)
        throw 1;

    Nodo *nn = new Nodo(m, auxfrom->getNext(), idfrom);
    auxfrom->setNext(nn);
}

/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */

//void Lista::insertarPrimero(email dato) {
//    Nodo *nn = new Nodo (dato, iniciodate, iddate);
//    iniciodate = nn;
//}


/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
//template<class T>
//void Lista<T>::insertarUltimo(T dato) {
//    if (NULL == iniciodate) {
//        iniciodate = new Nodo<T>(dato, NULL);
//        return;
//    }
//
//    Nodo<T> *aux = iniciodate;
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
    removerFrom(id);
    removerDate(id);
}

void Lista::removerFrom(unsigned long int id) {
    Nodo *aux = iniciofrom;
    bool flag = true;

    if(aux->getDato().id == id) {
        if (iniciofrom == nullptr)
            throw 1;
        iniciofrom = iniciofrom->getNext();
        delete aux;
        return;
    }

    while (flag && aux->getNext() != nullptr) {
        flag = false;
        if(aux->getNext()->getDato().id != id) {
            aux = aux->getNext();
            flag = true;
        }
    }
    if (aux->getNext() == nullptr){
        cout<<"No existe"<<endl;
//        throw 1;
        return;
    }

    Nodo *tmp = aux->getNext();
    aux->setNext(tmp->getNext());
    delete tmp;
}

void Lista::removerDate(unsigned long int id) {
    Nodo *aux = iniciodate;
    bool flag = true;

    if(aux->getDato().id == id) {
        if (iniciodate == nullptr)
            throw 1;
        iniciodate = iniciodate->getNext();
        delete aux;
        return;
    }

    while (flag && aux->getNext() != nullptr) {
        flag = false;
        if (aux->getNext()->getDato().id != id) {
            aux = aux->getNext();
            flag = true;
        }
    }
    if (aux->getNext() == nullptr) {
        cout << "No existe" << endl;
//      throw 1;
        return;
    }

    Nodo *tmp = aux->getNext();
    aux->setNext(tmp->getNext());
    delete tmp;
}


/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */

email Lista::getDato(int pos) {
    int i = 0;
    Nodo *aux = iniciodate;
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
//    Nodo *aux = iniciodate;
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
    Nodo *aux = iniciodate;


    while (aux != nullptr) {
        borr = aux;
        aux = aux->getNext();
        delete borr;
    }

    aux = iniciofrom;

    while (aux != nullptr) {
        borr = aux;
        aux = aux->getNext();
        delete borr;
    }

    iniciodate = nullptr;
    iniciofrom = nullptr;
}


//void Lista::insertAfter2(email oldValue, int n, email newValue) {
//    int cont = 0;
//    Nodo *aux = iniciodate;
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

Nodo* Lista::getInicioDate() {
    return iniciodate;
}

Nodo* Lista::getInicioFrom() {
    return iniciofrom;
}


