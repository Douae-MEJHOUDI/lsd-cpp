
#include <stdio.h>
#include <stdlib.h>

void print_nth_byte ( int n , int m) ;

int main()
{
    
    print_nth_byte(2,161616);
    return 0;
}

void print_nth_byte ( int n , int m) 
{
    for(int i = n*8 ;i>=(n-1)*8;i--)
    {
       if((m>>i)&1==1)
        printf("1");
       else
        printf("0");
    }
    printf("\n");
}

