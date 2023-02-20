#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

TEST(IncorrectMatrix, MatrixTwo) {
    S21Matrix incorrect (2,3);
    S21Matrix matrixTwo (3,3);

    EXPECT_THROW(incorrect.SumMatrix(matrixTwo), std::invalid_argument);
}

TEST(IncorrectMatrix, IncorrectMatrix) {
    S21Matrix incorrect (3,2);
    S21Matrix matrixTwo (3,3);

    EXPECT_THROW(incorrect.SumMatrix(matrixTwo), std::invalid_argument);
}

TEST(MatrixOne, MatrixTwo) {
    S21Matrix matrixOne(3,3);
    S21Matrix matrixTwo(3,3);

    matrixOne(0,0) = 0.25;
    matrixOne(0,1) = 1.25;
    matrixOne(0,2) = 2.25;
    matrixOne(1,0) = 3.25;
    matrixOne(1,1) = 4.25;
    matrixOne(1,2) = 5.25;
    matrixOne(2,0) = 6.25;
    matrixOne(2,1) = 7.25;
    matrixOne(2,2) = 8.25;

    matrixTwo(0,0) = 9.65;
    matrixTwo(0,1) = 8.65;
    matrixTwo(0,2) = 7.65;
    matrixTwo(1,0) = 6.65;
    matrixTwo(1,1) = 5.65;
    matrixTwo(1,2) = 4.65;
    matrixTwo(2,0) = 3.65;
    matrixTwo(2,1) = 2.65;
    matrixTwo(2,2) = 1.65;

    matrixOne.SumMatrix(matrixTwo);

    for(int i = 0; i < matrixOne.GetRows(); i++) {
        for(int j = 0; j < matrixOne.GetCols(); j++) {
            EXPECT_DOUBLE_EQ(matrixOne(i,j), 9.9);
        }
    }
}
