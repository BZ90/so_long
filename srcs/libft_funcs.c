/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:04:09 by bzawko            #+#    #+#             */
/*   Updated: 2022/09/08 16:04:11 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *stat_str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!stat_str)
	{
		stat_str = malloc(1);
		if (!stat_str)
			error_and_exit("ERROR: so_long: malloc\n");
		stat_str[0] = '\0';
	}
	ret = malloc(ft_strlen(stat_str) + ft_strlen(buffer) + 1);
	if (!ret)
		error_and_exit("ERROR: so_long: malloc\n");
	i = -1;
	j = 0;
	while (stat_str[++i])
		ret[i] = stat_str[i];
	while (buffer[j])
		ret[i++] = buffer[j++];
	ret[ft_strlen(stat_str) + ft_strlen(buffer)] = '\0';
	free(stat_str);
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	if (i < start)
		len = 0;
	ret = malloc(len + 1);
	if (!ret)
		error_and_exit("ERROR: so_long: malloc\n");
	i = 0;
	while (i < len && s[start])
	{
		ret[i] = s[start];
		++i;
		++start;
	}
	ret[i] = '\0';
	return (ret);
}

static int	count_splits(char const *s, char c)
{
	int	splits;
	int	i;
	int	len;

	splits = 0;
	len = 0;
	i = -1;
	while (s[len])
		++len;
	while (++i < len)
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			++splits;
	return (splits);
}

static void	fill_splits(char **array, char const *s, int splits, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	array[splits] = NULL;
	while (i < splits)
	{
		if (s[j] == c)
			j++;
		else
		{
			k = 0;
			while (s[j + k] != '\0' && s[j + k] != c)
				++k;
			array[i] = ft_substr(s, j, k);
			j += k;
			++i;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (count_splits(s, c) + 1));
	if (!array)
		exit(EXIT_FAILURE);
	fill_splits(array, s, count_splits(s, c), c);
	return (array);
}
