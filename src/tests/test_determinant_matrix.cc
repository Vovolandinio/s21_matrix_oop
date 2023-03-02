#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

TEST(determinantMatrix, determinantNormal) {
S21Matrix test_matrix(2, 2);
test_matrix(0, 0) = 1.0;
test_matrix(0, 1) = 2.0;
test_matrix(1, 0) = 3.0;
test_matrix(1, 1) = 5.0;
double result = test_matrix.Determinant();
EXPECT_DOUBLE_EQ(result, -1.0);
}

TEST(determinantMatrix, determinantNormal2) {
S21Matrix test_matrix(2, 2);
test_matrix(0, 0) = 11.0;
test_matrix(0, 1) = -24.0;
test_matrix(1, 0) = -101.0;
test_matrix(1, 1) = 77.0;
double result = test_matrix.Determinant();
EXPECT_DOUBLE_EQ(result, -1577.0);
}

TEST(determinantMatrix, determinantNormal3) {
S21Matrix test_matrix(4, 4);
test_matrix(0, 0) = -8.0;
test_matrix(0, 1) = 1.0;
test_matrix(0, 2) = -1.0;
test_matrix(0, 3) = 3.0;

test_matrix(1, 0) = 3.0;
test_matrix(1, 1) = -1.0;
test_matrix(1, 2) = 4.0;
test_matrix(1, 3) = -3.0;

test_matrix(2, 0) = -14.0;
test_matrix(2, 1) = 2.0;
test_matrix(2, 2) = 5.0;
test_matrix(2, 3) = 1.0;

test_matrix(3, 0) = 5.0;
test_matrix(3, 1) = 3.0;
test_matrix(3, 2) = 1.0;
test_matrix(3, 3) = -1.0;
double result = test_matrix.Determinant();
EXPECT_DOUBLE_EQ(result, 125.0);
}

TEST(determinantMatrix, determinantNormal4) {
S21Matrix test_matrix(5, 5);
test_matrix(0, 0) = 4.0;
test_matrix(0, 1) = 1.0;
test_matrix(0, 2) = 1.0;
test_matrix(0, 3) = 2.0;
test_matrix(0, 4) = 1.0;

test_matrix(1, 0) = 1.0;
test_matrix(1, 1) = 2.0;
test_matrix(1, 2) = -1.0;
test_matrix(1, 3) = 1.0;
test_matrix(1, 4) = 1.0;

test_matrix(2, 0) = 3.0;
test_matrix(2, 1) = 1.0;
test_matrix(2, 2) = 1.0;
test_matrix(2, 3) = 1.0;
test_matrix(2, 4) = 1.0;

test_matrix(3, 0) = 2.0;
test_matrix(3, 1) = 1.0;
test_matrix(3, 2) = 1.0;
test_matrix(3, 3) = 4.0;
test_matrix(3, 4) = 1.0;

test_matrix(4, 0) = 2.0;
test_matrix(4, 1) = -1.0;
test_matrix(4, 2) = 1.0;
test_matrix(4, 3) = 1.0;
test_matrix(4, 4) = 5.0;
double result = test_matrix.Determinant();
EXPECT_DOUBLE_EQ(result, 64.0);
}