/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:09:43 by mdemma            #+#    #+#             */
/*   Updated: 2022/03/29 14:15:40 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake_libft.h"

static int	ft_isspace(char c)
{
	if ((c == '\t' || c == '\n' || c == '\v' || c == '\f')
		|| (c == '\r' || c == ' '))
		return (1);
	else
		return (0);
}

long	*ft_atoi_check_int(const char *str, long *tab)
{
	int		i;
	int		sign;
	long	nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	tab[1] = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + str[i++] - '0';
	tab[0] = nbr * sign;
	if (nbr * sign > 2147483647 || nbr * sign < -2147483648)
		tab[1] = 0;
	return (tab);
}
