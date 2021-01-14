#include <QtTest>
#include <QDate>

// Добавляем существующие классы
#include <../Library-master/book.h>
#include <../Library-master/user.h>


Q_DECLARE_METATYPE(Book);
Q_DECLARE_METATYPE(User);

class LibraryTest : public QObject
{
    Q_OBJECT

public:
    LibraryTest();
    ~LibraryTest();

private slots:
    // CPP-class-tests
    void caseSetUserData();
    void caseSetbookdata();
};

LibraryTest::LibraryTest()
{

}

LibraryTest::~LibraryTest()
{

}

void LibraryTest::caseSetUserData()
{
    User testUser;
    // Корректные данные
    QCOMPARE(testUser.setData(User::Status::Reader, "login", "password", "Иван", "Иванов", "Иванович", "ул. Юбилейная, 9/2", 1), true);
    // Некорректные данные
    QCOMPARE(testUser.setData(User::Status::Reader, "", "password", "Иван", "Иванов", "Иванович", "ул. Юбилейная, 9/2", 1), false);
    QCOMPARE(testUser.setData(User::Status::Reader, "login", "", "Иван", "Иванов", "Иванович", "ул. Юбилейная, 9/2", 1), false);
    QCOMPARE(testUser.setData(User::Status::Reader, "login", "password", "", "Иванов", "Иванович", "ул. Юбилейная, 9/2", 1), false);
    QCOMPARE(testUser.setData(User::Status::Reader, "login", "password", "Иван", "", "Иванович", "ул. Юбилейная, 9/2", 1), false);
    QCOMPARE(testUser.setData(User::Status::Reader, "login", "password", "Иван", "Иванов", "", "ул. Юбилейная, 9/2", 1), false);
    QCOMPARE(testUser.setData(User::Status::Reader, "login", "password", "Иван", "Иванов", "Иванович", "", 1), false);
    QCOMPARE(testUser.setData(User::Status::Reader, "login", "password", "Иван", "Иванов", "Иванович", "ул. Юбилейная, 9/2", 0), false);
}

void LibraryTest::caseSetbookdata()
{
    Book testBook;
    // Корректные данные
    QCOMPARE(testBook.setData("Последний Защитник Камелота", "Роджер Желязны", 820, 1, QDate(1998, 6, 26)), true);
    // Некорректные данные
    QCOMPARE(testBook.setData("", "Роджер Желязны", 820, 1, QDate(1998, 6, 26)), false);
    QCOMPARE(testBook.setData("Последний Защитник Камелота", "", 820, 1, QDate(1998, 6, 26)), false);
    QCOMPARE(testBook.setData("Последний Защитник Камелота", "Роджер Желязны", 0, 1, QDate(1998, 6, 26)), false);
    QCOMPARE(testBook.setData("Последний Защитник Камелота", "Роджер Желязны", 820, 0, QDate(1998, 6, 26)), false);
    QCOMPARE(testBook.setData("Последний Защитник Камелота", "Роджер Желязны", 820, 1, QDate()), false);
}


QTEST_APPLESS_MAIN(LibraryTest)

#include "tst_librarytest.moc"
