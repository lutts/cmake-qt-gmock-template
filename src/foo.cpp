
#include "foo.h"
#include <QDebug>

Foo::Foo()
{
}

Foo::~Foo()
{
}

QString Foo::bar()
{
    QString string("Version: %1.%2.%3");
    return string.arg(QTEMPLATE_VERSION_MAJOR).arg(QTEMPLATE_VERSION_MINOR).arg(QTEMPLATE_VERSION_PATCH);
}
