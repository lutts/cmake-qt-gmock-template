// Copyright (c) 2014
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#include <QtWidgets>
#include <qtest.h>

class TestBenchmark : public QObject {
  Q_OBJECT
 private slots:
  void simple();
  void multiple_data();
  void multiple();
  void series_data();
  void series();
};

void TestBenchmark::simple() {
  QString str1 = QLatin1String("This is a test string");
  QString str2 = QLatin1String("This is a test string");

  QCOMPARE(str1.localeAwareCompare(str2), 0);

  QBENCHMARK {
    str1.localeAwareCompare(str2);
  }
}

void TestBenchmark::multiple_data() {
  QTest::addColumn<bool>("useLocaleCompare");
  QTest::newRow("locale aware compare") << true;
  QTest::newRow("standard compare") << false;
}

void TestBenchmark::multiple() {
  QFETCH(bool, useLocaleCompare);
  QString str1 = QLatin1String("This is a test string");
  QString str2 = QLatin1String("This is a test string");

  int result;
  if (useLocaleCompare) {
    QBENCHMARK {
      result = str1.localeAwareCompare(str2);
    }
  } else {
    QBENCHMARK {
      result = (str1 == str2);
    }
  }
  Q_UNUSED(result);
}

void TestBenchmark::series_data() {
  QTest::addColumn<bool>("useLocaleCompare");
  QTest::addColumn<int>("stringSize");

  for (int i = 1; i < 10000; i += 2000) {
    QByteArray size = QByteArray::number(i);
    QTest::newRow(("locale aware compare--" + size).constData()) << true << i;
    QTest::newRow(("standard compare--" + size).constData()) << false << i;
  }
}

void TestBenchmark::series() {
  QFETCH(bool, useLocaleCompare);
  QFETCH(int, stringSize);

  QString str1 = QString().fill('A', stringSize);
  QString str2 = QString().fill('A', stringSize);
  int result;
  if (useLocaleCompare) {
    QBENCHMARK {
      result = str1.localeAwareCompare(str2);
    }
  } else {
    QBENCHMARK {
      result = (str1 == str2);
    }
  }
  Q_UNUSED(result);
}

QTEST_MAIN(TestBenchmark)
#include "moc_benchmarking.cpp"
