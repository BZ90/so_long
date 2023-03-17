/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:04:25 by bzawko            #+#    #+#             */
/*   Updated: 2022/09/20 15:20:54 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check if you're next to the end position

static int	at_end(int *pos)
{
	if ((pos[0] == (pos[2] - 1) && pos[1] == pos[3]) || \
			(pos[0] == (pos[2] + 1) && pos[1] == pos[3]) || \
			(pos[0] == pos[2] && pos[1] == (pos[3] - 1)) || \
			(pos[0] == pos[2] && pos[1] == (pos[3] + 1)))
		return (1);
	else
		return (-1);
}

// Picks the move to be performed then sends it to move

int	pick_move2(char **map, int *pos)
{
	if (is_valid_space(map, pos[0] - 1, pos[1]) == 4)
		return (move(pos, pos[0] - 1, pos[1]));
	if (is_valid_space(map, pos[0] + 1, pos[1]) == 4)
		return (move(pos, pos[0] + 1, pos[1]));
	if (is_valid_space(map, pos[0], pos[1] - 1) == 4)
		return (move(pos, pos[0], pos[1] - 1));
	if (is_valid_space(map, pos[0], pos[1] + 1) == 4)
		return (move(pos, pos[0], pos[1] + 1));
	if (is_valid_space(map, pos[0] - 1, pos[1]) == 5)
		return (move(pos, pos[0] - 1, pos[1]));
	if (is_valid_space(map, pos[0] + 1, pos[1]) == 5)
		return (move(pos, pos[0] + 1, pos[1]));
	if (is_valid_space(map, pos[0], pos[1] - 1) == 5)
		return (move(pos, pos[0], pos[1] - 1));
	if (is_valid_space(map, pos[0], pos[1] + 1) == 5)
		return (move(pos, pos[0], pos[1] + 1));
	if (is_valid_space(map, pos[0] - 1, pos[1]) == 6)
		return (move(pos, pos[0] - 1, pos[1]));
	if (is_valid_space(map, pos[0] + 1, pos[1]) == 6)
		return (move(pos, pos[0] + 1, pos[1]));
	if (is_valid_space(map, pos[0], pos[1] - 1) == 6)
		return (move(pos, pos[0], pos[1] - 1));
	if (is_valid_space(map, pos[0], pos[1] + 1) == 6)
		return (move(pos, pos[0], pos[1] + 1));
	return (-1);
}

int	pick_move(char **map, int *pos)
{
	if (is_valid_space(map, pos[0] - 1, pos[1]) == 1)
		return (move(pos, pos[0] - 1, pos[1]));
	if (is_valid_space(map, pos[0] + 1, pos[1]) == 1)
		return (move(pos, pos[0] + 1, pos[1]));
	if (is_valid_space(map, pos[0], pos[1] - 1) == 1)
		return (move(pos, pos[0], pos[1] - 1));
	if (is_valid_space(map, pos[0], pos[1] + 1) == 1)
		return (move(pos, pos[0], pos[1] + 1));
	if (is_valid_space(map, pos[0] - 1, pos[1]) == 2)
		return (move(pos, pos[0] - 1, pos[1]));
	if (is_valid_space(map, pos[0] + 1, pos[1]) == 2)
		return (move(pos, pos[0] + 1, pos[1]));
	if (is_valid_space(map, pos[0], pos[1] - 1) == 2)
		return (move(pos, pos[0], pos[1] - 1));
	if (is_valid_space(map, pos[0], pos[1] + 1) == 2)
		return (move(pos, pos[0], pos[1] + 1));
	if (is_valid_space(map, pos[0] - 1, pos[1]) == 3)
		return (move(pos, pos[0] - 1, pos[1]));
	if (is_valid_space(map, pos[0] + 1, pos[1]) == 3)
		return (move(pos, pos[0] + 1, pos[1]));
	if (is_valid_space(map, pos[0], pos[1] - 1) == 3)
		return (move(pos, pos[0], pos[1] - 1));
	if (is_valid_space(map, pos[0], pos[1] + 1) == 3)
		return (move(pos, pos[0], pos[1] + 1));
	return (pick_move2(map, pos));
}

// Check if theirs a valid path by trying to follow the
// path to the end position

int	is_valid_path(char **map, int *pos)
{
	int	i;

	map = dup_p_to_p(map);
	if (!map)
		return (-2);
	while (valid_moves(map, pos) != 0)
	{
		if (at_end(pos) == 1)
			break ;
		if (valid_moves(map, pos) > 1)
		{
			map[pos[0]][pos[1]] = next_to_open(map, pos);
			pick_move(map, pos);
		}
		else if (valid_moves(map, pos) == 1)
		{
			map[pos[0]][pos[1]] = '1';
			pick_move(map, pos);
		}
	}
	i = at_end(pos);
	free_p_to_p(map);
	return (i);
}

// Runs is_valid_path once for each end position

int	check_paths(char **map, int *pos)
{
	int	count;

	count = 0;
	get_start_pos(map, pos);
	while (get_end_pos(map, pos, count) != -1)
	{
		if (is_valid_path(map, pos) == -1)
			return (-1);
		++count;
		get_start_pos(map, pos);
	}
	return (0);
}
