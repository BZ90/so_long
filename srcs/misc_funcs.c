/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:05:34 by bzawko            #+#    #+#             */
/*   Updated: 2022/09/14 12:49:57 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Compares two strings and returns 0 if identical

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	if (s1[i] != s2[i])
		return (-1);
	return (0);
}

// Returns length of string

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		++i;
	return (i);
}

// Duplicates a char *

char	*ft_strdup(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ret)
	{
		write(2, "ERROR: ft_strdup: malloc\n", 25);
		return (NULL);
	}
	while (str[i])
	{
		ret[i] = str[i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}

// Duplicates a char **

char	**dup_p_to_p(char **strs)
{
	char	**ret;
	int		i;

	i = 0;
	while (strs[i])
		++i;
	ret = malloc(sizeof(char *) * (i + 1));
	if (!ret)
	{
		write(2, "ERROR: dup_p_to_p: malloc\n", 26);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (strs[i])
	{
		ret[i] = ft_strdup(strs[i]);
		++i;
	}
	ret[i] = NULL;
	return (ret);
}

// Frees a char **

void	free_p_to_p(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		++i;
	}
	free(strs[i]);
	free(strs);
}
