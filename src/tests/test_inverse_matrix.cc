#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

TEST(InverseMatrix, InverseNormal) {
S21Matrix test_matrix(3, 3);
test_matrix(0, 0) = 2.0;
test_matrix(0, 1) = 5.0;
test_matrix(0, 2) = 7.0;

test_matrix(1, 0) = 6.0;
test_matrix(1, 1) = 3.0;
test_matrix(1, 2) = 4.0;

test_matrix(2, 0) = 5.0;
test_matrix(2, 1) = -2.0;
test_matrix(2, 2) = -3.0;

S21Matrix complements_matrix(3, 3);
complements_matrix(0, 0) = 1.0;
complements_matrix(0, 1) = -1.0;
complements_matrix(0, 2) = 1.0;

complements_matrix(1, 0) = -38.0;
complements_matrix(1, 1) = 41.0;
complements_matrix(1, 2) = -34.0;

complements_matrix(2, 0) = 27.0;
complements_matrix(2, 1) = -29.0;
complements_matrix(2, 2) = 24.0;
S21Matrix other_matrix = test_matrix.InverseMatrix();
EXPECT_EQ(other_matrix.EqMatrix(complements_matrix), true);
EXPECT_EQ(test_matrix.EqMatrix(complements_matrix), false);
}


TEST(InverseMatrix, InverseDeterminantIsZero) {
    S21Matrix matrixOne(3,3);

    matrixOne(0,0) = 0.25;
    matrixOne(0,1) = 1.25;
    matrixOne(0,2) = 2.25;
    matrixOne(1,0) = 3.25;
    matrixOne(1,1) = 4.25;
    matrixOne(1,2) = 5.25;
    matrixOne(2,0) = 6.25;
    matrixOne(2,1) = 7.25;
    matrixOne(2,2) = 8.25;

    EXPECT_ANY_THROW(matrixOne.InverseMatrix());
}