/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:40:06 by ale-tron          #+#    #+#             */
/*   Updated: 2023/11/30 16:51:29 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_line(int fd, char *buf, char *stash)
{
	int		read_bytes;
	char	*temp;

	read_bytes = 1;
	while (read_bytes)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
			return (NULL);
		buf[read_bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buf);
		if (!stash)
			return (NULL);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

char	*extract(char *line)
{
	char	*result;
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	result = ft_substr(line, i + 1, ft_strlen(line));
	if (!result)
		return (NULL);
	line[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	char		*line;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buf = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = read_line(fd, buf, stash);
	free(buf);
	if (*line == '\0' || line == NULL)
		return (NULL);
	stash = extract(line);
	return (line);
}
