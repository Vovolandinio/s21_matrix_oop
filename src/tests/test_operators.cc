#include "gtest/gtest.h"

#include "../s21_matrix_oop.hpp"

TEST(SumMatrix, SumAndOverload) {
    S21Matrix test_matrix(2, 2);
    test_matrix(0, 0) = 1;
    test_matrix(0, 1) = 1;
    test_matrix(1, 0) = 1;
    test_matrix(1, 1) = 1;
    S21Matrix other_matrix(2, 2);
    other_matrix(0, 0) = 1;
    other_matrix(0, 1) = 1;
    other_matrix(1, 0) = 1;
    other_matrix(1, 1) = 1;
    test_matrix.SumMatrix(other_matrix);
    for (int i = 0; i < test_matrix.GetRows(); i++) {
        for (int j = 0; j < test_matrix.GetCols(); j++) {
            EXPECT_DOUBLE_EQ(test_matrix(i, j), 2.0);
        }
    }
    S21Matrix overload_result = test_matrix + other_matrix;
    for (int i = 0; i < overload_result.GetRows(); i++) {
        for (int j = 0; j < overload_result.GetCols(); j++) {
            EXPECT_DOUBLE_EQ(overload_result(i, j), 3.0);
        }
    }
    overload_result += other_matrix;
    for (int i = 0; i < overload_result.GetRows(); i++) {
        for (int j = 0; j < overload_result.GetCols(); j++) {
            EXPECT_DOUBLE_EQ(overload_result(i, j), 4.0);
        }
    }
}

TEST(AssignmentOperator, EqualMatrix) {
    S21Matrix matrix_one (2,2);
    matrix_one(0, 0) = 1;
    matrix_one(0, 1) = 1;
    matrix_one(1, 0) = 1;
    matrix_one(1, 1) = 1;


    EXPECT_ANY_THROW(    for (int i = 1; i < matrix_one.GetRows(); --i) {
        matrix_one(0,i);
    });
}


TEST(S21MatrixTest, AssignmentOperatorSameObjectTest) {
    S21Matrix mat(3, 3);
    mat(0,0) = 1.0;
    mat(0,1) = 2.0;
    mat(0,2) = 3.0;
    mat(1,0) = 4.0;
    mat(1,1) = 5.0;
    mat(1,2) = 6.0;
    mat(2,0) = 7.0;
    mat(2,1) = 8.0;
    mat(2,2) = 9.0;

    S21Matrix& assigned_mat = mat;

    for (int i = 0; i < assigned_mat.GetRows(); i++) {
        for (int j = 0; j < assigned_mat.GetCols(); j++) {
            assigned_mat(i,j) = mat(i,j);
        }
    }

    EXPECT_EQ(assigned_mat(0,0), mat(0,0));
}

TEST(SubMatrix, SubAndOverload) {
    S21Matrix test_matrix(2, 2);
    test_matrix(0, 0) = 4;
    test_matrix(0, 1) = 4;
    test_matrix(1, 0) = 4;
    test_matrix(1, 1) = 4;
    S21Matrix other_matrix(2, 2);
    other_matrix(0, 0) = 1;
    other_matrix(0, 1) = 1;
    other_matrix(1, 0) = 1;
    other_matrix(1, 1) = 1;
    test_matrix.SubMatrix(other_matrix);
    for (int i = 0; i < test_matrix.GetRows(); i++) {
        for (int j = 0; j < test_matrix.GetCols(); j++) {
            EXPECT_DOUBLE_EQ(test_matrix(i, j), 3.0);
        }
    }
    S21Matrix overload_result = test_matrix - other_matrix;
    for (int i = 0; i < overload_result.GetRows(); i++) {
        for (int j = 0; j < overload_result.GetCols(); j++) {
            EXPECT_DOUBLE_EQ(overload_result(i, j), 2.0);
        }
    }
    overload_result -= other_matrix;
    for (int i = 0; i < overload_result.GetRows(); i++) {
        for (int j = 0; j < overload_result.GetCols(); j++) {
            EXPECT_DOUBLE_EQ(overload_result(i, j), 1.0);
        }
    }
}

TEST(MulNumber, MulNumberNormalAndOverload) {
    S21Matrix test_matrix(2, 2);
    test_matrix(0, 0) = 2;
    test_matrix(0, 1) = 2;
    test_matrix(1, 0) = 2;
    test_matrix(1, 1) = 2;
    double mul = 2;
    test_matrix.MulNumber(mul);
    for (int i = 0; i < test_matrix.GetRows(); i++) {
        for (int j = 0; j < test_matrix.GetCols(); j++) {
            EXPECT_DOUBLE_EQ(test_matrix(i, j), 4.0);
        }
    }
    S21Matrix overload_result = test_matrix * mul;
    for (int i = 0; i < overload_result.GetRows(); i++) {
        for (int j = 0; j < overload_result.GetCols(); j++) {
            EXPECT_DOUBLE_EQ(overload_result(i, j), 8.0);
        }
    }
    overload_result *= mul;
    for (int i = 0; i < overload_result.GetRows(); i++) {
        for (int j = 0; j < overload_result.GetCols(); j++) {
            EXPECT_DOUBLE_EQ(overload_result(i, j), 16.0);
        }
    }
}

TEST(MulMatrix, MulNormalAndOverload) {
    S21Matrix test_matrix(2, 2);
    test_matrix(0, 0) = 3.0;
    test_matrix(0, 1) = -3.0;
    test_matrix(1, 0) = -1.0;
    test_matrix(1, 1) = 5.0;

    S21Matrix other_matrix(2, 2);
    other_matrix(0, 0) = 5.0;
    other_matrix(0, 1) = 3.0;
    other_matrix(1, 0) = 1.0;
    other_matrix(1, 1) = 3.0;

    S21Matrix mulResult(2, 2);
    mulResult(0, 0) = 12.0;
    mulResult(0, 1) = 0.0;
    mulResult(1, 0) = 0.0;
    mulResult(1, 1) = 12.0;
    test_matrix.MulMatrix(other_matrix);
    EXPECT_EQ(test_matrix == mulResult, true);

    S21Matrix test_matrix2(2, 2);
    test_matrix2(0, 0) = 3.0;
    test_matrix2(0, 1) = -3.0;
    test_matrix2(1, 0) = -1.0;
    test_matrix2(1, 1) = 5.0;
    S21Matrix mulResult2 = test_matrix2 * other_matrix;
    EXPECT_EQ(test_matrix == mulResult2, true);

    test_matrix2 *= other_matrix;
    EXPECT_EQ(test_matrix2 == test_matrix, true);
}


TEST(Indexing, InvalidArgument) {
    EXPECT_THROW(S21Matrix test_matrix(-5, 0), std::invalid_argument);
}