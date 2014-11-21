// Copyright (c) 2014
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#include "test/exampletest.h"
#include "src/foo.h"
#include "test/foomock.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "testconfig.h"  // NOLINT

// #include "database/databaseutil.h"
// #include <QtSql>

using ::testing::AtLeast;
using ::testing::Return;

void ExampleTest::initTestCase() {
#if 0
  qttestutil::database::DatabaseUtil database(DATABASEDRIVER);
  database.open(DATABASE);
  database.read(SQLTESTFILE);
#endif
}

void ExampleTest::testExample() {
  Foo foo;
  foo.bar();

  QVERIFY(true);
}

void ExampleTest::testMockExample() {
  FooMock mock;

  EXPECT_CALL(mock, bar()).Times(AtLeast(1))
      .WillOnce(Return(QString("foo")));

  QCOMPARE(mock.bar(), QString("foo"));

  // QVERIFY(true);
}

QTEST_GMOCK_MAIN(ExampleTest)
#include "moc_exampletest.cpp"
