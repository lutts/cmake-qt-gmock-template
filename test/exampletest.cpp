
#include "exampletest.h"

#include "foo.h"

#include "foomock.h"

//#include <QtSql>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "testconfig.h"
//#include "database/databaseutil.h"

using ::testing::AtLeast;
using ::testing::Return;

void ExampleTest::initTestCase()
{
#if 0
    qttestutil::database::DatabaseUtil database(DATABASEDRIVER);
    database.open(DATABASE);
    database.read(SQLTESTFILE);
#endif
}

void ExampleTest::testExample()
{
    Foo foo;
    foo.bar();

    QVERIFY(true);
}

void ExampleTest::testMockExample()
{
    FooMock mock;

    EXPECT_CALL(mock, bar()).Times(AtLeast(1))
    .WillOnce(Return(QString("foo")));

    QCOMPARE(mock.bar(), QString("foo"));

    // QVERIFY(true);
}

QTEST_GMOCK_MAIN(ExampleTest)
#include "exampletest.moc"
