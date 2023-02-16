#!/bin/bash

cp ../linters/.clang-format .

clang-format -i s21_matrix_oop.hpp  s21_matrix_oop.cc

rm .clang-format