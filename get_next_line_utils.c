/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:15:39 by osukhore          #+#    #+#             */
/*   Updated: 2025/11/26 10:59:48 by osukhore         ###   ########.fr       */
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

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (str == 0)
		return ;
	while (str[i] != '\0')
		write (1, &str[i++], 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	i = -1;
	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(s1_len + s2_len + 1);
	if (str == 0)
		return (0);
	while (++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		str[s1_len + i] = s2[i];
	str[s1_len + i] = '\0';
	return (str);
}
