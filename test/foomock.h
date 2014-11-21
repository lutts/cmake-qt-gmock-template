// Copyright (c) 2014
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#ifndef TEST_FOOMOCK_H_
#define TEST_FOOMOCK_H_

#include <QString>

#include "src/foo.h"
#include "gmock/gmock.h"

class FooMock : public Foo {
 public:
  MOCK_METHOD0(bar, QString());
};

#endif  // TEST_FOOMOCK_H_
