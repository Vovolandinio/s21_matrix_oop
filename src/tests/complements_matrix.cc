#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

TEST(complements_matrix, complementsNormal) {
S21Matrix test_matrix(3, 3);
test_matrix(0, 0) = 1.0;
test_matrix(0, 1) = 2.0;
test_matrix(0, 2) = 3.0;

test_matrix(1, 0) = 0.0;
test_matrix(1, 1) = 4.0;
test_matrix(1, 2) = 2.0;

test_matrix(2, 0) = 5.0;
test_matrix(2, 1) = 2.0;
test_matrix(2, 2) = 1.0;

S21Matrix complements_matrix(3, 3);
complements_matrix(0, 0) = 0.0;
complements_matrix(0, 1) = 10.0;
complements_matrix(0, 2) = -20.0;

complements_matrix(1, 0) = 4.0;
complements_matrix(1, 1) = -14.0;
complements_matrix(1, 2) = 8.0;

complements_matrix(2, 0) = -8.0;
complements_matrix(2, 1) = -2.0;
complements_matrix(2, 2) = 4.0;
S21Matrix other_matrix = test_matrix.CalcComplements();
EXPECT_EQ(other_matrix.EqMatrix(complements_matrix), true);
}

