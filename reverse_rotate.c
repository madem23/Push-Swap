/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:43:22 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 11:43:23 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fake_libft/fake_libft.h"

//Shift down all elements of stack a by 1.
//The last element becomes the first one.
//if rrr = 0, rra must be printed,
//if rrr = 1, it is rrr which is called
void	ft_reverse_rotate_a(t_stacks *stacks, int rrr)
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
	if (rrr == 0)
		ft_putstr_fd("rra\n", 1);
}

//Shift down all elements of stack b by 1.
//The last element becomes the first one.
void	ft_reverse_rotate_b(t_stacks *stacks, int rrr)
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
	if (rrr == 0)
		ft_putstr_fd("rrb\n", 1);
}

//Shift down all elements of stack a & b by 1.
//The last element becomes the first one.
void	ft_reverse_rotate_all(t_stacks *stacks)
{
	ft_reverse_rotate_a(stacks, 1);
	ft_reverse_rotate_b(stacks, 1);
	ft_putstr_fd("rrr\n", 1);
}
