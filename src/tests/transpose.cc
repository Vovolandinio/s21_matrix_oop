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