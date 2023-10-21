all: format
	clang++ main.cpp -o rot13
format:
	clang-format -i main.cpp
clean:
	rm -vf rot13
