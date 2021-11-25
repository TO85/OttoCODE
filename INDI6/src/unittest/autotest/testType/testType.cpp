//! @file testType.icpp In {repo}./src/unittest/autotest

void autotest::test_eirType()
{
    QCOMPARE( 8U, cmPow2dn9);
    QCOMPARE( 8U, cmPow2__9);
    QCOMPARE(16U, cmPow2up9);
    QCOMPARE( 8U, cmPow2dn15);
    QCOMPARE(16U, cmPow2__15);
    QCOMPARE(16U, cmPow2up15);
}
