// Copyright (c) 2014
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#ifndef TEST_EXAMPLETEST_H_
#define TEST_EXAMPLETEST_H_

#include <QTest>

class ExampleTest : public QObject {
  Q_OBJECT

 private slots:
  void initTestCase();
  void testExample();
  void testMockExample();
};

#endif  // TEST_EXAMPLETEST_H_
