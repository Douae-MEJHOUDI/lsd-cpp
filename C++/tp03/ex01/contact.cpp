#include <stdio.h>
#include "contact.hpp"

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

