/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:56:36 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/04/08 14:27:28 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_remain(char *buffer)
{
	char	*buffer_new;
	int		i;
	int		j;

	if (buffer == NULL)
		return (free(buffer), NULL);
	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	if (buffer[i] == '\n')
		i++;
	buffer_new = ft_calloc((ft_str_len(buffer) - i + 1), sizeof(char));
	if (buffer_new == NULL)
		return (free(buffer_new), NULL);
	while (buffer[i + j] != '\0')
	{
		buffer_new[j] = buffer[i + j];
		j++;
	}
	buffer_new[j] = '\0';
	return (free(buffer), buffer_new);
}

char	*get_str(char *buffer)
{
	char	*str;
	int		len;

	if (buffer == NULL || buffer[0] == '\0')
		return (NULL);
	len = 0;
	while (buffer[len] != '\0' && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	str = ft_calloc((len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	len = 0;
	while (buffer[len] != '\0' && buffer[len] != '\n')
	{
		str[len] = buffer[len];
		len++;
	}
	if (buffer[len] == '\n')
		str[len++] = '\n';
	str[len] = '\0';
	return (str);
}

char	*read_chars(char *buffer, int fd)
{
	char	*chunk;
	int		chars_read;

	chunk = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (chunk == NULL)
		return (NULL);
	chars_read = 1;
	while ((ft_strchr(buffer, '\n') == NULL) && (chars_read != 0))
	{
		chars_read = read(fd, chunk, BUFFER_SIZE);
		if (chars_read == (-1))
		{
			free(buffer);
			free(chunk);
			return (NULL);
		}
		if (chars_read == 0)
			return (free(chunk), buffer);
		chunk[chars_read] = '\0';
		buffer = ft_strjoin(buffer, chunk);
	}
	free (chunk);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if ((fd < 0) || (fd > OPEN_MAX) || (BUFFER_SIZE <= 0))
		return (NULL);
	buffer[fd] = read_chars(buffer[fd], fd);
	if (buffer[fd] == NULL)
		return (free(buffer[fd]), NULL);
	line = get_str(buffer[fd]);
	buffer[fd] = get_remain(buffer[fd]);
	if (line == NULL)
		return (free(line), NULL);
	return (line);
}
