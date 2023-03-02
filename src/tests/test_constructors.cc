#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

TEST(constructor, customConstructor) {
    S21Matrix test_matrix(4, 6);
    EXPECT_EQ(4, test_matrix.GetRows());
    EXPECT_EQ(6, test_matrix.GetCols());
}

TEST(constructor, defaultConstructor) {
    S21Matrix test_matrix;
    EXPECT_EQ(5, test_matrix.GetRows());
    EXPECT_EQ(5, test_matrix.GetCols());
}

TEST(constructor, setGreaterRowDefault) {
    S21Matrix test_matrix;
    test_matrix.SetRows(15);
    EXPECT_EQ(15, test_matrix.GetRows());
    EXPECT_EQ(5, test_matrix.GetCols());
}

TEST(constructor, setLessRow) {
    S21Matrix test_matrix(10, 3);
    test_matrix.SetRows(3);
    EXPECT_EQ(3, test_matrix.GetRows());
    EXPECT_EQ(3, test_matrix.GetCols());
}

TEST(constructor, setGreaterRow) {
    S21Matrix test_matrix(5, 10);
    test_matrix.SetRows(30);
    EXPECT_EQ(30, test_matrix.GetRows());
    EXPECT_EQ(10, test_matrix.GetCols());
}

TEST(constructor, setIncorrectRow) {
    S21Matrix test_matrix(5, 10);
    EXPECT_ANY_THROW(test_matrix.SetRows(0));
}

TEST(constructor, setEqualRow) {
    S21Matrix test_matrix(5, 10);
    test_matrix.SetRows(5);
    EXPECT_EQ(5, test_matrix.GetRows());
    EXPECT_EQ(10, test_matrix.GetCols());
}

TEST(constructor, setGreaterColsDefault) {
    S21Matrix test_matrix(5, 10);
    test_matrix.SetCols(15);
    EXPECT_EQ(15, test_matrix.GetCols());
    EXPECT_EQ(5, test_matrix.GetRows());
}

TEST(constructor, setIncorrectCols) {
    S21Matrix test_matrix(5, 10);
    EXPECT_ANY_THROW(test_matrix.SetCols(0));
}

TEST(constructor, setLessColsDefault) {
    S21Matrix test_matrix(5, 10);
    test_matrix.SetCols(3);
    EXPECT_EQ(3, test_matrix.GetCols());
    EXPECT_EQ(5, test_matrix.GetRows());
}

TEST(constructor, setLessEqualDefault) {
    S21Matrix test_matrix(1, 10);
    test_matrix.SetCols(10);
    EXPECT_EQ(10, test_matrix.GetCols());
    EXPECT_EQ(1, test_matrix.GetRows());
}

TEST(constructor, moveConstructor) {
    S21Matrix test_matrix(2, 2);
    test_matrix(0, 0) = 1;
    test_matrix(0, 1) = 2;
    test_matrix(1, 0) = 3;
    test_matrix(1, 1) = 4;
    S21Matrix other_matrix(std::move(test_matrix));
    EXPECT_EQ(2, other_matrix.GetRows());
    EXPECT_EQ(2, other_matrix.GetCols());
    double k = 1;
    for (int i = 0; i < other_matrix.GetRows(); i++) {
        for (int j = 0; j < other_matrix.GetCols(); j++) {
            EXPECT_DOUBLE_EQ(other_matrix(i, j), k++);
        }
    }
}

TEST(S21MatrixTest, CopyConstructorTest) {
    S21Matrix mat1(3, 3);
    mat1(0, 0) = 1;
    mat1(1, 1) = 2;
    mat1(2, 2) = 3;

    S21Matrix mat2(mat1);

    EXPECT_EQ(mat1(0,0), mat2(0,0));
}