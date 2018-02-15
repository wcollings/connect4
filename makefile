flags = -fmessage-length=50 -std=c++11 -fpermissive
DEPS = row.hpp ai.hpp
OBJ = row.o ai.o connect4.o
CC=clang++

all: connect4

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(flags)

connect4: $(OBJ) 
	$(CC) $^  $(flags) -o $@

clean:
	rm *.hpp.gch
	rm *.o
