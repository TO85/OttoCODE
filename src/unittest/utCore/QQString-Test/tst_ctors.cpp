#include <QtTest>

// add necessary includes here
#include <String>

class ctors : public QObject
{
    Q_OBJECT

public:
    ctors();
    ~ctors();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_ctors1();

};

ctors::ctors() {;}
ctors::~ctors() {;}
void ctors::initTestCase() {;}
void ctors::cleanupTestCase() {;}
void ctors::test_ctors1()
{
    QString qs("This is a Qt String");

    String voidCtor;
    String emptyCtor("");
    String pszCtor("This is a c-style string literal constructor");
    String qsCtor(qs);

    QVERIFY(voidCtor.isEmpty());
    QVERIFY(voidCtor.isNull());
    QVERIFY(emptyCtor.isEmpty());
    QVERIFY(emptyCtor.notNull());
    QVERIFY(pszCtor.notEmpty());
    QVERIFY(pszCtor.notNull());
    QVERIFY(qsCtor.notEmpty());
    QVERIFY(qsCtor.notNull());
}

QTEST_APPLESS_MAIN(ctors)

#include "tst_ctors.moc"
