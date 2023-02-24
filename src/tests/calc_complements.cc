#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

TEST(CalcComplements, incorrectMatrix) {
    S21Matrix test_matrix(2,3);
    EXPECT_THROW(test_matrix.CalcComplements(),std::invalid_argument);
}
