#include <iostream>
#include "MailManager.h"

int main() {
    std::cout << "Super gestor de mails" << std::endl;
    email pr(15, "Susana", "Mirta", "2017-11-14", "Prueba", "Este es un mail de prueba");
    email pr2(16, "Carlos", "Mirta", "2017-11-24", "Prueba2", "Me gusta el cereal");
    email pr3(17, "Patricia", "Mirta", "2017-09-14", "Prueba3", "Lorem ipsum");
    email pr4(18, "Carlos", "Mirta", "2016-11-14", "Prueba4", "Un dinosaurio? Vivo?");
    MailManager snail;
    snail.addMail(pr);
    snail.addMail(pr2);
    snail.addMail(pr3);
    snail.addMail(pr4);

    cout<<"Por fecha"<<endl;
    vector<email> bydate;
    bydate = snail.getSortedByDate();
    for(int i = 0; i < bydate.size(); i ++){
        cout<<bydate[i].subject<<endl;
        cout<<bydate[i].date<<endl;
        cout<<bydate[i].id<<endl;
    }
    cout<<endl;

    cout<<"Desde, hasta"<<endl;
    vector<email> fromdateto;
    fromdateto = snail.getSortedByDate("2017-09-13","2017-11-15");
    for(int i = 0; i < fromdateto.size(); i ++){
        cout<<fromdateto[i].subject<<endl;
        cout<<fromdateto[i].date<<endl;
    }
    cout<<endl;

    snail.deleteMail(4);
    cout<<"Delete"<<endl;
    bydate = snail.getSortedByDate();
    for(int i = 0; i < bydate.size(); i ++){
        cout<<bydate[i].subject<<endl;
        cout<<bydate[i].date<<endl;
        cout<<bydate[i].id<<endl;
    }
    cout<<endl;

    cout<<"sortedByFrom"<<endl;
    vector<email> byfrom;
    byfrom = snail.getSortedByFrom();
    for(int i = 0; i < byfrom.size(); i++){
        cout<<byfrom[i].from<<endl;
        cout<<byfrom[i].subject<<endl;
        cout<<byfrom[i].date<<endl;
        cout<<byfrom[i].id<<endl;
    }
    cout<<endl;

    cout<<"GetByFrom"<<endl;
    vector<email> getByFrom;
    getByFrom = snail.getByFrom("patricia");
    for (int i = 0; i < getByFrom.size(); i++) {
        cout<<getByFrom[i].from<<endl;
        cout<<getByFrom[i].subject<<endl;
        cout<<getByFrom[i].date<<endl;
        cout<<getByFrom[i].id<<endl;
    }

    return 0;
}