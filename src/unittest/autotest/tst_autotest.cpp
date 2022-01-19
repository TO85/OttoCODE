#include <QtTest>

// add necessary includes here
#include "../../libs/tplBase/tplBase.h"

class autotest : public QObject
{
    Q_OBJECT

public:
    autotest();
    ~autotest();

#include "../tplBase/testBase.ih"

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

#include "../tplBase/testBase.icpp"

autotest::autotest()
{

}

autotest::~autotest()
{

}

void autotest::initTestCase()
{
    QCOMPARE(85, cmBase85);
    QCOMPARE(1, cmBase85.sign());
}

void autotest::cleanupTestCase()
{

}

void autotest::test_case1()
{
    QCOMPARE(1+2, 3);
    QVERIFY(1+1 != 3);
}

QTEST_APPLESS_MAIN(autotest)

#include "tst_autotest.moc"
