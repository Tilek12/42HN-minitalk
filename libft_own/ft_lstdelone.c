/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:31:42 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/20 10:21:16 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_lstdelone
Prototype -		void ft_lstdelone(t_list *lst, void (*del)(void
														*));
Turn in files -
Parameters -	lst: The node to free.
				del: The address of the function used to delete
				the content.
Return value -	None
External functs. -	free
Description -	Takes as a parameter a node and frees the memory of
				the node’s content using the function ’del’ given
				as a parameter and free the node. The memory of
				’next’ must not be freed.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free (lst);
}
