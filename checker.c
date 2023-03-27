/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:35:13 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 16:35:14 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake_libft/fake_libft.h"
#include "push_swap.h"
#include <stdio.h>

//Converts a tab of strings into a list of integers
//Checks if number not bigger than integers
int	ft_convert_tab_to_list(t_stacks *stacks, char **tab, int i)
{
	t_list	*new;
	long	*atoi;

	atoi = malloc(sizeof(long) * 2);
	while (tab[i])
	{
		atoi = ft_atoi_check_int(tab[i++], atoi);
		if (!atoi[1])
		{
			free(atoi);
			return (0);
		}
		new = ft_lstnew(atoi[0]);
		ft_lstadd_back(stacks->stack_a, new);
		stacks->lst_size++;
	}
	free(atoi);
	if (!(ft_check_duplicate(stacks)))
	{
		ft_free_stacks(stacks);
		return (0);
	}
	return (1);
}

int	ft_create_stack_check(t_stacks *stacks, char **tab, int i)
{
	if (!(ft_check_digits(tab, i)))
	{
		if (i == 0)
			ft_free_tab(tab);
		free(stacks);
		return (0);
	}
	if (!(ft_convert_tab_to_list(stacks, tab, i)))
	{
		if (i == 0)
			ft_free_tab(tab);
		return (0);
	}
	if (i == 0)
		ft_free_tab(tab);
	return (1);
}

//checks input and analyzes input format to convert into a list
int	ft_create_stack_a(t_stacks *stacks, int ac, char **av)
{
	char	**tab;
	int		i;

	i = 0;
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (!tab[0])
		{
			ft_free_tab(tab);
			free(stacks);
			exit(1);
		}
	}
	else
	{
		i = 1;
		tab = av;
	}
	if (!ft_create_stack_check(stacks, tab, i))
		return (0);
	return (1);
}

//checks if arg > 0
int	ft_parsing(int ac, char **av, t_stacks *stacks)
{
	if (ac < 2)
	{	
		free(stacks);
		return (0);
	}
	if (!(ft_create_stack_a(stacks, ac, av)))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	else
		return (1);
}

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_stacks	*stacks;

	stack_a = NULL;
	stack_b = NULL;
	stacks = malloc(sizeof(t_stacks));
	stacks->lst_size = 0;
	stacks->stack_a = &stack_a;
	stacks->stack_b = &stack_b;
	if (!ft_parsing(ac, av, stacks))
		return (0);
	ft_get_rank(&stack_a, stacks->lst_size);
	if (ft_read_execute(stacks))
	{
		ft_print_if_sorted(stacks);
		ft_free_stacks(stacks);
	}
	return (0);
}
