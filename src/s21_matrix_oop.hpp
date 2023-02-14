#ifndef S21_MATRIX_OOP_S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_S21_MATRIX_OOP_H

Class S21Matrix {
public:
    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other) noexcept;
    ~S21Matrix();

private:
    int rows_, cols_;
    double** matrix_;
    void CreateMatrix_();
};

#endif //S21_MATRIX_OOP_S21_MATRIX_OOP_H
