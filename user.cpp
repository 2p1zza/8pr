#include "user.h"

User::User()
{
}

User::User(const Status &status, const QString &login, const QString &password,
     const QString &name, const QString &patronymic, const QString &surname,
     const QString &homeAdress, const int &number){

    userStatus = status;
    userLogin = login;
    userPassword = password;
    userName = name;
    userPatronymic = patronymic;
    userSurname = surname;
    userHomeAdress = homeAdress;
    readerNumber = number;
}

const User::Status &User::status() const{
    return userStatus;
}

const QString &User::login() const{
    return userLogin;
}

const QString &User::password() const{
    return userPassword;
}

const QString &User::name() const{
    return userName;
}

const QString &User::surname() const{
    return userSurname;
}

const QString &User::patronymic() const{
    return userPatronymic;
}

const QString &User::homeAdress() const{
    return userHomeAdress;
}

const int &User::number() const{
    return readerNumber;
}

const QString User::statusString() const{
    return getListStatus()[userStatus];
}

QMap<User::Status, QString> User::getListStatus(){
    return QMap<Status, QString>
            (
    {
        { Admin, "Администратор" },
        { Librarian, "Библиотекарь"},
        { Reader, "Читатель" }
    }
            );
}

void User::setData(const User::Status &status, const QString &login, const QString &password,
                   const QString &name, const QString &patronymic, const QString &surname,
                   const QString &homeAdress, const int &number){

    userStatus = status;
    userLogin = login;
    userPassword = password;
    userName = name;
    userPatronymic = patronymic;
    userSurname = surname;
    userHomeAdress = homeAdress;
    readerNumber = number;
}

void User::setStatus(const Status &status){
    userStatus = status;
}

void User::setLogin(const QString &login){
    userLogin = login;
}

void User::setPassword(const QString &password){
    userPassword = password;
}

void User::setNumber(const int &number){
    readerNumber = number;
}
