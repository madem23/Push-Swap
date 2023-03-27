/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:17:08 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 17:17:11 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake_libft/fake_libft.h"
#include "push_swap.h"
#include <stdio.h>

//Shift down all elements of stack a by 1.
//The last element becomes the first one.
//if rrr = 0, rra must be printed,
//if rrr = 1, it is rrr which is called
void	ft_rra_checker(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*(stacks->stack_a)) || !((*(stacks->stack_a))->next))
		return ;
	last = ft_lstlast(*(stacks->stack_a));
	ft_lstadd_front(stacks->stack_a, last);
	tmp = *(stacks->stack_a);
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
}

//Shift down all elements of stack b by 1.
//The last element becomes the first one.
void	ft_rrb_checker(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*(stacks->stack_b)) || !((*(stacks->stack_b))->next))
		return ;
	last = ft_lstlast(*(stacks->stack_b));
	ft_lstadd_front(stacks->stack_b, last);
	tmp = *(stacks->stack_b);
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
}

//Shift down all elements of stack a & b by 1.
//The last element becomes the first one.
void	ft_rrr_checker(t_stacks *stacks)
{
	ft_rra_checker(stacks);
	ft_rrb_checker(stacks);
}
