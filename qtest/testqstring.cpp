// Copyright (c) 2014
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#include <QtTest/QtTest>

class TestQString: public QObject {
  Q_OBJECT

 private slots:
  void toUpper_data();
  void toUpper();
};

void TestQString::toUpper_data() {
  QTest::addColumn<QString>("str");
  QTest::addColumn<QString>("result");

  QTest::newRow("all lower") << "hello" << "HELLO";
  QTest::newRow("mixed")     << "Hello" << "HELLO";
  QTest::newRow("all upper") << "HELLO" << "HELLO";
}

void TestQString::toUpper() {
  QFETCH(QString, str);
  QFETCH(QString, result);

  QCOMPARE(str.toUpper(), result);
}

QTEST_MAIN(TestQString)
#include "moc_testqstring.cpp"
