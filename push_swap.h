/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:49:06 by mdemma            #+#    #+#             */
/*   Updated: 2022/05/19 11:49:09 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "fake_libft/fake_libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//structure which manages the parameters of the lists (stacks)
typedef struct s_stacks
{
	t_list		**stack_a;
	t_list		**stack_b;
	int			lst_size;
	int			*a_size;
	int			*min_rank_a;
	int			*max_rank_a;
	int			*b_size;
	int			*min_rank_b;
	int			*max_rank_b;
}				t_stacks;

void	ft_swap_a(t_stacks *stacks, int ss);
void	ft_swap_b(t_stacks *stacks, int ss);
void	ft_swap_all(t_stacks *stacks);
void	ft_push_to_b(t_stacks *stacks);
void	ft_push_to_a(t_stacks *stacks);
void	ft_rotate_a(t_stacks *stacks, int rr);
void	ft_rotate_b(t_stacks *stacks, int rr);
void	ft_rotate_all(t_stacks *stacks);
void	ft_reverse_rotate_a(t_stacks *stacks, int rrr);
void	ft_reverse_rotate_b(t_stacks *stacks, int rrr);
void	ft_reverse_rotate_all(t_stacks *stacks);
void	ft_sort_main(t_stacks *stacks);
void	ft_update_min_max(t_stacks *stacks);
int		*ft_choose_ra_rra_first_sort(t_stacks *stacks, int pivot, int *res);
void	ft_first_sort_to_b(t_stacks *stacks);
char	**ft_free_tab(char **tab);
void	ft_free_tab_int(int **tab);
void	ft_free_stacks(t_stacks *stacks);
int		*ft_find_best_score_scenario(t_stacks *stacks, int best_score);
int		*ft_count_ra(t_stacks *stacks, int rb);
int		ft_max(int a, int b);
int		ft_score_each_rb(int *moves, int rb, int rrb);
int		ft_check_ranks(t_list *elem_b, t_list *elem_a);
void	ft_sort_2_3(t_stacks *stacks);
int		ft_is_sorted(t_stacks *stacks);
int		ft_count_moves_ab(t_stacks *stacks);
int		ft_min(int a, int b);
int		ft_check_digits(char **tab, int i);
int		ft_check_duplicate(t_stacks *stacks);
int		ft_convert_tab_to_list(t_stacks *stacks, char **tab, int i);
int		ft_check_digits(char **tab, int i);
int		ft_check_duplicate(t_stacks *stacks);
int		ft_check_ifbegsign(char c);
int		ft_create_stack_a(t_stacks *stacks, int ac, char **av);
int		ft_execute_instruct(t_stacks *stacks, char *instruction);
void	ft_sa_checker(t_stacks *stacks);
void	ft_sb_checker(t_stacks *stacks);
void	ft_ss_checker(t_stacks *stacks);
void	ft_pb_checker(t_stacks *stacks);
void	ft_pa_checker(t_stacks *stacks);
void	ft_ra_checker(t_stacks *stacks);
void	ft_rb_checker(t_stacks *stacks);
void	ft_rr_checker(t_stacks *stacks);
void	ft_rra_checker(t_stacks *stacks);
void	ft_rrb_checker(t_stacks *stacks);
void	ft_rrr_checker(t_stacks *stacks);
int		ft_read_execute(t_stacks *stacks);
void	ft_print_if_sorted(t_stacks *stacks);
int		*ft_tab_rra_rrr(int *final_scenario, int *moves, int rrb);
int		*ft_tab_rrb_rrr(int *final_scenario, int *moves, int rrb);
int		*ft_tab_rra_rb(int *final_scenario, int *moves, int rb);
int		*ft_tab_ra_rrb(int *final_scenario, int *moves, int rrb);
int		*ft_create_tab(int a, int b, int c, int d);

#endif
