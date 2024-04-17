/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:06:21 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/19 16:53:23 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_lstadd_front
Prototype -		void ft_lstadd_front(t_list **lst, t_list *new);
Turn in files -
Parameters -	lst: The address of a pointer to the first link of
				a list.
				new: The address of a pointer to the node to be
				added to the list.
Return value -	None
External functs. -	None
Description -	Adds the node ’new’ at the beginning of the list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
