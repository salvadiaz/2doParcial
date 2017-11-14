#include <string>
#include <vector>
#include "email.h"

#ifndef MAILMANAGER_H
#define MAILMANAGER_H

using namespace std;


class MailManager {
private:
    // Propiedades y metodos privados de la clase
public:
    MailManager();

    // Métodos de uso
    void addMail(email m);

    void deleteMail(unsigned long id);

    vector<email> getSortedByDate();

    vector<email> getSortedByDate(string desde, string hasta);

    vector<email> getSortedByFrom();

    vector<email> getByFrom(string from);

    vector<email> getByQuery(string query);
};


#endif // MAILMANAGER_H
