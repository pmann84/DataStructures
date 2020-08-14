#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "array.h"

TEST(array_tests, check_array_access_returns_correct_value)
{
   std::string test_value = "Hello";
   ds::array<std::string, 5> a;
   a[1] = test_value;
   ASSERT_EQ(test_value, a[1]);
}

TEST(array_tests, fill_correctly_fills_values)
{
   uint64_t value = 25;
   ds::array<uint64_t, 5> a;
   a.fill(value);
   for (size_t i = 0; i < a.size(); ++i)
   {
      ASSERT_EQ(a[i], value);
   }
}