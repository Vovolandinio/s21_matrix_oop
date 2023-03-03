#include "../s21_matrix_oop.hpp"
#include "gtest/gtest.h"

TEST(test_functional, transposeCorrectMatrix) {
  S21Matrix test_matrix(2, 3);
  test_matrix(0, 0) = 3;
  test_matrix(0, 1) = 4;
  test_matrix(0, 2) = 3.5;
  test_matrix(1, 0) = 8;
  test_matrix(1, 1) = 6;
  test_matrix(1, 2) = 10;

  S21Matrix transposeMatrix = test_matrix.Transpose();

  EXPECT_EQ(transposeMatrix.GetRows(), 3);
  EXPECT_EQ(transposeMatrix.GetCols(), 2);

  EXPECT_DOUBLE_EQ(transposeMatrix(0, 0), 3);
  EXPECT_DOUBLE_EQ(transposeMatrix(0, 1), 8);
  EXPECT_DOUBLE_EQ(transposeMatrix(1, 0), 4);
  EXPECT_DOUBLE_EQ(transposeMatrix(1, 1), 6);
  EXPECT_DOUBLE_EQ(transposeMatrix(2, 0), 3.5);
  EXPECT_DOUBLE_EQ(transposeMatrix(2, 1), 10);
}