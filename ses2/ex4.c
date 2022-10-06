#include <stdio.h>
#include <stdlib.h>
#define N 20

int main()
{
	int* y=(int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++)
	{
		*(y+i)=i;
	}
	
	for(int i=0;i<N;i++)
	{
		printf("%d ",*(y+i));
	}
	return 0;
}
