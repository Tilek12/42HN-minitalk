/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:17:19 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/20 15:58:54 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_lstclear
Prototype -		void ft_lstclear(t_list **lst, void (*del)(void
														*));
Turn in files -
Parameters -	lst: The address of a pointer to a node.
				del: The address of the function used to delete
				the content of the node.
Return value -	None
External functs. -	free
Description -	Deletes and frees the given node and every
				successor of that node, using the function ’del’
				and free(3).
				Finally, the pointer to the list must be set to
				NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_pstn;
	t_list	*next_pstn;

	if (*lst == NULL || lst == NULL)
		return ;
	current_pstn = *lst;
	while (current_pstn != NULL)
	{
		next_pstn = current_pstn->next;
		if (del != NULL)
			del(current_pstn->content);
		free(current_pstn);
		current_pstn = next_pstn;
	}
	*lst = NULL;
}
