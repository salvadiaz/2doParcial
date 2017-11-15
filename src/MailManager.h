#ifndef MAILMANAGER_H
#define MAILMANAGER_H

#include <string>
#include <vector>
#include "Lista.h"

using namespace std;


class MailManager {
private:
    // Propiedades y metodos privados de la clase
    Lista gestor;
public:
    MailManager();

    ~MailManager();

    // Métodos de uso
    void addMail(email m);

    void deleteMail(unsigned long id);

    vector<email> getSortedByDate();

    vector<email> getSortedByDate(string desde, string hasta);

    vector<email> getSortedByFrom();

    vector<email> getByFrom(string from);

    vector<email> getByQuery(string query);

    string mayus(string ss);
};


#endif // MAILMANAGER_H
