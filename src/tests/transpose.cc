#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

TEST(test_functional, transpose) {
    const int rows = 2;
    const int cols = 3;

    S21Matrix matrix(rows, cols);
    S21Matrix result(cols, rows);

    matrix = matrix.Transpose();
    ASSERT_TRUE(matrix == result);
}

TEST(test_functional,transposeCorrectMatrix) {
    S21Matrix test_matrix(2,3);
    test_matrix(0,0) = 3;
    test_matrix(0,1) = 4;
    test_matrix(0,2) = 3.5;
    test_matrix(1,0) = 8;
    test_matrix(1,1) = 6;
    test_matrix(1,2) = 10;

    test_matrix.Transpose();

    EXPECT_EQ(test_matrix.GetRows(),3);
    EXPECT_EQ(test_matrix.GetCols(),2);

    EXPECT_DOUBLE_EQ(test_matrix(0,0), 3);
    EXPECT_DOUBLE_EQ(test_matrix(0,1), 8);
    EXPECT_DOUBLE_EQ(test_matrix(1,0), 4);
    EXPECT_DOUBLE_EQ(test_matrix(1,1), 6);
    EXPECT_DOUBLE_EQ(test_matrix(2,0), 3.5);
    EXPECT_DOUBLE_EQ(test_matrix(2,1), 10);
}