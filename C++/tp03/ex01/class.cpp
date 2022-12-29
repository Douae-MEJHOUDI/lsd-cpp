#include <stdio.h>
#include "class.hpp"

using namespace std;

contact::contact()
{
}

contact::contact(string first_name,string last_name, string nickname, string phone_number): m_first_name(first_name), m_last_name(last_name), m_nickname(nickname), m_number(phone_number) 
{
}

void contact::display_res( int i)
{
	string extr="          ";
	printf("  %d  |%.10s|%.10s|%.10s|\n",i,(m_first_name+extr).c_str(),(m_last_name+extr).c_str(),(m_nickname+extr).c_str());
}

void contact::display_full(int i)
{
	printf("index:%d \nfirst name: %s \nlast name: %s \nnickname: %s \nphone number: %s\n",i,m_first_name.c_str(),m_last_name.c_str(),m_nickname.c_str(),m_number.c_str());
	
}

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
















