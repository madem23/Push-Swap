/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:34:38 by mdemma            #+#    #+#             */
/*   Updated: 2022/03/29 15:47:32 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake_libft.h"

/* Adds the element new to the beginning of the list.
 * lst = pointer's address to the 1st element of the list, to reroute on NEW.
 * t_list **lst = lst->next if *lst
 * next must point of what was formerly pointed by lst, now 2nd element.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
