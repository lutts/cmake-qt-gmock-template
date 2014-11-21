// Copyright (c) 2014
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#include <QDebug>

#include "src/foo.h"
#include "config.h"  // auto-generated header file, NOLINT

int main(int argc, char *argv[]) {
  Foo foo;
  qDebug() << foo.bar();

  return 0;
}
