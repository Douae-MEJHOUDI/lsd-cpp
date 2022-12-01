#include <iostream>
#include <vector> 

#define ct 5


using namespace std;

using matrix= vector<vector<int>>;


/////////////Prototypes:
matrix initialize (int n,int val);
matrix multiply (matrix a, matrix b);
template <typename T>
T powrec(T a, int n);
void show_matrix (matrix a);
matrix poww(matrix a);

////////////////Main:
int main()
{
    int n=4;
    matrix a = initialize(n,2);
    //matrix b = initialize(n,3);
    show_matrix(a);
    cout<<endl;
    //show_matrix(b);
    //show_matrix(multiply(a,b));
    matrix c = powrec(a, 3);
    show_matrix(c);
    return 0;
}

////////////////Functions:

matrix initialize (int n,int val)
{
    matrix a (n);
    for (int i = 0; i<n; i++)
    {
        a[i]= vector <int> (n,val);
    }
    return a;
}

void show_matrix (matrix a)
{
    int n = a.size();
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            cout << a[i][j] << " ";
        }    
        cout << endl;
    }
}

matrix multiply (matrix a, matrix b)
{
    int n= a.size();
	matrix c= initialize(n,0);
	for(int i=0; i<n;i++)
	{
		for(int j=0; j<n;j++)
		{
			for(int k=0; k<n ; k++)
			    c[i][j]+= a[i][k] * b[k][j];
		}
	}
	return c;
}
matrix poww(matrix a)
{
    return multiply(a,a);
}

template <typename T>
T powrec(T a, int n)
{
    if(n==1)
        return a;
    if (n%2 == 0)
        return poww(powrec(a,n/2));
    return multiply(a,poww(powrec(a,n/2)));
}


