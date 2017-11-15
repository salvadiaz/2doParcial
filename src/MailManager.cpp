#include <cstring>
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
    if (ret.size() == 0)
        cout<<"No hay mails entre esas fechas."<<endl;

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
    bool flag = true;
    from = mayus(from);
    while(mayus(aux->getDato().from) != from && aux->getNext() != nullptr)
        aux = aux->getNext();
    while(aux != nullptr && flag){
        flag = false;
        if(mayus(aux->getDato().from) == from) {
            ret.push_back(aux->getDato());
            aux = aux->getNext();
            flag = true;
        }
    }
    if(ret.size() == 0)
        cout<<"El remitente no existe."<<endl;

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
    string line;
    bool flag = false;
    query = mayus(query);
    Nodo *aux = gestor.getInicioDate();


    while (aux != nullptr) {
        for (int i = 0; i < aux->getDato().subject.size(); i++) {
            while (aux->getDato().subject[i] != '\0') {
                line += aux->getDato().subject[i];
                i++;
            }
            line = mayus(line);
            if (line == query) {
               // ret.push_back(aux->getDato());
                flag = true;
                i = aux->getDato().subject.size();

            }
            else{
                line.clear();
            }

        }
        if (!flag) {
            for (int i = 0; i < aux->getDato().content.size(); i++) {
                while (aux->getDato().content[i] != ' ' && aux->getDato().content[i] != '\t' && aux->getDato().content[i] != '\0' && aux->getDato().content[i] != '\v' && aux->getDato().content[i] != '\f' && aux->getDato().content[i] != '\r' && aux->getDato().content[i] != '\n') {
                    line += aux->getDato().content[i];
                    i++;
                }
                line = mayus(line);
                if (line == query) {
                    //ret.push_back(aux->getDato());
                    i = aux->getDato().content[i];
                }
                else{
                    line.clear();
                }
            }

        }
        aux = aux->getNext();
    }
    if (ret.size() == 0)
        cout<<"No se ha encontrado ningun mail con ese contenido."<<endl;

    return ret;
}

string MailManager::mayus(string ss) {
    string tmp;
    for (char s : ss)
        tmp += toupper(s);
    return tmp;
}