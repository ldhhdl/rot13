all: format check
	clang++ main.cpp -o rot13 -std=c++17 -Wall -Wextra -Wshadow
format:
	clang-format -i main.cpp
check:
	cppcheck main.cpp
clean:
	rm -vf rot13
