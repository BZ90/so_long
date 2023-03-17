/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_funcs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:06:26 by bzawko            #+#    #+#             */
/*   Updated: 2022/09/20 12:54:32 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_and_exit(char *err_message)
{
	write(2, err_message, ft_strlen(err_message));
	exit(EXIT_FAILURE);
}

int	is_valid_space(char **map, int i, int j)
{
	if (i < 0 || j < 0)
		return (0);
	if (!map[i])
		return (0);
	if (map[i][j] == 'C' || map[i][j] == '0')
		return (1);
	else if (map[i][j] == 'i')
		return (2);
	else if (map[i][j] == 'j')
		return (3);
	else if (map[i][j] == 'k')
		return (4);
	else if (map[i][j] == 'l')
		return (5);
	else if (map[i][j] == 'm')
		return (6);
	else
		return (0);
}

int	valid_moves(char **map, int *pos)
{
	int	ret;

	ret = 0;
	if (is_valid_space(map, pos[0] - 1, pos[1]))
		++ret;
	if (is_valid_space(map, pos[0] + 1, pos[1]))
		++ret;
	if (is_valid_space(map, pos[0], pos[1] - 1))
		++ret;
	if (is_valid_space(map, pos[0], pos[1] + 1))
		++ret;
	return (ret);
}

void	get_start_pos(char **map, int *pos)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos[0] = i;
				pos[1] = j;
				return ;
			}
			++j;
		}
		++i;
	}
}

int	get_end_pos(char **map, int *pos, int count)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				if (count < 1)
				{
					pos[2] = i;
					pos[3] = j;
					return (0);
				}
				else
					--count;
			}
			++j;
		}
		++i;
	}
	return (-1);
}
