#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
T powiter(T a, int n)
{
	T res= 1;
	while (n >0)
	{
		if (n%2 == 0)
		{
			n=n/2;
			a=a*a;
		}
		else 
		{
			n=n-1;
			res=res*a;
			n=n/2;
			a=a*a;
		}
	}
	return res;
}

template <typename T>

T powrec(T a, int n)
{
    if(n==1)
        return a;
    if (n%2 == 0)
        return pow(powrec(a,n/2),2);
    return a*pow(powrec(a,n/2),2);
}

int main()
{
    cout << powrec(7,5)<<endl;
    cout << powiter(7,5)<<endl;
    return 0;
}

