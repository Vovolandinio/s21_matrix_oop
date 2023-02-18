### env
UNAME:=$(shell uname -s)

ifeq ($(UNAME), Linux)
D_ENV=__LINUX__
endif
ifeq ($(UNAME), Darwin)
D_ENV=__MAC_OS__
endif

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

### C++
CC=gcc
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
SOURCES_TEST=tests/test.cc
TEST_BINARY=s21_test
OBJECTS_TEST=$(SOURCES_TEST :%.c=%.o)
CPPFLAGS_TEST= -lgtest -lstdc++ -pthread


### gcov
GCOV=-coverage


vpath %.o $(OBJ_DIR)

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
	$(CC) $(CPPFLAGS) $(SOURCES_TEST) $(CPPFLAGS_TEST) $(STAT_LIBC_NAME) -o s21_test
	-./$(TEST_BINARY)

### coverage
gcov_report:CPPFLAGS += $(GCOV)
gcov_report: clean_test test
	./s21_test
	lcov -t "gcov_report" --no-external -o gcov_report.info -c -d ./
	genhtml -o report gcov_report.info;
	open ./report/index.html


clean_test:
	-@rm -f $(TEST_BINARY)

clean_s21_matrix_a:
	-@rm -f $(STAT_LIBC_NAME)
	-@rm -rf $(OBJ_DIR)


### open
open_html:
	$(OPEN) $(GCOV_DIR)/results/index.html