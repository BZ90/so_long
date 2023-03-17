/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_funcs_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:32:50 by bzawko            #+#    #+#             */
/*   Updated: 2022/09/20 15:24:20 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cross_clicked(t_stuff *args)
{
	end_game(args, "You have clicked the exit button\n");
	return (0);
}

char	*ft_join_str(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	ret = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!ret)
		error_and_exit("ERROR: so_long: malloc\n");
	i = -1;
	j = 0;
	while (str1[++i])
		ret[i] = str1[i];
	while (str2[j])
		ret[i++] = str2[j++];
	ret[ft_strlen(str1) + ft_strlen(str2)] = '\0';
	free(str2);
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		n2;

	len = 0;
	n2 = n;
	if (n2 == 0)
		len = 1;
	while (n2 >= 1)
	{
		++len;
		n2 /= 10;
	}
	ret = malloc(len + 1);
	if (!ret)
		exit(write(2, "ERROR: malloc\n", 14));
	ret[len] = '\0';
	if (n == 0)
		ret[0] = '0';
	while (n >= 1)
	{
		ret[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}

static void	draw_animation(t_stuff *args, int frame, int i, int j)
{
	if ((frame >= 0 && frame <= 29) || (frame >= 60 && frame <= 89))
		mlx_put_image_to_window(args->mlx_ptr, \
				args->win_ptr, args->img_enemy, j * 32, i * 32);
	else if (frame >= 30 && frame <= 59)
		mlx_put_image_to_window(args->mlx_ptr, \
				args->win_ptr, args->img_enemy2, j * 32, i * 32);
	else if (frame >= 90 && frame <= 119)
		mlx_put_image_to_window(args->mlx_ptr, \
				args->win_ptr, args->img_enemy3, j * 32, i * 32);
}

int	animate(t_stuff *args)
{
	int			i;
	int			j;
	static int	frame;

	if (frame >= 200)
		frame = 0;
	i = -1;
	while (args->map[++i] != NULL)
	{
		j = 0;
		while (args->map[i][j] != '\0')
		{
			if (args->map[i][j] == 'e')
			{
				draw_animation(args, frame, i, j);
			}
			++j;
		}
	}
	return (++frame);
}
