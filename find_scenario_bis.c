/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_scenario_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:29:30 by mdemma            #+#    #+#             */
/*   Updated: 2022/06/02 11:29:34 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fake_libft/fake_libft.h"

//fills a 4-int tab with given int.
//[0] code 1/2/3/4 for ra/rra/rb/rrb, [1] nb of moves
//[2] code 3/4/5/6 for rb/rrb/rr/rrr, [3] nb of moves
int	*ft_create_tab(int a, int b, int c, int d)
{
	int	*final_scenario;

	final_scenario = malloc(sizeof(int) * 4);
	final_scenario[0] = a;
	final_scenario[1] = b;
	final_scenario[2] = c;
	final_scenario[3] = d;
	return (final_scenario);
}

//fills the tab for scenario rra/rrr
int	*ft_tab_rra_rrr(int *final_scenario, int *moves, int rrb)
{
	free(final_scenario);
	final_scenario = ft_create_tab(2, moves[1] - rrb, 6, rrb);
	return (final_scenario);
}

//fills the tab for scenario rrb/rrr
int	*ft_tab_rrb_rrr(int *final_scenario, int *moves, int rrb)
{
	free(final_scenario);
	final_scenario = ft_create_tab(4, rrb - moves[1], 6, moves[1]);
	return (final_scenario);
}

//fills the tab for scenario rra/rb
int	*ft_tab_rra_rb(int *final_scenario, int *moves, int rb)
{
	free(final_scenario);
	final_scenario = ft_create_tab(2, moves[1], 3, rb);
	return (final_scenario);
}

//fills the tab for scenario ra/rrb
int	*ft_tab_ra_rrb(int *final_scenario, int *moves, int rrb)
{
	free(final_scenario);
	final_scenario = ft_create_tab(1, moves[0], 4, rrb);
	return (final_scenario);
}
