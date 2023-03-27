/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:39:53 by mdemma            #+#    #+#             */
/*   Updated: 2022/03/21 13:47:47 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fake_libft.h"

//#include <ctype.h>
//#include <stdio.h>
/*ft_isdigit tests a char (overtyped by INT because can accept -1/EOF)
 * Returns a positive value if TRUE (if c is a digit) and 0 if FALSE)
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
