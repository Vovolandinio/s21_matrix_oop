#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

TEST(EqualMatrix, NotEqualMatrix) {
    S21Matrix test_matrix(2, 3);
    test_matrix(0, 0) = 1.0;
    test_matrix(0, 1) = -1.0;
    test_matrix(0, 2) = 1.0;

    test_matrix(1, 0) = -38.0;
    test_matrix(1, 1) = 41.0;
    test_matrix(1, 2) = -34.0;

    S21Matrix test_matrix2(1, 4);
    test_matrix2(0, 0) = 0.023;
    test_matrix2(0, 1) = 124.161;
    test_matrix2(0, 2) = -4.445;
    test_matrix2(0, 3) = 0.123;
    EXPECT_EQ(test_matrix.EqMatrix(test_matrix2), false);
}

TEST(EqualMatrix, EqualMatrix) {
    S21Matrix test_matrix(2, 3);
    test_matrix(0, 0) = 1.0;
    test_matrix(0, 1) = -1.0;
    test_matrix(0, 2) = 1.0;

    test_matrix(1, 0) = -38.0;
    test_matrix(1, 1) = 41.0;
    test_matrix(1, 2) = -34.0;

    S21Matrix test_matrix2(2, 3);
    test_matrix2(0, 0) = 1.0;
    test_matrix2(0, 1) = -1.0;
    test_matrix2(0, 2) = 1.0;

    test_matrix2(1, 0) = -38.0;
    test_matrix2(1, 1) = 41.0;
    test_matrix2(1, 2) = -34.0;
    EXPECT_EQ(test_matrix.EqMatrix(test_matrix2), true);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}