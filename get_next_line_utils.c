/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:15:39 by osukhore          #+#    #+#             */
/*   Updated: 2025/11/26 15:32:11 by osukhore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	size_t	s_len;
	char	*str;

	i = -1;
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		str = (char *)malloc(1);
		if (str == 0)
			return (0);
		str[0] = '\0';
		return (str);
	}
	str_len = s_len - (size_t)start;
	if (len > str_len)
		len = str_len;
	str = (char *)malloc(len + 1);
	if (str == 0)
		return (0);
	while (++i < len)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}

size_t	ft_strnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (NULL);
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
