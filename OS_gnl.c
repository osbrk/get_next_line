/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:46:01 by osukhore          #+#    #+#             */
/*   Updated: 2025/12/05 11:41:46 by osukhore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

static void	style(char style)
{
	if (style == 'B')
		printf("\e[34m");
	else if (style == 'E')
		printf("\e[1;31;7m");
	else if (style == 'T')
		printf("\e[1;7m");
	else if (style == 'R')
		printf("\e[0m");
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*linetest1;
	char	*linetest2;
	char	*linetest3;
	int		i;
	int		lines_to_print;

	lines_to_print = 10;

	// ERROR CHECK
	if (argc < 2)
	{
		printf("\n--------------------------------------------\n");
		style('E');
		printf(" ERROR ");
		style('R');
		style('T');
		printf(" Need ARGV to work with: \n\n"
				" 1. File path \n");
		style('R');
		printf("--------------------------------------------\n");
		return (0);
	}

	// FILE NAME
	printf("\n--------------------------------------------\n");
	style('T');
	printf(" FILE: %s ", argv[1]);
	style('R');
	printf("\n--------------------------------------------\n");

	// TEST 01: READ FIRST 1 LINE
	style('T');
	printf(" TEST 01: FIRST 1 LINE \n");
	style('R');
	printf("\n");

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		style('E');
		printf("Could not open file\n");
		style('R');
		return (0);
	}

	linetest1 = get_next_line(fd);
	if (linetest1 == NULL)
	{
		style('B');
		printf("[EOF]\n");
		style('R');
	}
	else
	{
		printf("1: %s", linetest1);
		free(linetest1);
	}

	close(fd);

	// TEST 02: READ FIRST 10 LINES
	printf("\n--------------------------------------------\n");
	style('T');
	printf(" TEST 02: FIRST %d LINES \n", lines_to_print);
	style('R');
	printf("\n");

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		style('E');
		printf("Could not open file\n");
		style('R');
		return (0);
	}

	i = 0;
	while (i < lines_to_print)
	{
		linetest2 = get_next_line(fd);
		if (linetest2 == NULL)
		{
			style('B');
			printf("[EOF]\n");
			style('R');
			break ;
		}
		printf("%d: %s", (i + 1), linetest2);
		free(linetest2);
		i++;
	}

	close(fd);


	// TEST 03: FULL FILE READ
	printf("\n--------------------------------------------\n");
	style('T');
	printf(" TEST 03: FULL FILE UNTIL EOF \n");
	style('R');
	printf("\n");

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		style('E');
		printf("Could not open file\n");
		style('R');
		return (0);
	}
	i = 0;
	while (1)
	{
		i++;
		linetest3 = get_next_line(fd);
		if (linetest3 == NULL)
			break ;
		printf("%d: %s", i, linetest3);
		free(linetest3);
	}

	style('B');
	printf("[EOF]\n");
	style('R');

	close(fd);

	printf("--------------------------------------------\n");

	return (0);
}
