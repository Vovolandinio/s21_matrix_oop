#!/bin/bash

cp ../linters/.clang-format .

clang-format -n s21_matrix_oop.hpp  s21_matrix_oop.cc tests/*.cc

rm .clang-format