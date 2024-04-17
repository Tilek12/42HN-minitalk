/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:40:26 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/19 18:56:06 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_lstlast
Prototype -		t_list *ft_lstlast(t_list *lst);
Turn in files -
Parameters -	lst: The beginning of the list.
Return value -	Last node of the list
External functs. -	None
Description -	Returns the last node of the list.
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
