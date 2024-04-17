/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:51:21 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/20 10:24:08 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_lstiter
Prototype -		void ft_lstiter(t_list *lst, void (*f)(void *));
Turn in files -
Parameters -	lst: The address of a pointer to a node.
				f: The address of the function used to iterate on
				the list.
Return value -	None
External functs. -	None
Description -	Iterates the list ’lst’ and applies the function
				’f’ on the content of each node.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
