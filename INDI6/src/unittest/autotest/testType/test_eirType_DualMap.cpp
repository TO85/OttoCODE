//! @file testType.icpp In {repo}./src/unittest/autotest

#include <eirType/DualMap.h>

void autotest::test_eirType_DualMap()
{
	DualMap<int, QString> tDMap;
    QCOMPARE(0, tDMap.count());
	tDMap.insert(0x41, "Alpha");
    QVERIFY(tDMap.contains("Alpha"));
    QVERIFY(tDMap.contains(0x41));
    QCOMPARE(1, tDMap.count());
	tDMap.insert(85, "Uniform");
    QVERIFY(tDMap.contains("Uniform"));
    QVERIFY(tDMap.contains(85));
    QCOMPARE(2, tDMap.count());
    QCOMPARE("Alpha", tDMap.at(65));
    QCOMPARE("Uniform", tDMap.at(0x55));
    tDMap.insert(0x55, "OchoCinco");
    QVERIFY("Uniform" != tDMap.at(85));
    QCOMPARE("OchoCinco", tDMap.at(85));
    QCOMPARE(85, tDMap.at("OchoCinco"));
    QCOMPARE(true, tDMap.contains(85));
    QCOMPARE(false, tDMap.contains("Uniform"));
}
