/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:41:12 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 11:41:16 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fake_libft/fake_libft.h"

void	ft_update_min_max_b(t_stacks *stacks, int min_a)
{
	t_list	*tmp;
	int		min_b;

	min_b = *(stacks->max_rank_b);
	*(stacks->max_rank_b) = *(stacks->min_rank_b);
	tmp = *(stacks->stack_b);
	while (tmp)
	{
		if (tmp->rank < min_b)
			min_b = tmp->rank;
		if (tmp->rank > *(stacks->max_rank_b))
			*(stacks->max_rank_b) = tmp->rank;
		tmp = tmp->next;
	}
	if (min_b == 0 && min_a == 0)
		*(stacks->min_rank_b) = *(stacks->max_rank_b);
	else
	*(stacks->min_rank_b) = min_b;
}

//updates min and max ranks of each stacks after each movement
void	ft_update_min_max(t_stacks *stacks)
{
	t_list	*tmp;
	int		min_a;

	min_a = *(stacks->max_rank_a);
	*(stacks->max_rank_a) = *(stacks->min_rank_a);
	tmp = *(stacks->stack_a);
	while (tmp)
	{
		if (tmp->rank < min_a)
			min_a = tmp->rank;
		if (tmp->rank > *(stacks->max_rank_a))
			*(stacks->max_rank_a) = tmp->rank;
		tmp = tmp->next;
	}
	*(stacks->min_rank_a) = min_a;
	ft_update_min_max_b(stacks, min_a);
}

//Shift up all elements of stack a by 1.
//The first element becomes the last one.
//if rr = 0, ra must be printed,
//if rr = 1, it is rr which is called
void	ft_rotate_a(t_stacks *stacks, int rr)
{
	t_list	*tmp;

	if (!(*(stacks->stack_a)) || !((*(stacks->stack_a))->next))
		return ;
	ft_lstadd_back(stacks->stack_a, (*(stacks->stack_a)));
	tmp = (*(stacks->stack_a));
	(*(stacks->stack_a)) = (*(stacks->stack_a))->next;
	tmp->next = NULL;
	if (rr == 0)
		ft_putstr_fd("ra\n", 1);
}

//Shift up all elements of stack b by 1.
//The first element becomes the last one.
//if rr = 0, rb must be printed,
//if rr = 1, it is rr which is called
void	ft_rotate_b(t_stacks *stacks, int rr)
{
	t_list	*tmp;

	if (!(*(stacks->stack_b)) || !((*(stacks->stack_b))->next))
		return ;
	ft_lstadd_back(stacks->stack_b, (*(stacks->stack_b)));
	tmp = (*(stacks->stack_b));
	(*(stacks->stack_b)) = (*(stacks->stack_b))->next;
	tmp->next = NULL;
	if (rr == 0)
		ft_putstr_fd("rb\n", 1);
}

//Shift up all elements of stack a & b by 1.
//The first element becomes the last one.
void	ft_rotate_all(t_stacks *stacks)
{
	ft_rotate_a(stacks, 1);
	ft_rotate_b(stacks, 1);
	ft_putstr_fd("rr\n", 1);
}
