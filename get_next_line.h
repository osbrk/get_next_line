/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:45:22 by osukhore          #+#    #+#             */
/*   Updated: 2025/11/20 12:28:45 by osukhore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTGNL_H
# define LIBFTGNL_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strnl(const char *s);
char	*ft_strndup(const char *s, size_t len);

#endif //LIBFTPRINTF_H