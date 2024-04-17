/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:58:47 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/13 17:54:25 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstck, const char *ndl, size_t len)
{
	const char	*p_hstck;
	const char	*p_ndl;
	size_t		len_ndl;
	size_t		i;
	size_t		j;

	p_hstck = hstck;
	p_ndl = ndl;
	len_ndl = 0;
	i = 0;
	if (*p_ndl == '\0')
		return ((char *)p_hstck);
	while (p_ndl[len_ndl] != '\0')
		len_ndl++;
	while ((p_hstck[i] != '\0') && (i < len))
	{
		j = 0;
		while ((p_ndl[j] != '\0') && (p_ndl[j] == p_hstck[i + j])
			&& ((i + j) < len))
			j++;
		if (p_ndl[j] == '\0')
			return ((char *)(p_hstck + i));
		i++;
	}
	return (NULL);
}
