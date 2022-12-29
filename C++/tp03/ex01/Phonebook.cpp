#include <stdio.h>
#include "Phonebook.hpp"

using namespace std;


Phonebook::Phonebook() 
{
	order = 0;
}

void Phonebook::ADD() 
{
	string first_name , last_name, nickname, number; 
	cin>>first_name>>last_name>>nickname>>number;
	contact C(first_name, last_name, nickname, number);
	if (order == 8) 
	{
		order = 0;
	}
	m_contact[order]= C; 
	order+=1;
}

void Phonebook::search() 
{
	cout<<"index|first name|last  name| nickname |"<<endl;
	cout<<"_____|__________|__________|__________|"<<endl;
	for (int i=0; i<8; i++)
	{
		m_contact [i].display_res(i);
	}
	
	cout<<"give contact's index to display: ";
	int index;
	cin>>index;
	while( index<0 or index>= 8)
	{
		cout<<"it's an invalid index, please give a valid one: ";
		cin>>index;
	}
	
	m_contact[index].display_full(index);
}


void Phonebook::exit()
{
	delete [] m_contact;
	m_contact = new contact[8];
	cout<<"the phonebook has been cleared"<<endl;
}

