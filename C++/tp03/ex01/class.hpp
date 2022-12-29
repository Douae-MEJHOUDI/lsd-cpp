#ifndef DEF_CLASS
#define DEF_CLASS


#include <string>
#include <new>
//using namespace std;


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

class Phonebook
{
	private:
	int order;
	contact* m_contact= new contact[8];
	
	public:
	Phonebook();
	void ADD();
	void search();
	void exit();
};

#endif
