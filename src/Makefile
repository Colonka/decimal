CHECK_FLAGS = $(shell pkg-config --libs check --cflags)

FLAGS= -Wall -Wextra -Werror
STD= -std=c11
GCOVR= -fprofile-arcs -ftest-coverage

all: s21_decimal.a

style:
	clang-format -i -style=google *.c
	clang-format -style=google -n *.c

s21_decimal.a: s21_decimal s21_utils
	ar rc libs21_decimal.a binary/*.o
	ranlib libs21_decimal.a

s21_decimal: s21_main_func.c s21_main_func.h
	mkdir -p binary
	cd binary && gcc ${FLAGS} ${STD} ${GCOVR} -c ../s21_main_func.c

s21_utils: utils/s21_utils.c utils/s21_extra_utils.c utils/s21_utils.h
	cd binary && gcc ${FLAGS} ${STD} -c ../utils/*.c

test: test.c
	mkdir -p binary
	cd binary && gcc ${FLAGS} ${STD} ${GCOVR} -c ../test.c
	gcc -L. -ls21_decimal binary/test.o ${GCOVR} $(CHECK_FLAGS) -o run_tests
	./run_tests

dvi: clean
	mkdir -p docs
	doxygen Doxyfile
	mv html latex docs
	open docs/html/index.html

git: clean_for_git
	git add -A
	git commit -m "$m"
	git push origin "$b"

gcovr_report: test
	mkdir -p report
	./run_tests
	gcov -f *.gcno
	gcovr -r. --html --html-details -o report/report.html
	open report/report.html

clean:
	rm -rf *.gcov *.gcno *.gcda run_tests binary docs *.o *.a

clean_for_git:
	rm -rf run_tests binary report docs