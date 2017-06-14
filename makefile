all: make run

make: 
	g++ main.cpp -std=c++11 -o main

run: make
	./main 1000 2000 5000 10000 50000 100000 500000 1000000