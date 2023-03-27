/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:17:01 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 17:17:03 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake_libft/fake_libft.h"
#include "push_swap.h"
#include <stdio.h>

//Shift up all elements of stack a by 1.
//The first element becomes the last one.
void	ft_ra_checker(t_stacks *stacks)
{
	t_list	*tmp;

	if (!(*(stacks->stack_a)) || !((*(stacks->stack_a))->next))
		return ;
	ft_lstadd_back(stacks->stack_a, (*(stacks->stack_a)));
	tmp = (*(stacks->stack_a));
	(*(stacks->stack_a)) = (*(stacks->stack_a))->next;
	tmp->next = NULL;
}

//Shift up all elements of stack b by 1.
//The first element becomes the last one.
void	ft_rb_checker(t_stacks *stacks)
{
	t_list	*tmp;

	if (!(*(stacks->stack_b)) || !((*(stacks->stack_b))->next))
		return ;
	ft_lstadd_back(stacks->stack_b, (*(stacks->stack_b)));
	tmp = (*(stacks->stack_b));
	(*(stacks->stack_b)) = (*(stacks->stack_b))->next;
	tmp->next = NULL;
}

//Shift up all elements of stack a & b by 1.
//The first element becomes the last one.
void	ft_rr_checker(t_stacks *stacks)
{
	ft_ra_checker(stacks);
	ft_rb_checker(stacks);
}
