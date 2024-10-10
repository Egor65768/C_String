CC = gcc 
FLAGS = -Wall -Werror -Wextra 
STRING = *.c 
OBJECTS = *.o 
TEST_LIB = ./tests/*.c
BUILD_TEST = ./build.sh
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
LINK_FLAGS = -lcheck 
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux) 
	LINK_FLAGS += -lm -lsubunit
endif

all: rebuild gcov_report

s21_string.a:
	$(CC) $(FLAGS) -c $(STRING)
	ar rcs s21_string.a $(OBJECTS)

test: clean
	$(CC) $(FLAGS) $(LEAKS) $(STRING) ${TEST_LIB} ${LINK_FLAGS} -o test
	./test

test_docker: clean
	@sudo chmod +x $(BUILD_TEST)
	./$(BUILD_TEST)

leaks: test
ifeq ($(UNAME_S), Linux) 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
endif
ifeq ($(UNAME_S), Darwin) 
	leaks -quiet -atExit -- ./test
endif

clean: 
	rm -fr *.o *.gch *.gcno *.gcda test gcov_test s21_test.info ./report test

clean_lib:
	rm -rf *.a

rebuild: clean clean_lib s21_string.a 

gcov_report: 
	$(CC) $(FLAGS) $(GCOV_FLAGS) ${TEST_LIB} ${STRING} ${LINK_FLAGS} -o test
	./test
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open report/index.html	

style:
	clang-format -style=google -n tests/* ./*.c ./*.h

format:
	clang-format -style=google -i tests/* ./*.c ./*.h
