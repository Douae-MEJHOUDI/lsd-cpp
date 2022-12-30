obj= main.o contact.o Phonebook.o
all: main

main: $(obj)
	g++ -o main $(obj)
contact.o: contact.cpp contact.hpp
	g++ -c contact.cpp
Phonebook.o: Phonebook.cpp Phonebook.hpp contact.cpp contact.hpp
	g++ -c Phonebook.cpp contact.cpp
main.o: main.cpp
	g++ -c main.cpp
clean: $(obj)
	-rm *.o

