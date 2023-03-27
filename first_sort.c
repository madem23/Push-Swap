/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:07:56 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 11:07:58 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fake_libft/fake_libft.h"
#include <stdio.h>

int	ft_choose_rra_1st_sort(t_stacks *stacks, int pivot)
{	
	t_list	*tmp;
	int		i;
	int		rra;
	int		rra_save;

	rra_save = -1;
	rra = (*(stacks->a_size)) / 2;
	tmp = (*(stacks->stack_a));
	i = 0;
	if ((*(stacks->a_size)) % 2 == 1)
		rra = (*(stacks->a_size)) / 2 + 1;
	while (i++ < (*(stacks->a_size)) / 2)
		tmp = tmp->next;
	i = rra;
	while (tmp->next)
	{
		tmp = tmp->next;
		rra--;
		if (tmp->rank < pivot)
			rra_save = rra;
	}
	if (rra_save == i)
		rra_save = -1;
	return (rra_save);
}

//choose between ra et rra for the fist sorting operation
int	*ft_choose_ra_rra_first_sort(t_stacks *stacks, int pivot, int *res)
{
	t_list	*tmp;
	int		ra;
	int		rra_save;

	ra = 0;
	tmp = (*(stacks->stack_a));
	while (tmp->rank > pivot)
	{
		tmp = tmp->next;
		ra++;
	}
	res[0] = 1;
	res[1] = ra;
	rra_save = ft_choose_rra_1st_sort(stacks, pivot);
	if (rra_save < ra && rra_save > 0)
	{
		res[0] = 2;
		res[1] = rra_save;
	}
	return (res);
}

void	ft_apply_res_0(t_stacks *stacks, int *res)
{
	if (res[0] == 1)
		ft_rotate_a(stacks, 0);
	else if (res[0] == 2)
		ft_reverse_rotate_a(stacks, 0);
}

//First quicksort sorting while pushing all but 3 to B
void	ft_first_sort_to_b(t_stacks *stacks)
{
	int	pivot;
	int	j;
	int	a_size_round;
	int	*res;

	j = 1;
	res = malloc(sizeof(int) * 2);
	while ((*(stacks->a_size)) > 3)
	{
		pivot = stacks->lst_size / 3 * j;
		a_size_round = (*(stacks->a_size));
		while (((*(stacks->a_size)) > 3)
			&& (a_size_round - (*(stacks->a_size)) < pivot / j))
		{
			if ((*(stacks->stack_a))->rank <= pivot)
				ft_push_to_b(stacks);
			else
			{
				res = ft_choose_ra_rra_first_sort(stacks, pivot, res);
				ft_apply_res_0(stacks, res);
			}
		}
		j++;
	}
	free(res);
}
