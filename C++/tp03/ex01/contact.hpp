#ifndef DEF_CONTACT
#define DEF_CONTACT


#include <string>
#include <iostream>

class contact
{
	private:
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_number;
	
	public:
	contact ();
	contact(std::string first_name,std::string last_name, std::string nickname, std::string phone_number);
	void display_full( int i);
	void display_res( int i);
	
};


#endif
