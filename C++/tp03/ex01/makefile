#srcs= srcs/Phonebook.cpp srcs/contact.cpp
#files= Phonebook.cpp contact.cpp
#obj= Phonebook.o contact.o
#lib= libmylib.a
#all: libmylib
#libmylib: Phonebook.o contact.o
#	ar rcs $(lib) $(obj)
#Phonebook.o: Phonebook.cpp
#	g++ -c Phonebook.cpp -o Phonebook.o
#contact.o : contact.cpp
#	g++ -c contact.cpp -o contact.o 
#clean: $(obj)
#	-rm *.o
#fclean :$(lib) 
#	clean
#	-rm libmylib.a
	

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

