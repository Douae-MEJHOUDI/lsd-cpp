obj= main.o class.o

all: $(obj)
	g++ -o main $(obj)
class.o: class.cpp class.hpp
	g++ -c class.cpp
main.o: main.cpp
	g++ -c main.cpp
clean: $(obj)
	-rm *.o
