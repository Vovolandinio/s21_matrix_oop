### env
UNAME:=$(shell uname -s)

ifeq ($(UNAME), Linux)
D_ENV=__LINUX__
endif
ifeq ($(UNAME), Darwin)
D_ENV=__MAC_OS__
endif

### memory leaking
#ifeq ($(UNAME), Linux)
#LEAKS_CHECKING=valgrind -q --track-origins=yes --tool=memcheck --leak-check=full ./$(TEST_BINARY)
#endif
#ifeq ($(UNAME), Darwin)
#LEAKS_CHECKING=CK_FORK=no leaks --atExit -- ./s21_test
#endif

### open
ifeq ($(UNAME), Linux)
OPEN=xdg-open
endif
ifeq ($(UNAME), Darwin)
OPEN=open
endif

ifeq ($(UNAME), Linux)
CPPFLAGS_TEST= -lgtest -lpthread -fprofile-arcs -ftest-coverage
endif
ifeq ($(UNAME), Darwin)
CPPFLAGS_TEST= -lgtest -lstdc++ -pthread -fprofile-arcs -ftest-coverage
endif

### C++
CC=g++
STAT_LIBC_BUILD=ar rcs

### s21_matrix_oop.a
STAT_LIBC_NAME=s21_matrix_oop.a
CPPFLAGS=-Wall -Wextra -Werror -g -D $(D_ENV)
HEADER=s21_matrix_oop.hpp
SOURCES=s21_matrix_oop.cc
OBJ=$(notdir $(SOURCES:.cc=.o))

#DIRECTORY
OBJ_DIR=./objects

## tests
SOURCES_TEST=tests/*.cc
TEST_BINARY=s21_test
OBJECTS_TEST=$(SOURCES_TEST :%.c=%.o)

### gcov
GCOV=-coverage
GCOV_DIR=./gcov_report

### make

.PHONY: all clean s21_matrix_oop.a

all: s21_matrix_oop.a

%.o: %.cc $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $(addprefix $(OBJ_DIR)/, $@)

s21_matrix_oop.a: $(OBJ) $(HEADERS)
	$(STAT_LIBC_BUILD) $@ $(addprefix $(OBJ_DIR)/, $(OBJ))
	ranlib $@

### test
test: s21_matrix_oop.a
	fsanitize=address $(CC) $(CPPFLAGS) $(SOURCES_TEST) $(CPPFLAGS_TEST) $(STAT_LIBC_NAME) -o $(TEST_BINARY) -fprofile-arcs -ftest-coverage -lgcov
	./$(TEST_BINARY)
	-@rm -f *.gcda
	-@rm -f *.gcno

### coverage
gcov_report:FLAGS += $(GCOV)
gcov_report: fclean test
	./s21_test
	lcov -t "gcov_report" --no-external -o gcov_report.info -c -d ./
	genhtml -o report gcov_report.info;
	open ./report/index.html

valgrind: test
ifeq ($(UNAME), Linux)
	valgrind --leak-check=full ./s21_test
else
	CK_FORK=no leaks --atExit -- ./s21_test
endif

check_style:
	sh check_style.sh

clean_test: clean_s21_matrix_a
	-@rm -f $(TEST_BINARY)

clean_s21_matrix_a:
	-@rm -f $(STAT_LIBC_NAME)
	-@rm -rf $(OBJ_DIR)
	-@rm -rf $(TEST_BINARY).dSYM

fclean: clean_test clean_s21_matrix_a
	-@rm -f *.gcda
	-@rm -f *.gcno
	-@rm -f *.info
	-@rm -rf report

### open
open_html:
	$(OPEN) $(GCOV_DIR)/results/index.html