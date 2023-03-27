/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:57:38 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 11:57:41 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake_libft/fake_libft.h"
#include "push_swap.h"
#include <stdio.h>

//checks if '-' or '+', if not, returns 0.
int	ft_check_ifbegsign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

//checks if duplicate number in input
int	ft_check_duplicate(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		dup;

	tmp = *(stacks->stack_a);
	while (tmp)
	{
		dup = 0;
		tmp2 = *(stacks->stack_a);
		while (tmp2)
		{
			if (tmp->content == tmp2->content)
				dup++;
			if (dup > 1)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

//checks if all char of the tab of strings are digits or +/- for beginning char
int	ft_check_digits(char **tab, int i)
{
	int	j;

	j = 0;
	while (tab[i])
	{
		if (!(ft_isdigit(tab[i][j])) && !(ft_check_ifbegsign(tab[i][j])))
			return (0);
		while (tab[i][++j])
		{
			if (!(ft_isdigit(tab[i][j])))
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}
