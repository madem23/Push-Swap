/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdemma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:23:27 by mdemma            #+#    #+#             */
/*   Updated: 2022/03/25 17:25:11 by mdemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake_libft.h"

/* Allocate with malloc and returns a tab of strings
The tab is terminated by NULL.
*/
static char	**ft_malloc_error(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word_count++;
		i++;
	}
	return (word_count);
}

static char	*ft_cut_str(char const *s, int start, int end)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (start < end)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

char	**fill_tab(int start, char **split, char c, char const *s)
{
	int	i;
	int	end;

	i = 0;
	while (s[start])
	{
		end = start;
		while (s[end] && s[end] != c)
			end++;
		split[i] = ft_cut_str(s, start, end);
		if (!(split[i++]))
			return (ft_malloc_error(split));
		while (s[end] && s[end] == c)
			end++;
		start = end;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		start;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(split) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	start = 0;
	while (s[start] == c && c != '\0')
		start++;
	split = fill_tab(start, split, c, s);
	if (!split)
		return (NULL);
	return (split);
}
