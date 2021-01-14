#include "book.h"

Book::Book()
{
}

Book::Book(const QString &name, const QString &author, const int &pages,
           const int &number, QDate &date){
    bookName = name;
    bookAuthor = author;
    bookPagesAmount = pages;
    bookCardNumber = number;
    bookIssueDate = date;
}

void Book::setData(const QString &name, const QString &author,
             const int &pages, const int &number, QDate &date){
    bookName = name;
    bookAuthor = author;
    bookPagesAmount = pages;
    bookCardNumber = number;
    bookIssueDate = date;
}

void Book::setBookName(const QString &name){
    bookName = name;
}

void Book::setBookAuthor(const QString &author){
    bookAuthor = author;
}

void Book::setBookIssueDate(const QDate &date){
    bookIssueDate = date;
}

void Book::setBookCardNumber(const int &number){
    bookCardNumber = number;
}

void Book::setBookPagesAmount(const int &pages){
    bookPagesAmount = pages;
}

const QString &Book::name() const{
    return bookName;
}
const QString &Book::author() const{
    return bookAuthor;
}
const int &Book::pagesAmount() const{
    return bookPagesAmount;
}
const int &Book::cardNumber() const{
    return bookCardNumber;
}
const QDate &Book::issueDate() const{
    return bookIssueDate;
}
