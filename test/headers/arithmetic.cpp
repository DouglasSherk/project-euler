#include "../../headers/arithmetic.hpp"

#include <gtest/gtest.h>

#include <iostream>

namespace {

class ArithmeticTest : public ::testing::Test {
protected:
  ArithmeticTest() {
  }

  virtual ~ArithmeticTest() {
  }

  virtual void SetUp() {
  }

  virtual void TearDown() {
  }
};

TEST_F(ArithmeticTest, Power) {
  EXPECT_EQ(euler::power<int>(3, 3), 27);
}

TEST_F(ArithmeticTest, PowerLarge) {
  EXPECT_EQ(euler::power<long long>(12, 10), 61917364224);
}

TEST_F(ArithmeticTest, PowerModulo) {
  EXPECT_EQ(euler::power<int>(3, 3, 5), 2);
}

TEST_F(ArithmeticTest, PowerModuloLarge) {
  EXPECT_EQ(euler::power<long long>(12, 10, 15), 9);
}

} // namespace

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
