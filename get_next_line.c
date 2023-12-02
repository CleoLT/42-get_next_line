/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:40:06 by ale-tron          #+#    #+#             */
/*   Updated: 2023/12/02 15:56:32 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_line(int fd, char *buf, char *stash)
{
	int		read_bytes;
//	char	*temp;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
//		if (read_bytes == 0)
//			break ;
		buf[read_bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		if (!stash)
			return (NULL);
//		temp = stash;
		stash = ft_strjoin(stash, buf);
//		free(temp);
//		temp = NULL;
		if (!stash)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (stash[0] == '\0')
		return (free(stash), NULL);
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
	if (result[0] == '\0')
		return (free(result), NULL);
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
//	buf[0] = '\0';
	line = read_line(fd, buf, stash);
	free(buf);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = extract(line);
	return (line);
}
