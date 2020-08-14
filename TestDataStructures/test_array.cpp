#include <gtest/gtest.h>

#include "array.h"

TEST(array_tests, check_array_access_returns_correct_value)
{
   std::string test_value = "Hello";
   ds::array<std::string, 5> a;
   a[1] = test_value;
   EXPECT_EQ(test_value, a[1]);
}