#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	print_line(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
//	free(line);
	close(fd);
}

int	main(void)
{
	print_line("song.txt");
	return (0);
}
