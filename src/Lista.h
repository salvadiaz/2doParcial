//
// Created by salvadiaz on 12/11/17.
//

#ifndef MAILMANAGER_LISTA_H
#define MAILMANAGER_LISTA_H


#include "Nodo.h"
//#include <iostream>

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */

class Lista {
private:
    Nodo *inicio;
    unsigned long int id;
public:
    Lista();

    Lista(const Lista &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(email m);

    //void insertarPrimero(email dato);

    //void insertarUltimo(email dato);

    void remover(unsigned long int id);

    email getDato(int pos);

//    void reemplazar(int pos, email dato);

    void vaciar();

//    void insertAfter2(email, int, email);

    Nodo *getInicio();
};



#endif //MAILMANAGER_LISTA_H