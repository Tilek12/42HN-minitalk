/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:45:59 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/04/06 17:51:29 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
char	*read_chars(char *buffer, int fd);
char	*get_str(char *buffer);
char	*get_remain(char *buffer);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *str, int c);
size_t	ft_str_len(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_str_copy(char *dest, char *src, size_t len);

#endif
