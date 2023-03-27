/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:55:46 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 11:55:47 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake_libft/fake_libft.h"
#include "push_swap.h"
#include <stdio.h>

void	ft_free_stacks(t_stacks *stacks)
{
	t_list	*tmp;

	while (*(stacks->stack_a))
	{
		tmp = (*(stacks->stack_a));
		(*(stacks->stack_a)) = (*(stacks->stack_a))->next;
		free(tmp);
	}
	while (*(stacks->stack_b))
	{
		tmp = (*(stacks->stack_b));
		(*(stacks->stack_b)) = (*(stacks->stack_b))->next;
		free(tmp);
	}
	free(stacks);
}

//frees string tab if error found in parsing
char	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

//frees int tab if error found in parsing
void	ft_free_tab_int(int **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
