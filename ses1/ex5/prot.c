#include <stdio.h>
#include <stdlib.h>

void check_msb(int num)
{
    int nb_bits= sizeof(int)*8 ;
    int test= num>> (nb_bits-1) ;
    if (test&1)
    {
        printf("msb is set");
    }
    else 
        printf("msb is not set");
    return ;
}


void print_bits ( unsigned char byte)
{
    for(int i =sizeof(unsigned char)*8-1 ;i>=0;i--)
    {
       if((byte>>i)&1==1)
        printf("1");
       else
        printf("0");
    }
    printf("\n");
}
