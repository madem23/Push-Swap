/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_p_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:17:24 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 17:17:26 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake_libft/fake_libft.h"
#include "push_swap.h"
#include <stdio.h>

//permutes 1st element with 2nd in stack a
void	ft_sa_checker(t_stacks *stacks)
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
}

//permutes 1st element with 2nd in stack b
void	ft_sb_checker(t_stacks *stacks)
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
}

//permutes 1st element with 2nd in stack a & in stack b
void	ft_ss_checker(t_stacks *stacks)
{
	ft_sa_checker(stacks);
	ft_sb_checker(stacks);
}

//Put the 1st element of a at the top of b.
void	ft_pb_checker(t_stacks *stacks)
{
	t_list	*tmp;

	if (!(*(stacks->stack_a)))
		return ;
	tmp = *(stacks->stack_a);
	(*(stacks->stack_a)) = (*(stacks->stack_a))->next;
	ft_lstadd_front(stacks->stack_b, tmp);
}

//Put the 1st element of b at the top of a.
void	ft_pa_checker(t_stacks *stacks)
{
	t_list	*tmp;

	if (!(*(stacks->stack_b)))
		return ;
	tmp = *(stacks->stack_b);
	(*(stacks->stack_b)) = (*(stacks->stack_b))->next;
	ft_lstadd_front(stacks->stack_a, tmp);
}
