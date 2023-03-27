/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:43:11 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 10:43:14 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fake_libft/fake_libft.h"
#include <stdio.h>

int	ft_is_sorted(t_stacks *stacks)
{
	int		min;
	t_list	*tmp;

	tmp = *(stacks->stack_a);
	while (tmp)
	{
		min = tmp->rank;
		if (tmp->next && min > (tmp->next)->rank)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort_2_3(t_stacks *stacks)
{
	t_list	*tmp;
	int		rank_1;
	int		rank_2;
	int		rank_3;

	while (!(ft_is_sorted(stacks)))
	{
		tmp = *(stacks->stack_a);
		if (!(tmp->next->next))
		{
			ft_swap_a(stacks, 0);
			return ;
		}
		rank_1 = tmp->rank;
		rank_2 = tmp->next->rank;
		rank_3 = tmp->next->next->rank;
		if (rank_1 + rank_2 <= rank_2 + rank_3)
			ft_swap_a(stacks, 0);
		else if (rank_2 > rank_1 && rank_2 > rank_3)
			ft_reverse_rotate_a(stacks, 0);
		else
			ft_rotate_a(stacks, 0);
	}
}

//returns 1 if rank of 1st element is higher than the 2nd
int	ft_check_ranks(t_list *elem_b, t_list *elem_a)
{
	if (elem_b->rank < elem_a->rank)
		return (0);
	else
		return (1);
}

int	ft_min(int a, int b)
{
	if ((a <= b && a >= 0) || b < 0)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if ((a >= b && a >= 0) || b < 0)
		return (a);
	else
		return (b);
}
