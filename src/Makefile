### env
UNAME:=$(shell uname -s)

ifeq ($(UNAME), Linux)
D_ENV=__LINUX__
endif
ifeq ($(UNAME), Darwin)
D_ENV=__MAC_OS__
endif

### C++
CC=gcc
STAT_LIBC_BUILD=ar rcs

### s21_matrix_oop.a
STAT_LIBC_NAME=s21_matrix_oop.a
CFLAGS=-Wall -Wextra -Werror -g -D$(D_ENV)
HEADERS=s21_matrix_oop.hpp
SOURCES=s21_matrix_oop.cc

#DIRECTORY
OBJ_DIR=./objects

## tests
SOURCES_TEST=test_matrix_oop.cc
OBJECTS_TEST=$(SOURCES_TEST :%.c=%.o)
CFLAGS_TEST=$(CFLAGS) $(shell pkg-config --cflags check) -g
CLIBS_TEST=-lcheck $(shell pkg-config --libs check)

### gcov
GCOV_NAME=gcov_report_tests.exe
INFO_GCOV=gcov_report_tests.info
GCOV_DIR=tests_coverage
CFLAGS_GCOV=$(CFLAGS_TEST) -fprofile-arcs -ftest-coverage
CLIBS_GCOV=$(CLIBS_TEST)

### memory leaking
ifeq ($(UNAME), Linux)
LEAKS_CHECKING=valgrind -q --track-origins=yes --tool=memcheck --leak-check=full ./$(TESTS_NAME) ./$(STAT_LIBC_NAME) ./$(GCOV_NAME)
endif
ifeq ($(UNAME), Darwin)
LEAKS_CHECKING=CK_FORK=no leaks --atExit -- ./$(TESTS_NAME) ./$(STAT_LIBC_NAME) ./$(GCOV_NAME)
endif

### open
ifeq ($(UNAME), Linux)
OPEN=xdg-open
endif
ifeq ($(UNAME), Darwin)
OPEN=open
endif

### make

.PHONY: all clean gcov_report test html_rebuild check_rebuild

all: clean s21_matrix_oop.a

html_rebuild: clean gcov_report
test_rebuild: clean test

### build
$(SOURCES_TEST): $(TESTS_CHECK)
	checkmk $(TESTS_CHECK) > $(SOURCES_TEST)

%.o: %.cc $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $(addprefix $(OBJ_DIR)/, $@)

### build s21_matrix.a
$(STAT_LIBC_NAME): $(OBJECTS)
	$(STAT_LIBC_BUILD) $(STAT_LIBC_NAME) $(OBJECTS)

### test
test: $(SOURCES_TEST)
	$(CC) $(CFLAGS_TEST) $(SOURCES) $(SOURCES_TEST) -o $(TESTS_NAME) $(CLIBS_TEST)
	-./$(TESTS_NAME)

### coverage
gcov_report: $(SOURCES) $(SOURCES_TEST)
	$(CC) $(SOURCES) $(SOURCES_TEST) -o $(GCOV_NAME) $(CFLAGS_TEST) $(CLIBS_TEST) --coverage
	-./$(GCOV_NAME) -lcov
	-mkdir $(GCOV_DIR)
	lcov -c -d . -o $(GCOV_DIR)/$(INFO_GCOV)
	genhtml -o $(GCOV_DIR)/results/ $(GCOV_DIR)/$(INFO_GCOV)

### clean
 clean_gcov_report:
	-@lcov -z -d .
	-@rm -f $(GCOV_NAME)

clean_test:
	-@rm -f $(SOURCES_TEST)

clean_s21_matrix_a:
	-@rm -f $(STAT_LIBC_NAME)

clean: clean_gcov_report clean_test clean_s21_matrix_a
	-@rm -rf $(GCOV_DIR)
	-@rm -f *.o
	-@rm -f *.gcda
	-@rm -f *.gcno
	-@rm -f *.exe
	-@rm -f *.cfg

### open
open_html:
	$(OPEN) $(GCOV_DIR)/results/index.html