/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:49:38 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 11:49:40 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fake_libft/fake_libft.h"
#include <stdio.h>

//returns following min int after previous ones have been ranked
int	ft_get_next_min(t_list *list, int min)
{
	int		new_min;
	t_list	*tmp;

	tmp = list;
	while (tmp->content <= min && tmp)
		tmp = tmp->next;
	new_min = tmp->content;
	while (list)
	{
		if (list->content < new_min && list->content > min)
			new_min = list->content;
		list = list->next;
	}
	return (new_min);
}

//returns the first min int of stack_a
int	ft_get_first_min(t_list **list)
{
	int		min;
	t_list	*tmp;

	tmp = *list;
	min = (*list)->content;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

//Gives a rank from 0 to (size - 1) to each int of stack a
void	ft_get_rank(t_list **list, int size)
{
	int		min;
	t_list	*tmp;
	int		rank;

	rank = 0;
	min = ft_get_first_min(list);
	tmp = *list;
	while (tmp)
	{
		if (tmp->content == min)
			tmp->rank = rank++;
		tmp = tmp->next;
	}
	while (rank < size)
	{
		tmp = *list;
		min = ft_get_next_min(*list, min);
		while (tmp)
		{
			if (tmp->content == min)
				tmp->rank = rank++;
			tmp = tmp->next;
		}
	}
}
