#ifndef S21_MATRIX_OOP_S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_S21_MATRIX_OOP_H
#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  int GetRows() const noexcept;
  int GetCols() const noexcept;
  void SetRows(const int& rows);
  void SetCols(const int& cols);

  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double& number) const;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double& number);
  S21Matrix& operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other) const noexcept;
  double& operator()(int row, int col);

  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  double Determinant() const;
  bool EqMatrix(const S21Matrix& other) const;
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

 private:
  int rows_, cols_;
  double** matrix_;
  void CreateMatrix_();
  void RemoveMatrix_();
  bool EqSizeMatrix(const S21Matrix& other) const noexcept;
  void CropMatrix_(int rows, int cols, S21Matrix& other) const;
};

#endif  // S21_MATRIX_OOP_S21_MATRIX_OOP_H
