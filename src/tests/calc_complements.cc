#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

TEST(CalcComplements, incorrectMatrix) {
    S21Matrix test_matrix(2,3);
    EXPECT_THROW(test_matrix.CalcComplements(),std::invalid_argument);
}

TEST(CalcComplements, Matrix1x1) {
    S21Matrix test_matrix(1,1);
    test_matrix(0,0) = 3;
    test_matrix.CalcComplements();
//    EXPECT_DOUBLE_EQ(test_matrix,0);
}