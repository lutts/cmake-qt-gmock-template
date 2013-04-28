
#ifndef EXAMPLETEST_H_
#define EXAMPLETEST_H_

#include <QtTest/QtTest>

class ExampleTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void testExample();
    void testMockExample();
};

#endif /* EXAMPLETEST_H_ */
