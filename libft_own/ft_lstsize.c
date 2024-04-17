/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:23:06 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/19 18:39:46 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_lstsize
Prototype -		int ft_lstsize(t_list *lst);
Turn in files -
Parameters -	lst: The beginning of the list.
Return value -	The length of the list
External functs. -	None
Description -	Counts the number of nodes in a list.
*/

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst != NULL)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}
