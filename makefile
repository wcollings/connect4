flags=-fmessage-length=50 -w -std=c++14

all: connect4.cc row ai
	clang++ connect4.cpp row.cpp ai.cpp $(flags) -o c4

row: row.hpp
	clang++ row.hpp $(flags)

ai:ai.hpp
	clang++ ai.hpp $(flags)

cleanup:
	rm *.hpp.gch
	rm *.o