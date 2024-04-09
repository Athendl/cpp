
all:
	g++ --std=c++11 main.cpp Entry.cpp HashedEntry.cpp HashedDictionary.cpp -Wall -o a.out

test:
	./a.out
