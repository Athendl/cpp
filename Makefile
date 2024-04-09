
all:
	g++ --std=c++11 HashedDictionary.cpp main.cpp -o test.exe

test:
	./test.exe
