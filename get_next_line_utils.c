/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:21:38 by ale-tron          #+#    #+#             */
/*   Updated: 2023/11/04 18:21:40 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = (char *)malloc(sizeof(char) * len);
	if (string == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		string[i + j] = s2[j];
		j++;
	}
	string [i + j] = '\0';
	return (string);
}

char	*ft_strchr(char *s, int c)
{
	char	ch;
	int		i;

	ch = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return (s + i);
		i++;
	}
	if (ch == '\0')
		return (s + i);
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen(s1) + 1;
	ptr = (char *)malloc(len * sizeof(*ptr));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}
