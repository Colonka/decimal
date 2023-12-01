FLAGS= -Wall -Wextra -Werror
STD= -std=c11
GCOVR= -fprofile-arcs -ftest-coverage

all: s21_decimal.a

style:
	clang-format -i -style=google *.c
	clang-format -style=google -n *.c

s21_decimal.a: s21_decimal s21_utils s21_checking s21_utils_extra
	ar rc libs21_decimal.a binary/*.o
	ranlib libs21_decimal.a

s21_decimal: s21_main_func.c s21_main_func.h
	mkdir -p binary
	cd binary && gcc ${FLAGS} ${STD} -c ../s21_main_func.c

s21_utils: utils/s21_utils.c utils/s21_utils.h
	cd binary && gcc ${FLAGS} ${STD} -c ../utils/s21_utils.c

s21_utils_extra: utils/s21_extra_utils.c utils/s21_utils.h
	cd binary gcc ${FLAGS} ${STD} -c ../utils/s21_extra_utils.c

s21_checking: checking/checking.c checking/checking.h
	cd binary && gcc ${FLAGS} ${STD} -c ../checking/checking.c

test: clean s21_decimal.a test.c
	cd binary && gcc ${FLAGS} ${STD} ${GCOVR} -c ../test.c
	gcc -L. -ls21_decimal binary/test.o -lcheck -lm -lpthread -o run_tests
	./run_tests

dvi: clean
	mkdir -p docs
	doxygen Doxyfile
	mv html latex docs
	open docs/html/index.html

docs:
	open docs/html/index.html

git: clean
	git add -A
	git commit -m "$m"
	git push origin "$b"

gcov_report: test
	mkdir -p report
	./run_tests
	gcovr --object-directory=binary
	gcovr -r . --html --html-details -o report/report.html
	open report/report.html

clean:
	rm -rf *.gcov *.gcno *.gcda run_tests binary docs