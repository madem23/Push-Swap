/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:05:52 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 17:05:55 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake_libft/fake_libft.h"
#include "push_swap.h"
#include <stdio.h>

void	ft_print_if_sorted(t_stacks *stacks)
{
	if (ft_is_sorted(stacks) && !(*(stacks->stack_b)))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	ft_read_execute(t_stacks *stacks)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		if (!ft_execute_instruct(stacks, instruction))
		{
			ft_free_stacks(stacks);
			free(instruction);
			return (0);
		}
		free(instruction);
		instruction = get_next_line(0);
	}
	free(instruction);
	return (1);
}

int	ft_print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

//checks if lines read by GNL are properly-formatted instructions
int	ft_check_instructions(char *instruction)
{
	if (!ft_strncmp(instruction, "ra\n", 4))
		return (1);
	else if (!ft_strncmp(instruction, "rb\n", 4))
		return (2);
	else if (!ft_strncmp(instruction, "rr\n", 4))
		return (3);
	else if (!ft_strncmp(instruction, "rrr\n", 5))
		return (4);
	else if (!ft_strncmp(instruction, "rra\n", 5))
		return (5);
	else if (!ft_strncmp(instruction, "rrb\n", 5))
		return (6);
	else if (!ft_strncmp(instruction, "pb\n", 4))
		return (7);
	else if (!ft_strncmp(instruction, "pa\n", 4))
		return (8);
	else if (!ft_strncmp(instruction, "sa\n", 4))
		return (9);
	else if (!ft_strncmp(instruction, "sb\n", 4))
		return (10);
	else if (!ft_strncmp(instruction, "ss\n", 4))
		return (11);
	return (0);
}

//executes read instruction
int	ft_execute_instruct(t_stacks *stacks, char *instruction)
{
	if (ft_check_instructions(instruction) == 1)
		ft_ra_checker(stacks);
	else if (ft_check_instructions(instruction) == 5)
		ft_rra_checker(stacks);
	else if (ft_check_instructions(instruction) == 2)
		ft_rb_checker(stacks);
	else if (ft_check_instructions(instruction) == 6)
		ft_rrb_checker(stacks);
	else if (ft_check_instructions(instruction) == 3)
		ft_rr_checker(stacks);
	else if (ft_check_instructions(instruction) == 4)
		ft_rrr_checker(stacks);
	else if (ft_check_instructions(instruction) == 7)
		ft_pb_checker(stacks);
	else if (ft_check_instructions(instruction) == 8)
		ft_pa_checker(stacks);
	else if (ft_check_instructions(instruction) == 10)
		ft_sb_checker(stacks);
	else if (ft_check_instructions(instruction) == 9)
		ft_sa_checker(stacks);
	else if (ft_check_instructions(instruction) == 11)
		ft_ss_checker(stacks);
	else if (!ft_check_instructions(instruction))
		return (ft_print_error());
	return (1);
}
