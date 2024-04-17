/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:57:32 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/19 19:31:25 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_lstadd_back
Prototype -		void ft_lstadd_back(t_list **lst, t_list *new);
Turn in files -
Parameters -	lst: The address of a pointer to the first link of
				a list.
				new: The address of a pointer to the node to be
				added to the list.
Return value -	None
External functs. -	None
Description -	Adds the node ’new’ at the end of the list.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	ptr = ft_lstlast(ptr);
	ptr->next = new;
}
