#include "s21_matrix_oop.hpp"

S21Matrix::S21Matrix() {
    this->cols_(5);
    this->rows_(5);
    CreateMatrix_();
}

S21Matrix::S21Matrix(int rows, int cols) {
    this->rows_ = rows;
    this->cols_ = cols;
    this->matrix_(nullptr);
    CreateMatrix_();
}

S21Matrix::S21Matrix(const S21Matrix& other) {
    this->cols_ = other.cols_;
    this->rows_ = other.rows_;
    CreateMatrix_();
    for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
            this->matrix_[i][j] = other.matrix_[i][j];
        }
    }
}


void S21Matrix::CreateMatrix_() {
    if (rows_ <= 0 || cols_ <= 0) {
        throw std::invalid_argument(
                "the values cannot be less than or equal to zero. ERROR!");
    }
    matrix_ = new double*[rows_];
    for (int i = 0; i < this->rows_; i++) {
        matrix_[i] = new double[cols_];
    }
    for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
            matrix_[i][j] = 0;
        }
    }
}