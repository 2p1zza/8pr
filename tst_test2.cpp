#include <QtTest>
#include "C:/Kursach/Library/Library/book.h"


class test2 : public QObject
{
    Q_OBJECT

public:
    test2();
    ~test2();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();
};

test2::test2()
{

}

test2::~test2()
{

}

void test2::test_case1()
{
    QDate d(2015, 4, 21);
    Book e("Oblomov", "Goncharov", 12, 12, d);
    QVERIFY(e.issueDate() == d);
}

void test2::test_case2()
{
    Book object;
    QString auth = "Lermontov";
    QDate d(2015, 4, 21);
    Book q("Demon", auth, 12, 12, d);
    Book object1(q);
    QCOMPARE(q.author(), object1.author());
}

void test2::test_case3()
{
    Book object;
    QString auth = "Lermontov";
    QDate d(2015, 4, 21);
    Book receive("Parus", auth, 12, 12, d);
    Book equal;
    equal = receive;
    QCOMPARE(receive.name(), equal.name());
}

void test2::test_case4()
{
    QString nam = "Kolobok";
    QDate d(2015, 4, 21);
    Book e(nam, "Narod", 12, 12, d);
    QVERIFY(e.name() == nam);
}

void test2::test_case5()
{
    Book object;
    const int n = 12;
    QDate d(2015, 4, 21);
    Book q("Student", "Griboedov", n, 12, d);
    Book object1(q);
    QCOMPARE(q.pagesAmount(), object1.pagesAmount());
}

QTEST_APPLESS_MAIN(test2)

#include "tst_test2.moc"
