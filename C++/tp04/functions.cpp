////////////NOT FINISHED YET

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;



Directory mkdir (string nom, Directory* current)
{
	Directory dir;
	parent->sub_directories.push_back(dir);
	dir.name = nom; 
	dir.location = parent->location + "/" +parent->name ;
	
	return dir;
	
}

TextFile touch_t ( string nom, Directory* current)
{
	TextFile t;
	t.name = nom; 
	t.location = current->location + "/" + current->name;
	current->sub_textFiles.push_back(t);
	t.name_parent = current->name;
	
	return t;

}

ExecFile touch_e ( string nom, Directory* current)
{
	ExecFile e;
	e.name = nom; 
	e.location = current->location + "/" + current->name;
	current->sub_textFiles.push_back(e);
	//t.name_parent = current->name;
	e.flag = FALSE;
	
	return t;

}

//bool rm (string nom, Directory 
