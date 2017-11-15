//
// Created by salvadiaz on 12/11/17.
//

#ifndef MAILMANAGER_NODO_H
#define MAILMANAGER_NODO_H


#include <iostream>
#include "email.h"

class Nodo{
    // friend class Lista;
private:
    email dato;
    Nodo *next;

public:
    Nodo();

    virtual ~Nodo();

    Nodo(email d, Nodo *n, unsigned long int id);

    Nodo(email d, Nodo *n);

    email getDato();

    void setDato(email d);

    Nodo *getNext();


    void setNext(Nodo *n);

};

#endif //MAILMANAGER_NODO_H
