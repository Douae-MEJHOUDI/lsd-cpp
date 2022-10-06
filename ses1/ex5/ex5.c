#include <stdio.h>
void check_msb(int);
void  print_bits(unsigned char);

int main()
{
    int num = 2147483648;
    check_msb(num);
    printf("\n");
    unsigned char byte =255;
    print_bits(byte);
    return 0;
}
/*
 the commands to generate a library in this example (and execute ) :
   gcc -c prot.c -o prot.o (generate an object file .o from prot.c)
   ar rcs -o prot.a prot.o (generate an archive fila .a from prot.o)
   gcc ex5.c -L. prot.o (compile the file ex5.c with attached library prot.o)
   ./a.out (execute)
   
*/
 
