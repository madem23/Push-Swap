/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:44:24 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 10:44:26 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fake_libft/fake_libft.h"
#include <stdio.h>

//Returns a pointer to the future last element of the list,
//after executing the moves stored
t_list	*ft_proj_last_a(t_list *lst, int rot_moves)
{
	if (rot_moves == 0)
		return (ft_lstlast(lst));
	if (!lst)
		return (NULL);
	while (lst && (rot_moves-- > 1))
		lst = lst->next;
	return (lst);
}

int	ft_count_ra_minmax(t_stacks *stacks, t_list *tmp_a)
{
	int	ra;

	ra = 0;
	while (tmp_a && tmp_a->rank != *(stacks->min_rank_a))
	{
		ra++;
		tmp_a = tmp_a->next;
	}
	return (ra);
}

int	ft_count_ra_normal(t_stacks *stacks, t_list *tmp_a, t_list *tmp_b)
{
	int	ra;

	ra = 0;
	while (tmp_a)
	{
		if ((tmp_b->rank < tmp_a->rank)
			&& (ft_check_ranks(tmp_b, ft_proj_last_a(*(stacks->stack_a), ra))))
			break ;
		ra++;
		tmp_a = tmp_a->next;
	}
	if (tmp_a == ft_lstlast(*(stacks->stack_a)))
	{
		if ((tmp_b->rank > tmp_a->rank)
			|| !(ft_check_ranks(tmp_b, ft_proj_last_a(*(stacks->stack_a), ra))))
			ra = -1;
	}
	return (ra);
}

int	*ft_count_ra_spec(t_stacks *stacks, int ra, int *foreachrb_ra_rra)
{
	if ((ra == *(stacks->a_size) && *(stacks->a_size) != 1)
		|| (*(stacks->a_size) == 1))
	{
		foreachrb_ra_rra[0] = -1;
		foreachrb_ra_rra[1] = -1;
		return (foreachrb_ra_rra);
	}
	foreachrb_ra_rra[1] = *(stacks->a_size) - ra;
	return (foreachrb_ra_rra);
}

// 0:nb ra, 1:nb rra
int	*ft_count_ra(t_stacks *stacks, int rb)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		*foreachrb_ra_rra;
	int		ra;

	ra = 0;
	tmp_a = *(stacks->stack_a);
	tmp_b = *(stacks->stack_b);
	foreachrb_ra_rra = malloc(sizeof(int) * 2);
	while (tmp_b && rb > 0)
	{
		tmp_b = tmp_b->next;
		rb--;
	}
	if ((tmp_b->rank < *(stacks->min_rank_a)
			|| (tmp_b->rank > *(stacks->max_rank_a))))
		ra = ft_count_ra_minmax(stacks, tmp_a);
	else
		ra = ft_count_ra_normal(stacks, tmp_a, tmp_b);
	foreachrb_ra_rra[0] = ra;
	foreachrb_ra_rra = ft_count_ra_spec(stacks, ra, foreachrb_ra_rra);
	return (foreachrb_ra_rra);
}
