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

TEST(constructor, setGreaterRowD) {
    S21Matrix test_matrix(5, 10);
    test_matrix.SetRows(30);
    EXPECT_EQ(30, test_matrix.GetRows());
    EXPECT_EQ(10, test_matrix.GetCols());
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

