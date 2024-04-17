/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:26:21 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/18 16:13:39 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_split
Prototype -		char **ft_split(char const *s, char c);
Turn in files -
Parameters -	s: The string to be split.
				c: The delimiter character.
Return value -	The array of new strings resulting from the split.
				NULL if the allocation fails.
External functs. -	malloc, free
Description -	Allocates (with malloc(3)) and returns an array
				of strings obtained by splitting ’s’ using the
				character ’c’ as a delimiter. The array must end
				with a NULL pointer.
*/

static int	count_words(const char *s, char c)
{
	int	word_counter;
	int	in_word;

	word_counter = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (in_word)
				in_word = 0;
		}
		else
		{
			if (!in_word)
			{
				in_word = 1;
				word_counter++;
			}
		}
		s++;
	}
	return (word_counter);
}

static char	*next_word(const char **s, char c)
{
	const char	*p_start;
	char		*word;
	size_t		len;

	p_start = *s;
	len = 0;
	while (**s && (**s == c))
		(*s)++;
	while (((*s)[len]) && ((*s)[len] != c))
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_memcpy(word, p_start, len);
	word[len] = '\0';
	*s += len;
	return (word);
}

static void	free_str(char **str, int i)
{
	while (i--)
		free(str[i]);
	free(str);
}

static int	calc(char **str, const char **s, char c, int *i)
{
	str[*i] = next_word(s, c);
	if (!str[*i])
	{
		free_str(str, *i);
		return (0);
	}
	(*i)++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words_num;
	int		i;

	if (!s)
		return (NULL);
	words_num = count_words(s, c);
	str = (char **)malloc((words_num + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!calc(str, &s, c, &i))
				return (NULL);
		}
		else
			s++;
	}
	str[words_num] = NULL;
	return (str);
}
