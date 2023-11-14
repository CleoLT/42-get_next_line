#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;

	line = "hola hihihi\n";	
	read(fd, line, BUFFER_SIZE); 
	return (line);
}
