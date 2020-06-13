#include "gtest/gtest.h"

#include <exception>
#include "blaze/posix/thread.hh"
#include "blaze/concur/thread.hh"

TEST(ThreadTest, ShouldExecuteTheThreadToCompletion)
{
  int thCount = 0, mCount = 0;
  int count = 0;

  auto fn = [&thCount, &count]() {
    thCount = ++count;
    std::cout << "In Local Thread" << std::endl;
  };

  blaze::concur::ThreadAttributes attrs{1024};
  blaze::concur::Thread th{fn, attrs};

  th.Start();

  mCount = ++count;
  std::cout << "Thread Finished" << std::endl;
  
  
  EXPECT_EQ(1, thCount);
  EXPECT_EQ(2, mCount);
}

TEST(ThreadTest, ShouldNotFailOnErrorFromLocalThread)
{
  int thCount = 0, mCount = 0;
  int count = 0;

  auto fn = [&thCount, &count]() {
    thCount = ++count;
    throw std::runtime_error("Failed");
  };

  blaze::concur::ThreadAttributes attrs{128*1024};
  blaze::concur::Thread th{fn, attrs};

  th.Start();

  mCount = ++count;
  std::cout << "Thread Finished" << std::endl;

  EXPECT_EQ(1, thCount);
  EXPECT_EQ(2, mCount);
}
