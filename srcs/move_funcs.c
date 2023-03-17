/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:05:25 by bzawko            #+#    #+#             */
/*   Updated: 2022/09/20 15:27:24 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_exit(t_stuff *args)
{
	int	i;
	int	j;

	i = 0;
	while (args->map[i] != NULL)
	{
		j = 0;
		while (args->map[i][j] != '\0')
		{
			if (args->map[i][j] == 'E')
			{
				mlx_put_image_to_window(args->mlx_ptr, \
						args->win_ptr, args->img_exit, j * 32, i * 32);
				return ;
			}
			++j;
		}
		++i;
	}
}

void	check_coins(t_stuff *args)
{
	int	i;

	i = 0;
	--args->coin_count[0];
	if (args->coin_count[0] == 0)
	{
		mlx_destroy_image(args->mlx_ptr, args->img_exit);
		args->img_exit = mlx_png_file_to_image(args->mlx_ptr, \
				"./images/exit_open.png", &i, &i);
		draw_exit(args);
	}
}

void	draw_player_move(t_stuff *args, int *pos, int i, int j)
{
	args->map[pos[0]][pos[1]] = '0';
	args->map[i][j] = 'P';
	mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, \
			args->img_path, pos[1] * 32, pos[0] * 32);
	mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, \
			args->img_player, j * 32, i * 32);
}

// W = 13, A = 0, S = 1, D = 2, ESC = 53

void	draw_each_key(t_stuff *args)
{
	char	*str;

	str = ft_join_str("Moves: ", ft_itoa(args->move_count));
	mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, \
			args->img_wall, 0, 0);
	mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, \
			args->img_wall, 32, 0);
	mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, \
			args->img_wall, 64, 0);
	mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, \
			args->img_wall, 96, 0);
	mlx_string_put(args->mlx_ptr, args->win_ptr, 0, 12, 0xFFFFFF, str);
	free(str);
}

int	check_key_press(int key, t_stuff *args)
{
	if (key == 53)
		shutdown(args, NULL);
	if (key == 0)
		args->move_count += move_left(args);
	if (key == 1)
		args->move_count += move_down(args);
	if (key == 2)
		args->move_count += move_right(args);
	if (key == 13)
		args->move_count += move_up(args);
	draw_each_key(args);
	return (0);
}
