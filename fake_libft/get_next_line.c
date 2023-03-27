/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:21:39 by mdemma            #+#    #+#             */
/*   Updated: 2022/04/21 14:23:23 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake_libft.h"

char	*ft_save(char *not_printed, int len)
{
	char	*tmp;

	tmp = ft_strdup(not_printed + len);
	free(not_printed);
	not_printed = tmp;
	return (not_printed);
}

char	*ft_strstock_save(char **not_printed)
{
	int		len;
	char	*line;

	len = 0;
	while ((*not_printed)[len] != '\0' && (*not_printed)[len] != '\n')
		len++;
	if ((*not_printed)[len] == '\0' && len == 0)
	{
		*not_printed = NULL;
		free(*not_printed);
		return (NULL);
	}
	line = ft_substr(*not_printed, 0, len + 1);
	if ((*not_printed)[len] == '\n')
		*not_printed = ft_save(*not_printed, len + 1);
	else if ((*not_printed)[len] == '\0')
		*not_printed = ft_save(*not_printed, len);
	return (line);
}

char	*ft_manage_outputs(int n, char **not_printed)
{
	if (n <= 0)
	{
		if (*(*not_printed) != '\0')
		{
			return (ft_strstock_save(not_printed));
		}
		else
		{
			free (*not_printed);
			*not_printed = NULL;
			return (NULL);
		}
	}
	else
	{
		return (ft_strstock_save(not_printed));
	}
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	int			n;
	static char	*not_printed[FOPEN_MAX];

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (not_printed[fd] == NULL)
	{
			n = read(fd, buf, BUFFER_SIZE);
			buf[n] = '\0';
			not_printed[fd] = ft_strdup(buf);
	}
	while (!(ft_strchr(not_printed[fd], '\n')))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == 0)
			break ;
		buf[n] = '\0';
		tmp = ft_strjoin(not_printed[fd], buf);
		free(not_printed[fd]);
		not_printed[fd] = tmp;
	}
	return (ft_manage_outputs(n, &(not_printed[fd])));
}
