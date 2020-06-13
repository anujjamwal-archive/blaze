#include <iostream>
#include "gtest/gtest.h"

#include "blaze/posix/thread.hh"

TEST(PThreadTest, RunThread)
{
  auto func = []() {
    std::cout << "Inside Thread " << std::this_thread::get_id() << std::endl;
  };

  {
    blaze::posix::PThread thread_(func);
  }
}