/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:50:42 by mdemma            #+#    #+#             */
/*   Updated: 2022/03/29 15:53:15 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FAKE_LIBFT_H
# define FAKE_LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

//each elements of the lists:
typedef struct s_list
{
	int				content;
	int				rank;
	int				index;
	struct s_list	*next;
}					t_list;

int		ft_isdigit(int c);
long	*ft_atoi_check_int(const char *str, long *tab);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
t_list	*ft_lstnew(int content);
void	ft_get_rank(t_list **list, int size);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_manage_outputs(int n, char **not_printed);
char	*ft_strstock_save(char **not_printed);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
