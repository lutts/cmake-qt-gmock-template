// Copyright (c) 2014
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#ifndef GTEST_DUMMY_H_
#define GTEST_DUMMY_H_

#include <string>
#include <vector>

namespace dummy_space {

class Dummy {
 public:
  Dummy();
  ~Dummy();

  size_t size() const;

  void addTask(const std::string& task);
  std::string getTask(size_t index) const;

 private:
  std::vector< std::string > this_tasks;
};
}  // namespace dummy_space

#endif  // GTEST_DUMMY_H_
