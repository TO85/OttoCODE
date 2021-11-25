//! @file testType.icpp In {repo}./src/unittest/autotest

#include <eirType/WeightedAverageF.h>

void autotest::test_eirType_WeightedAverageF()
{
    WeightedAverageF tWAF;
    QCOMPARE(0, tWAF.count());
    QVERIFY(tWAF.append(10, "Alpha", 1.0));
    QVERIFY(tWAF.append(20, "Bravo", 5.0));
    QVERIFY(tWAF.append(30, "Charlie", 2.0));
    QCOMPARE(tWAF.count(), 3);
    QVERIFY( ! tWAF.append(20, "Baker", 7.5));
    QCOMPARE(tWAF.count(), 3);
    QCOMPARE(tWAF.calculate(), 0.0);

    QVERIFY(tWAF.setScore(10, 10.0));
    QVERIFY(tWAF.setScore(20, 20.0));
    QVERIFY(tWAF.setScore(30, 30.0));
    // ((1.0 * 10.0) + (5.0 * 20.0) + (2.0 * 30.0)) / (1.0 + 5.0 + 2.0)
    QCOMPARE(tWAF.calculate(), 170.0 / 8.0); // (10 + 100 + 60) / 8 = 170 / 8 = 21.25
    QVERIFY(tWAF.setScore("Alpha", 70.0));
    QVERIFY(tWAF.setScore("Bravo", 20.0));
    QVERIFY(tWAF.setScore("Charlie", 10.0));
    // ((1.0 * 70.0) + (5.0 * 20.0) + (2.0 * 10)) / (1.0 + 5.0 + 2.0)
    // = (70 + 100 + 20) / 8 = 190 / 8 = 23.75
    QCOMPARE(tWAF.calculate(), 190.0 / 8.0); // 190 / 8 = 23.75
    tWAF.zeroValues();
    QCOMPARE(tWAF.count(), 3);
    QCOMPARE(tWAF.calculate(), 0.0);
    tWAF.clear();
    QCOMPARE(tWAF.count(), 0);
    QCOMPARE(tWAF.calculate(), 0.0);

}
