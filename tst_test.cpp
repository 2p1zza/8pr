#include <QtTest>
#include "C:/Kursach/Library/Library/user.h"
// add necessary includes here

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();
    void test_case6();

};

test::test()
{

}

test::~test()
{

}

void test::test_case1()
{
    QString nam = "Alina";
    User q(User::Admin, "administrator", "password1234", nam, "evgenievna", "melnikova", "dom", 100 );
    QVERIFY(q.name() == nam);
}

void test::test_case2()
{
    QString pas = "alina123";
    User q(User::Admin, "administrator", pas, "name", "evgenievna", "melnikova", "dom", 100 );
    QVERIFY(q.password() == pas);
}

void test::test_case3()
{
    User object;
    User receive(User::Librarian, "mylogin12", "password123", "name", "evgenievna", "melnikova", "dom", 100 );
    User equal;
    equal = receive;
    QCOMPARE(receive.login(), equal.login());
    QCOMPARE(receive.password(), equal.password());
    QCOMPARE(receive.status(), equal.status());
}


void test::test_case4()
{
    QString pas = "dispetcher";
    User q(User::Admin, pas, "password123", "name", "evgenievna", "melnikova", "dom", 100 );
    QVERIFY(q.login() == pas);
}

void test::test_case5()
{
    User::Status stat = User::Admin;
    User q(stat, "administrator", "password123", "name", "evgenievna", "melnikova", "dom", 100 );
       QVERIFY(q.status() == stat);
    stat = User::Librarian;
    User q1(stat, "librerian", "password123", "name", "evgenievna", "melnikova", "dom", 100 );
       QVERIFY(q1.status() == stat);
}

void test::test_case6()
{
    const int n = 92;
    User q(User::Admin, "administrator", "password", "name", "evgenievna", "melnikova", "dom", n );
    QVERIFY(q.number() == n);
}

QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
