// Copyright (c) 2014
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#include "src/foo.h"
#include <QDebug>

Foo::Foo() {
}

Foo::~Foo() {
}

QString Foo::bar() {
    QString str("Version: %1.%2.%3");
    return str.arg(QTEMPLATE_VERSION_MAJOR)
        .arg(QTEMPLATE_VERSION_MINOR)
        .arg(QTEMPLATE_VERSION_PATCH);
}
