#include <QtTest>

// add necessary includes here
#include "../../libs/eirType/eirType.h"

class autotest : public QObject
{
    Q_OBJECT

public:
    autotest();
    ~autotest();

#include "../../unittest/autotest/testType/testType.h"
#include "../../unittest/autotest/testType/test_eirType_DualMap.h"
#include "../../unittest/autotest/testType/test_eirType_WeightedAverageF.h"

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

#include "../../unittest/autotest/testType/testType.cpp"
#include "../../unittest/autotest/testType/test_eirType_DualMap.cpp"
#include "../../unittest/autotest/testType/test_eirType_WeightedAverageF.cpp"

autotest::autotest()
{

}

autotest::~autotest()
{

}

void autotest::initTestCase()
{
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
