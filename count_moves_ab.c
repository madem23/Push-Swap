/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves_ab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:44:07 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 10:44:10 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fake_libft/fake_libft.h"
#include <stdio.h>

//part of count_moves_ab (norm). 
int	ft_count_moves_bis(t_stacks *stacks, int best_score, int rrb, int **moves)
{
	int	rb;

	rb = 0;
	while (moves[rb])
	{
		rrb = *(stacks->b_size) - rb;
		best_score = ft_min(best_score, ft_score_each_rb(moves[rb], rb, rrb));
		rb++;
	}
	return (best_score);
}

//moves: [1] nb of rb moves, [2] code for ra or rra, 3: nb of ra/rra moves
int	ft_count_moves_ab(t_stacks *stacks)
{
	int		**moves;
	int		best_score;
	int		rb;
	int		rrb;
	t_list	*tmp_b;

	rb = 0;
	best_score = 10000;
	rrb = *(stacks->b_size);
	tmp_b = *(stacks->stack_b);
	moves = malloc(sizeof(int *) * (*(stacks->b_size) + 1));
	while (tmp_b)
	{
		moves[rb] = ft_count_ra(stacks, rb);
		tmp_b = tmp_b->next;
		rb++;
	}
	moves[rb] = NULL;
	best_score = ft_count_moves_bis(stacks, best_score, rrb, moves);
	ft_free_tab_int(moves);
	return (best_score);
}
