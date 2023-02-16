#include "s21_matrix_oop.hpp"

S21Matrix::S21Matrix() {
  this->cols_ = 5;
  this->rows_ = 5;
  this->matrix_ = nullptr;
  CreateMatrix_();
}

S21Matrix::S21Matrix(int rows, int cols) {
  this->rows_ = rows;
  this->cols_ = cols;
  CreateMatrix_();
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  this->cols_ = other.cols_;
  this->rows_ = other.rows_;
  CreateMatrix_();
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
  std::swap(matrix_, other.matrix_);
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
}

S21Matrix::~S21Matrix() { RemoveMatrix_(); }

int S21Matrix::GetCols() const { return cols_; }

int S21Matrix::GetRows() const { return rows_; }

double **S21Matrix::GetMatrix() { return matrix_; }

void S21Matrix::SetCols(const int &cols) {
    if (cols <= 0) {
        throw std::invalid_argument(
                "the values cannot be less than or equal to zero. ERROR!");
    }
    S21Matrix newMatrix(rows_, cols);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            if (j > cols_ - 1) {
                newMatrix.GetMatrix()[i][j] = 0;
            } else {
                newMatrix.GetMatrix()[i][j] = this->matrix_[i][j];
            }
        }
    }
    this->RemoveMatrix_();
    *this = newMatrix;
}

void S21Matrix::CreateMatrix_() {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::invalid_argument(
        "the values cannot be less than or equal to zero. ERROR!");
  }
  matrix_ = new double *[rows_];
  for (int i = 0; i < this->rows_; ++i) {
    matrix_[i] = new double[cols_];
  }
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      matrix_[i][j] = 0;
    }
  }
}

void S21Matrix::RemoveMatrix_() {
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}



S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
        rows_ = other.rows_;
        cols_ = other.cols_;
        CreateMatrix_();
        if (matrix_ != nullptr) {
            for (int i = 0; i < rows_; i++) {
                for (int j = 0; j < cols_; j++) {
                    this->matrix_[i][j] = other.matrix_[i][j];
                }
            }
        }
    return *this;
}