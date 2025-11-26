/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:44:57 by osukhore          #+#    #+#             */
/*   Updated: 2025/11/26 15:47:15 by osukhore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	int			line;
	char		*placeholder;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	while (line != 0)
	{
		line = read(fd, buf, BUFFER_SIZE);
		if (line == -1)
			return (NULL);
		buf[line] = '\0';
	}
	if (ft_strnl(buf) == NULL)
		str = ft_strjoin(str, buf);
	else
	{
		placeholder = ft_substr(buf, 0, (ft_strnl(buf)));
		str = ft_strjoin(str, placeholder);
	}
	if (placeholder)
		free(placeholder);
	if (line == 0)
		return(str);
}

//How do I know when to continue with the next line?

#include <stdio.h>
static	void style(char style)
{
	//BLUE
	if (style == 'B')
		printf("\e[34m");
	//ERROR
	else if(style == 'E')
		printf("\e[1;31;7m");
	//TITLE
	else if(style == 'T')
		printf("\e[1;7m");
	//RESET TO BLACK
	else if(style == 'R')
		printf("\e[0m\n");
}

int main(int argc, char **argv)
{
	int		fd;
	int		fd_argv;
	char	**str;
	char	*argv_str;
	int		i;
	int		lines_to_print;

	lines_to_print = 10;

	//ERROR CHECK
	if (argc < 2)
	{
		printf("\n--------------------------------------------\n");
		style('E');
		printf("INPUT ");
		style('R');
		style('T');
		printf("Need ARGV to work with: \n\n"
			" 1. String \n");
		style('R');
		printf("--------------------------------------------\n");
		return (0);
	}

	//FILE NAME
	style('T');
	printf("\n ft_printft.c \n");
	style('R');

	//TEST 01: ARGV
	printf("\n--------------------------------------------\n");
	style('T');
	printf(" TEST 01: ARGV \n\n");
	style('r');
	fd_argv = open(argv[1], O_CREAT | O_EXCL);
	argv_str = get_next_line(fd_argv);
	free(argv_str);

	//TEST 02: READ FD
	printf("\n--------------------------------------------\n");
	style('T');
	printf(" TEST 02: FD READ \n\n");
	style('r');

	i = 0;
	fd = open("path/to/file", O_RDONLY);
	while (i < )
	str[i] = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
}
