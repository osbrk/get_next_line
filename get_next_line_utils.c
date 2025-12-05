/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:15:39 by osukhore          #+#    #+#             */
/*   Updated: 2025/12/05 14:22:37 by osukhore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	if (s == NULL)
		return (NULL);
	ch = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*res;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (res == NULL)
		return (free(s1), NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	i = -1;
	while (++i < len2)
		res[len1 + i] = s2[i];
	res[len1 + len2] = '\0';
	free(s1);
	return (res);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*sub;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		sub = (char *)malloc(1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}
