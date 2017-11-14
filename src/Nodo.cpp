//
// Created by salvadiaz on 14/11/17.
//
#include "Nodo.h"

Nodo::Nodo(){
    next = NULL;
}

Nodo::Nodo(email d, Nodo *n, unsigned long int id){
dato = d;
dato.id = id;
next = n;
}

email Nodo::getDato(){
    return dato;
}

void Nodo::setDato(email d){
    dato = d;
}

Nodo *Nodo::getNext(){
    return next;
}

void Nodo::setNext(Nodo *n){
    next = n;
}

Nodo::~Nodo() {

}
