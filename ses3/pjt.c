#include "pjt.h"

////////MAIN :

int main()
{
    
    int fd = open("file.txt", O_RDONLY );
    ///printf("%d\n\n",fd);
    for(int i=0; i<5; i++)
    {
    	read_lines(fd);
    }
    return 0;
}


void strjin (char* recep, char* string)
{
	int n= strlen (string);
	int m=strlen (recep);
	for (int i=0;i<n;i++)
		recep[m+i]=string[i];
	return ;
}

int check_endl(char* stc)
{
	int i=0;
	while (stc[i] != '\0')
	{
		if (stc[i] == '\n')
			return 1;
		i++;
	}
	return 0;
}

void read_file(int fd)
{

	int k;
	void* buffer= (char*)malloc((BUFFER_SIZE+1) * sizeof(char));
	while(k=read(fd,buffer,BUFFER_SIZE) != 0)
	{
		if (k == -1)
		{
			free(buffer);
			exit(EXIT_FAILURE);
		}
		strjin(stc,buffer);
		if(check_endl(stc))
			break;
	}
	return ;
}

char* get_line ()
{
	int n=0;
	while (stc[n] != '\n' && stc [n] != '\0')
		n++;
	if (stc[n] == '\n')
		n++;
	char* line =(char*)malloc(sizeof(char) *(n+1));
	for(int i=0;i<n;i++)
	{
		line[i] = stc[i] ;
	}
	line [n]='\0';
	return line;
}

char* save_extra() 
{
	int n=0, m=1;
	while (stc[n] != '\0' )
		n++;
	while (stc[m] != '\n' )
		m++;
	int size= n-m+1 ;
	char* extra = (char*)malloc (sizeof(char) * size );
	for (int i=0; i<size-1 ; i++)
		extra[i]= stc[i+m+1];
	extra[size-1] = '\0';
	return extra;
}

char* read_lines(int fd)
{
	read_file (fd);
	if (stc == NULL)
		return NULL;
	char* line = get_line(stc);
	char* extra= save_extra(stc);
	
	int i=0;
	while ( line[i] !='\0')
	{
		printf("%c", line[i]);
		i++;
	}

	memset(stc,0,strlen(stc));
	int j=0;
	while( extra [j]!= '\0')
	{
		stc[j] = extra [j];

		j++;
	}
	
	//free(extra);
	//free(line);
	
	return line;
	
}
