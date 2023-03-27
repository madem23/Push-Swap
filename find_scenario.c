/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_scenario.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:44:34 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 10:44:36 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fake_libft/fake_libft.h"

int	ft_score_each_rb(int *moves, int rb, int rrb)
{
	int	ra;
	int	rra;
	int	score;

	ra = moves[0];
	rra = moves[1];
	if (ra >= rb)
		score = ra;
	else if (ra < rb)
		score = rb;
	if (rra >= rrb && rra < score)
			score = rra;
	else if (rra < rrb && rrb < score)
		score = rrb;
	if (score > rra + rb)
		score = rra + rb;
	if (score > rrb + ra)
		score = rrb + ra;
	return (score);
}

//ra = moves[0]; rra = moves[1]
//[0] code 1/2/3/4 for ra/rra/rb/rrb, [1] nb of moves
//[2] code 3/4/5/6 for rb/rrb/rr/rrr, [3] nb of moves
int	*ft_find_scenario(int *moves, int rb, int rrb)
{
	int	*final_scenario;
	int	score;

	if (moves[0] >= rb)
		final_scenario = ft_create_tab(1, moves[0] - rb, 5, rb);
	else if (moves[0] < rb)
		final_scenario = ft_create_tab(3, rb - moves[0], 5, moves[0]);
	score = ft_max(moves[0], rb);
	if (moves[1] >= rrb && moves[1] < score)
		final_scenario = ft_tab_rra_rrr(final_scenario, moves, rrb);
	else if (moves[1] < rrb && rrb < score)
		final_scenario = ft_tab_rrb_rrr(final_scenario, moves, rrb);
	if (moves[1] < score || rrb < score)
		score = ft_max(moves[1], rrb);
	if (score > moves[1] + rb)
	{
		score = moves[1] + rb;
		final_scenario = ft_tab_rra_rb(final_scenario, moves, rb);
	}
	if (score > rrb + moves[0])
	{
		score = rrb + moves[0];
		final_scenario = ft_tab_ra_rrb(final_scenario, moves, rrb);
	}
	return (final_scenario);
}

//for norm.
int	**ft_find_best_score_scenario_bis(t_stacks *stacks)
{
	int		**final_moves;
	int		rb;
	t_list	*tmp_b;

	rb = 0;
	tmp_b = *(stacks->stack_b);
	final_moves = malloc(sizeof(int *) * ((*(stacks->b_size)) + 1));
	while (tmp_b)
	{
		final_moves[rb] = ft_count_ra(stacks, rb);
		tmp_b = tmp_b->next;
		rb++;
	}
	final_moves[rb] = NULL;
	return (final_moves);
}

//[0] code 1/2/3/4 for ra/rra/rb/rrb, [1] nb of moves
//[2] code 3/4/5/6 for rb/rrb/rr/rrr, [3] nb of moves
//final_moves = [1] nb moves de rb [2] code pour ra ou rra,[3] nb of ra/rra
int	*ft_find_best_score_scenario(t_stacks *stacks, int best_score)
{
	int		**final_moves;
	int		rb;
	int		rrb;
	int		*final_scenario;

	final_moves = ft_find_best_score_scenario_bis(stacks);
	rb = 0;
	while (final_moves[rb])
	{
		rrb = *(stacks->b_size) - rb;
		if (best_score == ft_score_each_rb(final_moves[rb], rb, rrb))
			break ;
		rb++;
	}
	final_scenario = ft_find_scenario(final_moves[rb], rb, rrb);
	rb = 0;
	ft_free_tab_int(final_moves);
	return (final_scenario);
}
