/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:44:57 by osukhore          #+#    #+#             */
/*   Updated: 2025/11/26 14:49:36 by osukhore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static int	call_count;
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	int			line;
	int			nl_index;
//Check line
//Control read
//Double check buf and the rest
//Declare buffer
	call_count = 0;
	if (fd == -1)
		return (NULL);
	while (line != 0)
	{
		line = read(fd, buf, BUFFER_SIZE);
		if (line == -1)
			return (NULL);
		buf[line] = '\0';
	}
	//Here we check for nl
	nl_index = ft_strnl(buf);
	//if nl_index == NULL, we can move to placeholder
	//else - ft_split at /n?

	//Here we move buf to placeholder
	call_count++;
	ft_pustr(str);
}

int main(int argc, char **argv)
{
	int	fd;

	fd = open("path/to/file", O_RDONLY);


	close(fd);
}
