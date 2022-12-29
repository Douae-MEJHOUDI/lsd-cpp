#include <iostream>
#include <string>

#include "contact.hpp"
#include "Phonebook.hpp"

using namespace std;

int main()
{
	string end= "ok";
	Phonebook P;
	cout<<"Hi dear user"<<endl;
	do
	{
		int action;
		cout<<"Please print\n 1 -> To add new contact to the phonebook \n 2 -> To search a contact \n 3 -> To clear the phonebook "<<endl;
		cin>>action;
		switch (action)
		{
			case 1: 
				P.ADD();
				break;
			case 2:
				P.search();
				break;
			case 3:
				P.exit();
				exit(EXIT_SUCCESS);
				break;
			default:
				cout<<"This is an invalid option "<<endl;
				break;
		}
		cout<<"if u wanna quit print EXIT, otherwise print anything else: ";
		cin>>end;
	}while(end != "EXIT");
	return 0;
}
