/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:07:12 by bzawko            #+#    #+#             */
/*   Updated: 2022/09/20 15:14:38 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pick_image(t_stuff *args, int i, int j)
{
	if (args->map[i][j] == 'e')
		mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, \
				args->img_enemy, j * 32, i * 32);
	else if (args->map[i][j] == 'C')
		mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, \
				args->img_coin, j * 32, i * 32);
	else if (args->map[i][j] == 'E')
		mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, \
				args->img_exit, j * 32, i * 32);
	else if (args->map[i][j] == '1')
		mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, \
				args->img_wall, j * 32, i * 32);
	else if (args->map[i][j] == '0')
		mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, \
				args->img_path, j * 32, i * 32);
	else if (args->map[i][j] == 'P')
		mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, \
				args->img_player, j * 32, i * 32);
}

void	draw_map(t_stuff *args)
{
	int		i;
	int		j;

	i = 0;
	while (args->map[i] != NULL)
	{
		j = 0;
		while (args->map[i][j] != '\0')
		{
			pick_image(args, i, j);
			++j;
		}
		++i;
	}
}

void	assign_images(t_stuff *args)
{
	int	i;

	i = 0;
	args->img_coin = mlx_png_file_to_image(args->mlx_ptr, \
			"./images/coin.png", &i, &i);
	args->img_path = mlx_png_file_to_image(args->mlx_ptr, \
			"./images/path.png", &i, &i);
	args->img_player = mlx_png_file_to_image(args->mlx_ptr, \
			"./images/player.png", &i, &i);
	args->img_wall = mlx_png_file_to_image(args->mlx_ptr, \
			"./images/wall.png", &i, &i);
	args->img_exit = mlx_png_file_to_image(args->mlx_ptr, \
			"./images/exit_closed.png", &i, &i);
	args->img_enemy = mlx_png_file_to_image(args->mlx_ptr, \
			"./images/enemy.png", &i, &i);
	args->img_enemy2 = mlx_png_file_to_image(args->mlx_ptr, \
			"./images/enemy2.png", &i, &i);
	args->img_enemy3 = mlx_png_file_to_image(args->mlx_ptr, \
			"./images/enemy3.png", &i, &i);
	if (args->img_coin == NULL || args->img_path == NULL || \
			args->img_player == NULL || args->img_wall == NULL \
			|| args->img_exit == NULL || args->img_enemy == NULL \
			|| args->img_enemy2 == NULL || args->img_enemy3 == NULL)
		exit(write(2, "ERROR: Image broke\n", 19));
}

void	so_long(t_stuff *args)
{
	count_coins(args);
	args->mlx_ptr = mlx_init();
	if (args->mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	args->win_ptr = mlx_new_window(args->mlx_ptr, \
			ft_strlen(args->map[0]) * 32, \
			p_to_p_len(args->map) * 32, "so_long");
	if (args->win_ptr == NULL)
		exit(EXIT_FAILURE);
	assign_images(args);
	mlx_key_hook(args->win_ptr, &check_key_press, args);
	mlx_hook(args->win_ptr, 17, 0L, &cross_clicked, args);
	mlx_loop_hook(args->mlx_ptr, &animate, args);
	draw_map(args);
	mlx_loop(args->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_stuff	args;
	int		i;
	int		*pos;

	if (argc != 2)
		return (write(2, "ERROR: wrong arguments\n", 23));
	i = 4;
	pos = malloc(sizeof(int) * 4);
	if (!pos)
		return (write(2, "ERROR: so_long: malloc\n", 23));
	while (i-- != 0)
		pos[i] = 0;
	args.map = file_to_array(argv[1]);
	if (is_valid_map(args.map, ft_strlen(args.map[0])) != 0)
		return (write(2, "ERROR: Invalid Map\n", 19));
	if (check_paths(args.map, pos) == -1)
		return (write(2, "ERROR: No Valid Path\n", 21));
	free(pos);
	args.coin_count = malloc(sizeof (int));
	if (args.coin_count == NULL)
		return (write(2, "ERROR: malloc\n", 14));
	args.coin_count[0] = 0;
	args.move_count = 0;
	so_long(&args);
	return (0);
}
