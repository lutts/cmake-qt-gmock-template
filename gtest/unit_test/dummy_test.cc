// Copyright (c) 2014
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]


#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

#include "gtest/dummy.h"

using std::string;
using ::testing::Eq;
using ::testing::Test;

namespace dummy_space {
namespace testing {
class DummyTest : public Test {
 protected:
  DummyTest() { }
  ~DummyTest() { }

  virtual void SetUp() { }
  virtual void TearDown() { }


  Dummy list;

  static const size_t taskCount = 3;
  static const char* tasks[taskCount];
};

const char* DummyTest::tasks[taskCount] = {"write code",
                                            "compile",
                                            "test"};

TEST_F(DummyTest, constructor_createsEmptyList) {
  EXPECT_THAT(list.size(), Eq(size_t(0)));
}

TEST_F(DummyTest, addTask_threeTimes_sizeIsThree) {
  list.addTask(tasks[0]);
  list.addTask(tasks[1]);
  list.addTask(tasks[2]);

  EXPECT_THAT(list.size(), Eq(taskCount));
}

TEST_F(DummyTest, getTask_withOneTask_returnsCorrectString) {
  list.addTask(tasks[0]);

  ASSERT_THAT(list.size(),     Eq(size_t(1)));
  EXPECT_THAT(list.getTask(0), Eq(tasks[0]));
}

TEST_F(DummyTest, getTask_withThreeTasts_returnsCorrectStringForEachIndex) {
  list.addTask(tasks[0]);
  list.addTask(tasks[1]);
  list.addTask(tasks[2]);

  ASSERT_THAT(list.size(),     Eq(taskCount));
  EXPECT_THAT(list.getTask(0), Eq(tasks[0]));
  EXPECT_THAT(list.getTask(1), Eq(tasks[1]));
  EXPECT_THAT(list.getTask(2), Eq(tasks[2]));
}

}  // namespace testing
}  // namespace dummy_space
