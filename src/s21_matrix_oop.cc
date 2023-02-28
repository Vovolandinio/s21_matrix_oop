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
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = new double *[0];
}

S21Matrix::~S21Matrix() { RemoveMatrix_(); }

int S21Matrix::GetCols() const { return cols_; }

int S21Matrix::GetRows() const { return rows_; }

void S21Matrix::SetCols(const int &cols) {
  if (cols <= 0) {
    throw std::invalid_argument(
        "the values cannot be less than or equal to zero. ERROR!");
  }
  int tmp = cols_;
  cols_ = cols;
  S21Matrix newMatrix(rows_, cols);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (j >= tmp) {
        newMatrix(i, j) = 0;
      } else {
        newMatrix(i, j) = this->matrix_[i][j];
      }
    }
  }
  if (matrix_) {
    this->RemoveMatrix_();
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
  *this = newMatrix;
}

void S21Matrix::SetRows(const int &rows) {
  if (rows <= 0) {
    throw std::invalid_argument(
        "the values cannot be less than or equal to zero. ERROR!");
  }
  int tmp = rows_;
  rows_ = rows;
  S21Matrix newMatrix(rows, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i >= tmp) {
        newMatrix(i, j) = 0;
      } else {
        newMatrix(i, j) = this->matrix_[i][j];
      }
    }
  }
  if (matrix_ != nullptr) {
    this->RemoveMatrix_();
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
  *this = newMatrix;
}

/*
 * overload
 */

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double &number) {
  S21Matrix result(*this);
  result.MulNumber(number);
  return result;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double &number) {
  this->MulNumber(number);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this == &other) {
    return *this;
  }

  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }

  rows_ = other.rows_;
  cols_ = other.cols_;
  CreateMatrix_();

  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (matrix_[i] != nullptr) {
          this->matrix_[i][j] = other.matrix_[i][j];
        }
      }
    }
  }
  return *this;
}

double &S21Matrix::operator()(int row, int col) {
  if (row >= this->rows_ || col >= this->cols_ || row < 0 || col < 0) {
    throw std::invalid_argument("Index is outside the matrix ERROR!");
  }
  return this->matrix_[row][col];
}

/*
 * public
 */

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool result = true;
  if (this->rows_ != other.rows_ && this->cols_ != other.cols_) {
    result = false;
  } else {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) > 1e-6) {
          result = false;
        }
      }
    }
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (!EqSizeMatrix(other)) {
    throw std::invalid_argument("different matrix dimensions");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (!EqSizeMatrix(other)) {
    throw std::invalid_argument("different matrix dimensions");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (this->matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] *= num;
      }
    }
  } else {
    throw std::invalid_argument("The values cannot be null. ERROR!");
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (this->cols_ != other.rows_) {
    throw std::invalid_argument(
        "the number of columns of the first matrix is not equal to the number "
        "of rows of the second matrix. ERROR!");
  } else {
    S21Matrix result(this->rows_, other.cols_);
    for (int m = 0; m < this->rows_; m++) {
      for (int n = 0; n < other.cols_; n++) {
        result.matrix_[m][n] = 0;
        for (int k = 0; k < this->cols_; k++) {
          result.matrix_[m][n] += matrix_[m][k] * other.matrix_[k][n];
        }
      }
    }
    *this = result;
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  if (matrix_ && rows_ > 0 && cols_ > 0) {
    for (int i = 0; i < result.rows_; i++) {
      for (int j = 0; j < result.cols_; j++) {
        result.matrix_[i][j] = matrix_[j][i];
      }
    }
  }
  return *this = result;
}

double S21Matrix::Determinant() {
  double determinant = 0.0;
  if (rows_ == 1) {
    determinant = this->matrix_[0][0];
  } else {
    S21Matrix new_matrix(rows_ - 1, cols_ - 1);
    for (int j = 0; j < cols_; ++j) {
      for (int i = 1; i < rows_; ++i) {
        for (int k = 0; k < cols_; ++k) {
          if (k < j) {
            new_matrix.matrix_[i - 1][k] = matrix_[i][k];
          } else if (k > j) {
            new_matrix.matrix_[i - 1][k - 1] = matrix_[i][k];
          }
        }
      }
      determinant +=
          ((j % 2 == 0) ? 1 : -1) * matrix_[0][j] * new_matrix.Determinant();
    }
  }
  return determinant;
}

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_) {
    throw std::invalid_argument("The matrix is not square.");
  }

  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      S21Matrix temp_matrix(rows_ - 1, cols_ - 1);
      CropMatrix_(i, j, temp_matrix);
      double temp = temp_matrix.Determinant();
      result.matrix_[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * temp;
    }
  }
  return *this = result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = this->Determinant();
  if (fabs(det) < 1e-6) {
    throw std::invalid_argument("matrix determinant is 0.");
  }
  S21Matrix result = this->CalcComplements();
  result = result.Transpose();

  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      result.matrix_[i][j] = result.matrix_[i][j] / det;
    }
  }
  return result;
}

/*
 * private
 */

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

bool S21Matrix::EqSizeMatrix(const S21Matrix &other) const {
  if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
    return true;
  } else {
    return false;
  }
}

void S21Matrix::RemoveMatrix_() {
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

void S21Matrix::CropMatrix_(int del_row, int del_col, S21Matrix &other) {
  for (int i = 0; i < rows_; i++) {
    if (i == del_row) continue;
    for (int j = 0; j < cols_; j++) {
      if (j == del_col) continue;
      other.matrix_[i - (i > del_row)][j - (j > del_col)] = matrix_[i][j];
    }
  }
}
