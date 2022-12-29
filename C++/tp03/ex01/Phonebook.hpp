#ifndef DEF_PHONEBOOK
#define DEF_PHONEBOOK

#include <new>
#include <iostream>
#include "contact.hpp"


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
