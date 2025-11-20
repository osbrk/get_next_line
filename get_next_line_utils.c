/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:15:39 by osukhore          #+#    #+#             */
/*   Updated: 2025/11/20 12:27:19 by osukhore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strnl(const char *s)
{
	size_t	i;
	char	a;

	i = 0;
	a = '\n';
	while (s[i] != '\0')
	{
		if (s[i] == a)
			return (i);
		i++;
	}
	if (a == 0)
		return (i);
	return (0);
}

char	*ft_strndup(const char *s, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(len + 1);
	if (str == 0)
		return (0);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}
