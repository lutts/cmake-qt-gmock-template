
#include "foo.h"
#include "config.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    Foo foo;
    qDebug() << foo.bar();

    return 0;
}
