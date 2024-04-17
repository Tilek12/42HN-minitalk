/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:27:28 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/20 15:56:27 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_lstnew
Prototype -		t_list *ft_lstnew(void *content);
Turn in files -
Parameters -	content: The content to create the node with.
Return value -	The new node
External functs. -	malloc
Description -	Allocates (with malloc(3)) and returns a new node.
				The member variable ’content’ is initialized with
				the value of the parameter ’content’. The variable
				’next’ is initialized to NULL.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
	free(list);
}
