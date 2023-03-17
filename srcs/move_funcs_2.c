/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_funcs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:03 by bzawko            #+#    #+#             */
/*   Updated: 2022/09/20 15:27:15 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_left(t_stuff *args)
{
	int	*pos;

	pos = malloc(sizeof (int) * 2);
	if (!pos)
		shutdown(args, "ERROR: malloc\n");
	get_start_pos(args->map, pos);
	if (args->map[pos[0]][pos[1] - 1] == 'E' && args->coin_count[0] == 0)
	{
		free(pos);
		end_game(args, "Congratulations, you won the game!\n");
	}
	if (args->map[pos[0]][pos[1] - 1] == '0' || \
			args->map[pos[0]][pos[1] - 1] == 'C')
	{
		if (args->map[pos[0]][pos[1] - 1] == 'C')
			check_coins(args);
		draw_player_move(args, pos, pos[0], pos[1] - 1);
		free(pos);
		return (1);
	}
	if (args->map[pos[0]][pos[1] - 1] == 'e')
		end_game(args, "You have died\n");
	free(pos);
	return (0);
}

int	move_right(t_stuff *args)
{
	int	*pos;

	pos = malloc(sizeof (int) * 2);
	if (!pos)
		shutdown(args, "ERROR: malloc\n");
	get_start_pos(args->map, pos);
	if (args->map[pos[0]][pos[1] + 1] == 'E' && args->coin_count[0] == 0)
	{
		free(pos);
		end_game(args, "Congratulations, you won the game!\n");
	}
	if (args->map[pos[0]][pos[1] + 1] == '0' || \
			args->map[pos[0]][pos[1] + 1] == 'C')
	{
		if (args->map[pos[0]][pos[1] + 1] == 'C')
			check_coins(args);
		draw_player_move(args, pos, pos[0], pos[1] + 1);
		free(pos);
		return (1);
	}
	if (args->map[pos[0]][pos[1] + 1] == 'e')
		end_game(args, "You have died\n");
	free(pos);
	return (0);
}

int	move_up(t_stuff *args)
{
	int	*pos;

	pos = malloc(sizeof (int) * 2);
	if (!pos)
		shutdown(args, "ERROR: malloc\n");
	get_start_pos(args->map, pos);
	if (args->map[pos[0] - 1][pos[1]] == 'E' && args->coin_count[0] == 0)
	{
		free(pos);
		end_game(args, "Congratulations, you won the game!\n");
	}
	if (args->map[pos[0] - 1][pos[1]] == '0' || \
			args->map[pos[0] - 1][pos[1]] == 'C')
	{
		if (args->map[pos[0] - 1][pos[1]] == 'C')
			check_coins(args);
		draw_player_move(args, pos, pos[0] - 1, pos[1]);
		free(pos);
		return (1);
	}
	if (args->map[pos[0] - 1][pos[1]] == 'e')
		end_game(args, "You have died\n");
	free(pos);
	return (0);
}

int	move_down(t_stuff *args)
{
	int	*pos;

	pos = malloc(sizeof (int) * 2);
	if (!pos)
		shutdown(args, "ERROR: malloc\n");
	get_start_pos(args->map, pos);
	if (args->map[pos[0] + 1][pos[1]] == 'E' && args->coin_count[0] == 0)
	{
		free(pos);
		end_game(args, "Congratulations, you won the game!\n");
	}
	if (args->map[pos[0] + 1][pos[1]] == '0' || \
			args->map[pos[0] + 1][pos[1]] == 'C')
	{
		if (args->map[pos[0] + 1][pos[1]] == 'C')
			check_coins(args);
		draw_player_move(args, pos, pos[0] + 1, pos[1]);
		free(pos);
		return (1);
	}
	if (args->map[pos[0] + 1][pos[1]] == 'e')
		end_game(args, "You have died\n");
	free(pos);
	return (0);
}
