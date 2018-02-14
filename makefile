flags = -fmessage-length=50 -std=c++14 -fpermissive
DEPS = ai.hpp row.hpp
OBJ = row.o ai.o connect4.o
CC=clang++

all: connect4

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(flags)

connect4: $(OBJ) 
	$(CC) $^ -I . $(flags) -o $@

clean:
	rm *.hpp.gch
	rm *.o
