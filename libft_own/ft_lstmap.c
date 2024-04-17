/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:26:47 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/20 16:45:19 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_lstmap
Prototype -		t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));
Turn in files -
Parameters -	lst: The address of a pointer to a node.
				f: The address of the function used to iterate on
					the list.
				del: The address of the function used to delete
					the content of a node if needed.
Return value -	The new list.
				NULL if the allocation fails.
External functs. -	malloc, free
Description -	Iterates the list ’lst’ and applies the function
				’f’ on the content of each node. Creates a new
				list resulting of the successive applications of
				the function ’f’. The ’del’ function is used to
				delete the content of a node if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*node_new;
	void	*content_new;

	if ((lst == NULL) || (f == NULL) || (del == NULL))
		return (NULL);
	lst_new = NULL;
	while (lst)
	{
		content_new = f(lst->content);
		if (content_new != NULL)
		{
			node_new = ft_lstnew(content_new);
			if (!node_new)
			{
				del(content_new);
				ft_lstclear(&lst_new, del);
				return (NULL);
			}
			ft_lstadd_back(&lst_new, node_new);
		}
		lst = lst->next;
	}
	return (lst_new);
}
