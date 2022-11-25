#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define MAX 1000
#define BUFFER_SIZE 1

static char stc[MAX] ;


////////PROTOTYPES :
void strjin (char* recep, char* string);
int check_endl(char* stc);
void read_file(int fd );
char* get_line ();
char* save_extra();
char* read_lines(int fd);


/*


void	memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	str = (char*)b;
	i = 0;
	while (i < len)
	{
		str[i] = (char)c;
		i++;
	}
	return (str);
}

int	strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


*/
