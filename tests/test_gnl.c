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
	free(line);
	close(fd);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (i++ < 10) 
			print_line(argv[1]);
	}
	return (0);
}
