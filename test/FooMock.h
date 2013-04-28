#ifndef FOOMOCK_H
#define FOOMOCK_H

#include "gmock/gmock.h"
#include "foo.h"
#include <QString>

class FooMock : public Foo
{
public:
    MOCK_METHOD0(bar, QString());
};

#endif // FOOMOCK_H
