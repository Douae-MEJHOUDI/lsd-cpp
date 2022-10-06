srcs= srcs/ex1.c srcs/ex2.c
files= ex1.c ex2.c
obj= ex1.o ex2.o
lib= libmylib.a
all: libmylib
libmylib: ex1.o ex2.o
	ar rcs $(lib) $(obj)
exercice1.o: ex1.c
	gcc -c ex1.c -o ex1.o
exercice2.o : ex2.c
	gcc -c ex2.c -o ex2.o 
clean: $(obj)
	-rm * .o
fclean :$(lib) 
	clean
	-rm libmylib.a
