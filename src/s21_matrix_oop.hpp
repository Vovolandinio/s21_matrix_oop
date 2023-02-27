#ifndef S21_MATRIX_OOP_S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_S21_MATRIX_OOP_H
#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other) noexcept;
  ~S21Matrix();

  int GetRows() const;
  int GetCols() const;
  void SetRows(const int &rows);
  void SetCols(const int &cols);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  double Determinant();
  bool EqMatrix(const S21Matrix &other);
  S21Matrix CalcComplements();

  bool operator==(const S21Matrix &other);
  S21Matrix &operator=(const S21Matrix &other);
  double &operator()(int row, int col);

 private:
  int rows_, cols_;
  double **matrix_;
  void CreateMatrix_();
  void RemoveMatrix_();
  bool EqSizeMatrix(const S21Matrix &other) const;
  void CropMatrix_(int rows, int cols, S21Matrix &other);
};

#endif  // S21_MATRIX_OOP_S21_MATRIX_OOP_H
