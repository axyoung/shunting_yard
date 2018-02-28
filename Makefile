PROGRAM = main.exe
CXXFLAGS = -Wall -g

$(PROGRAM): main.o Node.o
	g++ -o $@ $^

clean:
	rm -f $(PROGRAM) *.o

run: $(PROGRAM)
	./$(PROGRAM)

main.o: main.cpp Node.h
Node.o: Node.cpp Node.h

