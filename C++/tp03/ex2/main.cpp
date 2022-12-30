#include "class.hpp"

#include <iostream>

using namespace std;

int main()
{
	float h=5 , w= 2;
	Triangle A(w,h);
	Rectangle B(w,h);
	cout<<"width = "<<w<<", height= "<<h<<endl;
	cout<<"Triange's area: "<<A.area()<<endl;
	cout<<"Rectangle's area: "<<B.area()<<endl;
	return 0;
}
