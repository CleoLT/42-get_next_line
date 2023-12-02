#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	print_lines(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	line = " ";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_lines(argv[1]);
//	get_next_line(78);
//	get_next_line(0);
	return (0);
}
