/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:40:06 by ale-tron          #+#    #+#             */
/*   Updated: 2023/11/24 08:41:22 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_line(int fd, char *buf, char *stash)
{
//	char	*line  ;
	int	read_bytes;
	char	*temp;
	
//	stash = ft_strdup("");
	read_bytes = 1;
	while (read_bytes)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
			return (NULL);
		if (read_bytes == 0)
			break;
		buf[read_bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break;
		
//		free(buf);
	}
	return (stash);
}


char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	char		*line;

	if ((fd < 0) | (BUFFER_SIZE == 0))
		return (NULL);
	buf = malloc(sizeof(char*) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
//	stash = ft_strdup("");
	line = read_line(fd, buf, stash);
	free(buf);
	return (line);
}
