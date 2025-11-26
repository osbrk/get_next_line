/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:45:22 by osukhore          #+#    #+#             */
/*   Updated: 2025/11/26 15:12:26 by osukhore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTGNL_H
# define LIBFTGNL_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE=42
#endif //BUFFER

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	ft_putstr(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strnl(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif //LIBFTGNL_H