/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:19:28 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/20 16:49:04 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
ssize_t	ft_strchr(const char *accumulation, int c);
size_t	ft_strlen(const char *accumulation);
char	*ft_strjoin(char *acc, char *buff);
char	*ft_strdup(const char *s1);
char	*ft_substr(char *accumulation, unsigned int start, size_t len);

#endif