/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:04:43 by bzawko            #+#    #+#             */
/*   Updated: 2022/09/08 16:04:44 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_tile(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || \
			c == 'P' || c == 'e')
		return (1);
	else
		return (-1);
}

static int	are_counts_correct(int play_count, int exit_count, int coin_count)
{
	if (play_count != 1)
		return (-2);
	if (exit_count != 1)
		return (-3);
	if (coin_count == 0)
		return (-4);
	return (0);
}

static int	is_map_allowed(char **map, int i, int j, int play_count)
{
	int	exit_count;
	int	coin_count;

	exit_count = 0;
	coin_count = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (-5);
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				play_count += 1;
			if (map[i][j] == 'E')
				exit_count += 1;
			if (map[i][j] == 'C')
				coin_count += 1;
			if (is_valid_tile(map[i][j]) == -1)
				return (-1);
			++j;
		}
		j = 0;
		++i;
	}
	return (are_counts_correct(play_count, exit_count, coin_count));
}

int	is_valid_map(char **map, int len)
{
	int	i;
	int	j;

	i = is_map_allowed(map, 0, 0, 0);
	if (i != 0)
		return (i);
	while (map[i])
		++i;
	if (i <= 2)
		return (-1);
	if (len <= 2)
		return (-1);
	i = 0;
	while (map[++i])
		if (len != ft_strlen(map[i]))
			return (-1);
	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1' || map[0][j] != '1')
			return (-1);
		++j;
	}
	return (0);
}
