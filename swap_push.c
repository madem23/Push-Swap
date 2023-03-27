/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:16:03 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 11:16:05 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fake_libft/fake_libft.h"
#include <stdio.h>

//permutes 1st element with 2nd in stack a
void	ft_swap_a(t_stacks *stacks, int ss)
{
	t_list	*tmp;
	t_list	*new_first_element;

	if (!(*(stacks->stack_a)) || (!(*(stacks->stack_a))->next))
		return ;
	new_first_element = (*(stacks->stack_a))->next;
	tmp = (*(stacks->stack_a));
	tmp = tmp->next;
	(*(stacks->stack_a))->next = tmp->next;
	new_first_element->next = (*(stacks->stack_a));
	(*(stacks->stack_a)) = new_first_element;
	if (ss == 0)
		ft_putstr_fd("sa\n", 1);
}

//permutes 1st element with 2nd in stack b
void	ft_swap_b(t_stacks *stacks, int ss)
{
	t_list	*tmp;
	t_list	*new_first_element;

	if (!(*(stacks->stack_b)) || (!(*(stacks->stack_b))->next))
		return ;
	new_first_element = (*(stacks->stack_b))->next;
	tmp = (*(stacks->stack_b));
	tmp = tmp->next;
	(*(stacks->stack_b))->next = tmp->next;
	new_first_element->next = (*(stacks->stack_b));
	(*(stacks->stack_b)) = new_first_element;
	if (ss == 0)
		ft_putstr_fd("sb\n", 1);
}

//permutes 1st element with 2nd in stack a & in stack b
void	ft_swap_all(t_stacks *stacks)
{
	ft_swap_a(stacks, 1);
	ft_swap_b(stacks, 1);
	ft_putstr_fd("ss\n", 1);
}

//Put the 1st element of a at the top of b.
void	ft_push_to_b(t_stacks *stacks)
{
	t_list	*tmp;

	if (!(*(stacks->stack_a)))
		return ;
	tmp = *(stacks->stack_a);
	(*(stacks->stack_a)) = (*(stacks->stack_a))->next;
	ft_lstadd_front(stacks->stack_b, tmp);
	ft_putstr_fd("pb\n", 1);
	(*(stacks->a_size))--;
	(*(stacks->b_size))++;
	ft_update_min_max(stacks);
}

//Put the 1st element of b at the top of a.
void	ft_push_to_a(t_stacks *stacks)
{
	t_list	*tmp;

	if (!(*(stacks->stack_b)))
		return ;
	tmp = *(stacks->stack_b);
	(*(stacks->stack_b)) = (*(stacks->stack_b))->next;
	ft_lstadd_front(stacks->stack_a, tmp);
	ft_putstr_fd("pa\n", 1);
	(*(stacks->b_size))--;
	(*(stacks->a_size))++;
	ft_update_min_max(stacks);
}
