/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:44:57 by osukhore          #+#    #+#             */
/*   Updated: 2025/11/20 14:56:22 by osukhore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		count;
	int		line;

	if (fd == -1)
		return (NULL);
	while (line != 0)
	{
		line = read(fd, buf, BUFFER_SIZE);
		if (line == -1)
			return (NULL);
		buf[line] = '\0';
	}

}

int main(int argc, char **argv)
{
	int	fd;

	fd = open("path/to/file", O_RDONLY);


	close(fd);
}
