/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:21:16 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 10:21:21 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fake_libft/fake_libft.h"
#include <stdio.h>

// 0: code 1/2/3/4/5/6 for ra/rra/rb/rrb/rr/rrr 1:nb of moves 2:code 3:moves 
void	ft_apply_sorting_bis(t_stacks *stacks, int *moves)
{
	int	nb_moves;

	nb_moves = moves[3];
	if (moves[2] == 5)
	{
		while (nb_moves-- > 0)
			ft_rotate_all(stacks);
	}
	else if (moves[2] == 6)
	{
		while (nb_moves-- > 0)
			ft_reverse_rotate_all(stacks);
	}
	else if (moves[2] == 3)
	{
		while (nb_moves-- > 0)
			ft_rotate_b(stacks, 0);
	}
	else if (moves[2] == 4)
	{
		while (nb_moves-- > 0)
			ft_reverse_rotate_b(stacks, 0);
	}
	ft_push_to_a(stacks);
}

// 0: code 1/2/3/4/5/6 for ra/rra/rb/rrb/rr/rrr 1:nb of moves 2:code 3:moves 
void	ft_apply_sorting_decision(t_stacks *stacks, int *moves)
{
	int	nb_moves;

	nb_moves = moves[1];
	if (moves[0] == 1)
	{
		while (nb_moves-- > 0)
			ft_rotate_a(stacks, 0);
	}
	else if (moves[0] == 2)
	{
		while (nb_moves-- > 0)
			ft_reverse_rotate_a(stacks, 0);
	}
	else if (moves[0] == 3)
	{
		while (nb_moves-- > 0)
			ft_rotate_b(stacks, 0);
	}
	else if (moves[0] == 4)
	{
		while (nb_moves-- > 0)
			ft_reverse_rotate_b(stacks, 0);
	}
	ft_apply_sorting_bis(stacks, moves);
}

//once sorted, puts the pointer of the beg. of the stack A on the rank-0-elem
void	ft_ascending_order(t_stacks *stacks)
{
	int		ra;
	int		rra;
	t_list	*tmp;

	ra = 0;
	rra = 0;
	tmp = *(stacks->stack_a);
	while (tmp->rank != 0)
	{
		ra++;
		tmp = tmp->next;
	}
	rra = *(stacks->a_size) - ra;
	if (ra <= rra)
	{
		while (ra-- > 0)
			ft_rotate_a(stacks, 0);
	}
	else
	{
		while (rra-- > 0)
			ft_reverse_rotate_a(stacks, 0);
	}
}

//if stack size is n, ra scenario + rra scenario (same result) = n - 1.
void	ft_sort_big(t_stacks *stacks)
{
	int	best_score;
	int	*moves;

	ft_first_sort_to_b(stacks);
	ft_sort_2_3(stacks);
	while (*(stacks->b_size))
	{
		best_score = ft_count_moves_ab(stacks);
		moves = ft_find_best_score_scenario(stacks, best_score);
		ft_apply_sorting_decision(stacks, moves);
		free(moves);
	}
	ft_ascending_order(stacks);
}

void	ft_sort_main(t_stacks *stacks)
{
	int		min_a;
	int		max_a;
	int		min_b;
	int		max_b;

	min_a = 0;
	max_a = stacks->lst_size;
	min_b = 0;
	max_b = 0;
	stacks->min_rank_a = &min_a;
	stacks->max_rank_a = &max_a;
	stacks->min_rank_b = &min_b;
	stacks->max_rank_b = &max_b;
	if (ft_is_sorted(stacks))
		return ;
	if (stacks->lst_size == 2 || stacks->lst_size == 3)
	{
		ft_sort_2_3(stacks);
		return ;
	}
	if (stacks->lst_size > 3)
		ft_sort_big(stacks);
}
