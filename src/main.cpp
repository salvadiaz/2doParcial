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

    return 0;
}