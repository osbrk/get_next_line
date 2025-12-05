/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:44:57 by osukhore          #+#    #+#             */
/*   Updated: 2025/12/05 16:03:09 by osukhore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clear_all(char *buf, char *placeholder)
{
	if (buf != NULL)
		free(buf);
	if (placeholder != NULL)
		free(placeholder);
	return (NULL);
}

static char	*read_into_placeholder(int fd, char *placeholder)
{
	char	*buf;
	ssize_t	bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	bytes = 1;
	while (ft_strchr(placeholder, '\n') == NULL && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (clear_all(buf, placeholder));
		buf[bytes] = '\0';
		if (bytes == 0)
			break ;
		placeholder = ft_strjoin(placeholder, buf);
		if (placeholder == NULL)
			return (clear_all(buf, NULL));
	}
	free(buf);
	return (placeholder);
}

static char	*extract_line(char *placeholder)
{
	size_t	i;

	if (placeholder == NULL || placeholder[0] == '\0')
		return (NULL);
	i = 0;
	while (placeholder[i] && placeholder[i] != '\n')
		i++;
	if (placeholder[i] == '\n')
		i++;
	return (ft_substr(placeholder, 0, i));
}

static char	*update_placeholder(char *placeholder)
{
	size_t	i;
	char	*next;

	if (placeholder == NULL)
		return (NULL);
	i = 0;
	while (placeholder[i] && placeholder[i] != '\n')
		i++;
	if (placeholder[i] == '\0')
	{
		free(placeholder);
		return (NULL);
	}
	i++;
	next = ft_substr(placeholder, i, ft_strlen(placeholder + i));
	free(placeholder);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*placeholder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	placeholder = read_into_placeholder(fd, placeholder);
	if (placeholder == NULL)
		return (NULL);
	line = extract_line(placeholder);
	placeholder = update_placeholder(placeholder);
	return (line);
}
