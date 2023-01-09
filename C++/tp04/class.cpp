#include "class.hpp"

using namespace std; 

Shell::Shell()
{
	ROOTDIR.name = "home";
	ROOTDIR.location = "/";
	BINDIR.name = "bin";
	
}

File::File()
{
	location = "/home";
	permission = "rw-rw-rw-";
	date = time(0);
}

Directory::Directory( )	{
	type = 0;
}

TextFile::TextFile() 
{
	type=1;
}

ExecFile::execFile ()
{
	type=2;
}

