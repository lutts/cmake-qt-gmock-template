// Copyright (c) 2014
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#include "gtest/dummy.h"

namespace dummy_space {

Dummy::Dummy() {
}

Dummy::~Dummy() {
}


size_t Dummy::size() const {
  return this_tasks.size();
}

void Dummy::addTask(
    const std::string& task) {
  this_tasks.push_back(task);
}

std::string Dummy::getTask(
    size_t index) const {
  if (index < this_tasks.size()) {
    return this_tasks[index];
  } else {
    return "";
  }
}
}  // namespace dummy_space
