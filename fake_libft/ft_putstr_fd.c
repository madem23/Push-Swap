/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:49:02 by mdemma            #+#    #+#             */
/*   Updated: 2022/03/29 14:44:17 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake_libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
}
