////////NOT FINISHED YET 
#ifndef DEF_CLASS
#define DEF_CLASS



#include <iostream>
#include <string>
#include <ctime>
#include <vector>

class Shell
{
	private :
	Directory ROOTDIR;
	Directory BINDIR;
	public :
	Shell();
	
};
class File
{
	protected:
	std::string name;
	std::string location;
	std::string permission;
	std::time_t date;
	int type;
	public:
	File();
	//DelFile(std::string name);
};

class Directory : public File
{
	private :
	Directory *parent;
	std::vector <Directory> sub_directories;
	std::vector <TextFile> sub_textFiles;
	std::vector <ExecFile> sub_execFiles;
	public :
	Directory();
	//Cd(std::string name);
	//Find(std::string name);
	
	
	friend class File;
	friend Directory mkdir (string nom, Directory* current);
};

class TextFile : public File
{
	protected:
	std::string name_parent;
	public :
	TextFile();
	
	friend 
	friend class Directory ;
	
};

class ExecFile : public TextFile
{
	bool flag;
	ExecFile();
	 
};


#endif

