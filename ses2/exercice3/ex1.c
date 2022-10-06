#include <stdio.h>

void check_msb(int num);

int main()
{
    int num = 2147483648;
    check_msb(num);

    return 0;
}


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
