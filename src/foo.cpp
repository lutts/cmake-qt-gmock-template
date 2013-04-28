
#include "foo.h"

Foo::Foo()
{
}

Foo::~Foo()
{
}

QString Foo::bar()
{
    QString string("Version: ");
    string.append(QTEMPLATE_VERSION_MAJOR).append('.');
    string.append(QTEMPLATE_VERSION_MINOR).append('.');
    string.append(QTEMPLATE_VERSION_PATCH);
    return string;
}
