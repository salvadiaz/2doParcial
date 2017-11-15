#include <iostream>
#include "MailManager.h"

int main() {
//    std::cout << "Super gestor de mails" << std::endl;
//    email pr(15, "Susana", "Mirta", "2017-11-14", "Prueba", "Este es un mail de prueba");
//    email pr2(16, "Carlos", "Mirta", "2017-11-24", "Prueba2", "Me gusta el cereal");
//    email pr3(17, "Patricia", "Mirta", "2017-09-14", "Prueba3", "Lorem ipsum");
//    email pr4(18, "Carlos", "Mirta", "2016-11-14", "Prueba4", "Un dinosaurio ? Vivo?");
//    MailManager snail;
//    snail.addMail(pr);
//    snail.addMail(pr2);
//    snail.addMail(pr3);
//    snail.addMail(pr4);
//
//    cout<<"Por fecha"<<endl;
//    vector<email> bydate;
//    bydate = snail.getSortedByDate();
//    for(int i = 0; i < bydate.size(); i ++){
//        cout<<bydate[i].subject<<endl;
//        cout<<bydate[i].date<<endl;
//        cout<<bydate[i].id<<endl;
//    }
//    cout<<endl;
//
//    cout<<"Desde, hasta"<<endl;
//    vector<email> fromdateto;
//    fromdateto = snail.getSortedByDate("2017-09-13","2017-11-15");
//    for(int i = 0; i < fromdateto.size(); i ++){
//        cout<<fromdateto[i].subject<<endl;
//        cout<<fromdateto[i].date<<endl;
//    }
//    cout<<endl;
//
//    snail.deleteMail(4);
//    cout<<"Delete"<<endl;
//    bydate = snail.getSortedByDate();
//    for(int i = 0; i < bydate.size(); i ++){
//        cout<<bydate[i].subject<<endl;
//        cout<<bydate[i].date<<endl;
//        cout<<bydate[i].id<<endl;
//    }
//    cout<<endl;
//
//    cout<<"sortedByFrom"<<endl;
//    vector<email> byfrom;
//    byfrom = snail.getSortedByFrom();
//    for(int i = 0; i < byfrom.size(); i++){
//        cout<<byfrom[i].from<<endl;
//        cout<<byfrom[i].subject<<endl;
//        cout<<byfrom[i].date<<endl;
//        cout<<byfrom[i].id<<endl;
//    }
//    cout<<endl;
//
//    cout<<"GetByFrom"<<endl;
//    vector<email> getByFrom;
//    getByFrom = snail.getByFrom("patricia");
//    for (int i = 0; i < getByFrom.size(); i++) {
//        cout<<getByFrom[i].from<<endl;
//        cout<<getByFrom[i].subject<<endl;
//        cout<<getByFrom[i].date<<endl;
//        cout<<getByFrom[i].id<<endl;
//    }
//    cout<<endl;
//
//    cout<<"Query"<<endl;
//    vector<email> query;
//    query = snail.getByQuery("cereal");
//    for (int i = 0; i < query.size(); i++) {
//        cout<<query[i].from<<endl;
//        cout<<query[i].subject<<endl;
//        cout<<query[i].date<<endl;
//        cout<<query[i].id<<endl;
//    }
//    cout<<endl;

    MailManager snail;
    int s;
    cout<<"Bienvenido a su casilla de corres, que desea hacer:"<<endl;
    do{
        cout<<"SELECCIONE LO QUE DESEA HACER"<<endl;
        cout<<endl;

        cout<<"1- Mostrar mails por fecha"<<endl;
        cout<<"2- Mostrar mails en un rango de fechas"<<endl;
        cout<<"3- Mostrar mails por remitente"<<endl;
        cout<<"4- Buscar mails por remitente"<<endl;
        cout<<"5- Buscar mail por palabras del texto o asunto"<<endl;
        cout<<"6- Borrar mail"<<endl;
        cout<<"0- Salir"<<endl;
        cin>>s;
        system("cls");

        switch (s) {

            case 1:
                cout << "Por fecha" << endl;
                vector<email> bydate;
                bydate = snail.getSortedByDate();
                for (int i = 0; i < bydate.size(); i++) {
                    cout << "De: " << bydate[i].to << endl;
                    cout << "Para: " << bydate[i].from << endl;
                    cout << "Asunto: " << bydate[i].subject << endl;
                    cout << "Fecha" << bydate[i].date << endl;
                    cout << "Id: " << bydate[i].id << endl;
                    cout << bydate[i].content << endl;
                }
                cout << endl;
                break;

            case 2:
                string desde, hasta;
                cout << "Ingrese una fecha de inicio" << endl;
                getline(desde);
                cout << "Ingrese una fecha de finalización" << endl;
                getline(hasta);
                cout << "Desde " << desde << " hasta" << hasta << endl;
                vector<email> fromdateto;
                fromdateto = snail.getSortedByDate("2017-09-13", "2017-11-15");
                for (int i = 0; i < fromdateto.size(); i++) {
                    cout << "De: " << fromdateto[i].to << endl;
                    cout << "Para: " << fromdateto[i].from << endl;
                    cout << "Asunto: " << fromdateto[i].subject << endl;
                    cout << "Fecha" << fromdateto[i].date << endl;
                    cout << "Id: " << fromdateto[i].id << endl;
                    cout << fromdateto[i].content << endl;
                }
                cout << endl;
                break;

            case 3:
                cout << "Por remitente" << endl;
                vector<email> byfrom;
                byfrom = snail.getSortedByFrom();
                for (int i = 0; i < byfrom.size(); i++) {
                    cout << "De: " << byfrom[i].to << endl;
                    cout << "Para: " << byfrom[i].from << endl;
                    cout << "Asunto: " << byfrom[i].subject << endl;
                    cout << "Fecha" << byfrom[i].date << endl;
                    cout << "Id: " << byfrom[i].id << endl;
                    cout << byfrom[i].content << endl;
                }
                break;

            case 4:
                string remitente;
                cout << "Ingrese un remitente" << endl;
                getline(remitente);
                vector<email> getByFrom;
                getByFrom = snail.getByFrom(remitente);
                for (int i = 0; i < getByFrom.size(); i++) {
                    cout << "De: " << getByFrom[i].to << endl;
                    cout << "Para: " << getByFrom[i].from << endl;
                    cout << "Asunto: " << getByFrom[i].subject << endl;
                    cout << "Fecha" << getByFrom[i].date << endl;
                    cout << "Id: " << getByFrom[i].id << endl;
                    cout << getByFrom[i].content << endl;
                }
                break;

            case 5:
                string palabra;
                cout << "Ingrese una palabra" << endl;
                getline(palabra);
                vector<email> query;
                query = snail.getByQuery(query);
                for (int i = 0; i < query.size(); i++) {
                    cout << "De: " << query[i].to << endl;
                    cout << "Para: " << query[i].from << endl;
                    cout << "Asunto: " << query[i].subject << endl;
                    cout << "Fecha" << query[i].date << endl;
                    cout << "Id: " << query[i].id << endl;
                    cout << query[i].content << endl;
                }

                break;

            case 6:
                unsigned long int id;
                cout << "Ingrese un id" << endl;
                cin >> id;
                snail.deleteMail(id);

                break;

            case 0;
            }
        }while (s != 0 && (s>=1 && s<=6);

    return 0;
}