#include "gtest/gtest.h"

#include "blaze/operation/file_scan.hh"

TEST(FileScanTest, ToString)
{
  blaze::operation::FileScanOperation op;

  EXPECT_EQ("FileScan []", op.ToString());
}