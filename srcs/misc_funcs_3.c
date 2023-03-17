/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_funcs_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 07:59:32 by bzawko            #+#    #+#             */
/*   Updated: 2022/09/20 15:23:45 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	next_to_open2(char **map, int *pos)
{
	if (map[pos[0] - 1][pos[1]] == 'j')
		return ('k');
	if (map[pos[0]][pos[1] - 1] == 'j')
		return ('k');
	if (map[pos[0] + 1][pos[1]] == 'j')
		return ('k');
	if (map[pos[0]][pos[1] + 1] == 'j')
		return ('k');
	if (map[pos[0] - 1][pos[1]] == 'k')
		return ('l');
	if (map[pos[0]][pos[1] - 1] == 'k')
		return ('l');
	if (map[pos[0] + 1][pos[1]] == 'k')
		return ('l');
	if (map[pos[0]][pos[1] + 1] == 'k')
		return ('l');
	if (map[pos[0] - 1][pos[1]] == 'l')
		return ('m');
	if (map[pos[0]][pos[1] - 1] == 'l')
		return ('m');
	if (map[pos[0] + 1][pos[1]] == 'l')
		return ('m');
	if (map[pos[0]][pos[1] + 1] == 'l')
		return ('m');
	return ('1');
}

char	next_to_open(char **map, int *pos)
{
	if (pos[0] != 0)
	{
		if (map[pos[0] - 1][pos[1]] == '0' || map[pos[0] - 1][pos[1]] == 'C')
			return ('i');
	}
	if (pos[1] != 0)
	{
		if (map[pos[0]][pos[1] - 1] == '0' || map[pos[0]][pos[1] - 1] == 'C')
			return ('i');
	}
	if (map[pos[0] + 1][pos[1]] == '0' || map[pos[0] + 1][pos[1]] == 'C')
		return ('i');
	if (map[pos[0]][pos[1] + 1] == '0' || map[pos[0]][pos[1] + 1] == 'C')
		return ('i');
	if (map[pos[0] - 1][pos[1]] == 'i')
		return ('j');
	if (map[pos[0]][pos[1] - 1] == 'i')
		return ('j');
	if (map[pos[0] + 1][pos[1]] == 'i')
		return ('j');
	if (map[pos[0]][pos[1] + 1] == 'i')
		return ('j');
	return (next_to_open2(map, pos));
}

void	count_coins(t_stuff *args)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;
	while (args->map[i] != NULL)
	{
		j = 0;
		while (args->map[i][j] != '\0')
		{
			if (args->map[i][j] == 'C')
				ret += 1;
			++j;
		}
		++i;
	}
	args->coin_count[0] = ret;
}

void	shutdown(t_stuff *args, char *error)
{
	mlx_destroy_image(args->mlx_ptr, args->img_coin);
	mlx_destroy_image(args->mlx_ptr, args->img_path);
	mlx_destroy_image(args->mlx_ptr, args->img_player);
	mlx_destroy_image(args->mlx_ptr, args->img_wall);
	mlx_destroy_image(args->mlx_ptr, args->img_exit);
	mlx_destroy_image(args->mlx_ptr, args->img_enemy);
	mlx_destroy_image(args->mlx_ptr, args->img_enemy2);
	mlx_destroy_image(args->mlx_ptr, args->img_enemy3);
	free(args->coin_count);
	free_p_to_p(args->map);
	if (error != NULL)
		write(2, error, ft_strlen(error));
	mlx_clear_window(args->mlx_ptr, args->win_ptr);
	mlx_destroy_window(args->mlx_ptr, args->win_ptr);
	exit(0);
}

void	end_game(t_stuff *args, char *message)
{
	mlx_destroy_image(args->mlx_ptr, args->img_coin);
	mlx_destroy_image(args->mlx_ptr, args->img_path);
	mlx_destroy_image(args->mlx_ptr, args->img_player);
	mlx_destroy_image(args->mlx_ptr, args->img_wall);
	mlx_destroy_image(args->mlx_ptr, args->img_exit);
	mlx_destroy_image(args->mlx_ptr, args->img_enemy);
	mlx_destroy_image(args->mlx_ptr, args->img_enemy2);
	mlx_destroy_image(args->mlx_ptr, args->img_enemy3);
	free_p_to_p(args->map);
	free(args->coin_count);
	mlx_destroy_window(args->mlx_ptr, args->win_ptr);
	write(1, message, ft_strlen(message));
	exit(0);
}
