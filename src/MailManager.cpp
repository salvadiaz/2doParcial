#include "MailManager.h"

/**
 * Constructor
 */


MailManager::~MailManager() {
    gestor.vaciar();
}

MailManager::MailManager() {}

/**
 * Agrega un mail al gestor
 * @param m mail a agregar
 */
void MailManager::addMail(email m) {
    gestor.insertar(m);

}

/**
 * Elimina un mail del gestor
 * @param id identificador del mail a borrar
 */
void MailManager::deleteMail(unsigned long id) {
    gestor.remover(id);
}


/**
 * Devuelve una lista de mails ordenados por fecha
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByDate() {
    vector<email> ret;
    Nodo *aux = gestor.getInicioDate();
    while(aux != nullptr){
        ret.push_back(aux->getDato());
        aux = aux->getNext();
    }

    return ret;
}


/**
 * Devuelve una lista de mails oredenados por fecha que estan en el rango
 * desde - hasta
 * @param desde Fecha desde donde buscar
 * @param hasta Fecha hasta donde buscar
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByDate(string desde, string hasta) {
    vector<email> ret;
    Nodo *aux = gestor.getInicioDate();
    while(aux->getDato().date > hasta)
        aux = aux->getNext();
    while(aux->getDato().date >= desde){
        ret.push_back(aux->getDato());
        aux = aux->getNext();
    }
    return ret;
}


/**
 * Devuelve una lista de mails ordenados por Remitente
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByFrom() {
    vector<email> ret;

    Nodo *aux = gestor.getInicioFrom();
    while(aux != nullptr){
        ret.push_back(aux->getDato());
        aux = aux->getNext();
    }

    return ret;
}


/**
 * Devuelve una lista de mails de un determinado remitente
 * @param from String con direccion del remitente
 * @return lista de mails del remitente
 */
vector<email> MailManager::getByFrom(string from) {
    vector<email> ret;
    Nodo *aux = gestor.getInicioFrom();
    while(mayus(aux->getDato().from) != mayus(from))
        aux = aux->getNext();
    while(mayus(aux->getDato().from) == mayus(from)){
        ret.push_back(aux->getDato());
        aux = aux->getNext();
    }
    return ret;
}


/**
 * Devuelve una lista de mails que contengan las palabras de 'query'
 * en su asunto o en su contenido
 * @param query String con palabra/s a buscar
 * @return lista de mails que contienen dicha/s palabra/s
 */
vector<email> MailManager::getByQuery(string query) {
    vector<email> ret;
    return ret;
}

string MailManager::mayus(string ss) {
    string tmp;
    for (char s : ss)
        tmp += toupper(s);
    return tmp;
}