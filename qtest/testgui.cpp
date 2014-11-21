// Copyright (c) 2014
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#include <QtWidgets>
#include <QtTest/QtTest>

class TestGui: public QObject {
  Q_OBJECT

 private slots:
  void testGui();
};

void TestGui::testGui() {
  QLineEdit lineEdit;

  QTest::keyClicks(&lineEdit, "hello world");

  QCOMPARE(lineEdit.text(), QString("hello world"));
}

QTEST_MAIN(TestGui)
#include "moc_testgui.cpp"
