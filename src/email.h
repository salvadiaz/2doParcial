#ifndef EMAIL_H
#define EMAIL_H

using namespace std;
#include <string>
#include <iostream>


/**
 * Clase con los datos del mail
 */
class email {
public:
    unsigned long id;
    string from;
    string to;
    string date;
    string subject;
    string content;

//    email(unsigned long iddate, const string &from, const string &to, const string &date, const string &subject,
//          const string &content);
    email(){

        
    }

    email(unsigned long id, const string &from, const string &to, const string &date, const string &subject,
          const string &content) : id(id), from(from), to(to), date(date), subject(subject), content(content) {}

    virtual ~email() {

    }

//    unsigned long getId() const;
//
//    void setId(unsigned long iddate);
//
//    const string &getFrom() const;
//
//    void setFrom(const string &from);
//
//    const string &getTo() const;
//
//    void setTo(const string &to);
//
//    const string &getDate() const;
//
//    void setDate(const string &date);
//
//    const string &getSubject() const;
//
//    void setSubject(const string &subject);
//
//    const string &getContent() const;
//
//    void setContent(const string &content);
};


#endif // EMAIL_H
