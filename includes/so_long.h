/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:03:55 by bzawko            #+#    #+#             */
/*   Updated: 2022/09/20 15:20:41 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_stuff {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_coin;
	void	*img_path;
	void	*img_player;
	void	*img_wall;
	void	*img_exit;
	void	*img_enemy;
	void	*img_enemy2;
	void	*img_enemy3;
	char	**map;
	int		*coin_count;
	int		move_count;
}		t_stuff;

char	*ft_itoa(int n);
char	*ft_join_str(char *str1, char *str2);
char	*ft_strjoin(char *stat_str, char *buffer);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	**file_to_array(char *path);
char	**dup_p_to_p(char **strs);
char	next_to_open(char **map, int *pos);

int		animate(t_stuff *args);
int		p_to_p_len(char **p_to_p);
int		ft_strlen(char const *str);
int		ft_strcmp(const char *s1, const char *s2);
int		is_valid_map(char **map, int len);
int		is_valid_space(char **map, int i, int j);
int		valid_moves(char **map, int *pos);
int		check_paths(char **map, int *pos);
int		get_end_pos(char **map, int *pos, int count);
int		check_key_press(int key, t_stuff *args);
int		cross_clicked(t_stuff *args);
int		move_left(t_stuff *args);
int		move_right(t_stuff *args);
int		move_up(t_stuff *args);
int		move_down(t_stuff *args);
int		pick_move(char **map, int *pos);
int		pick_move2(char **map, int *pos);
int		is_valid_path(char **map, int *pos);
int		move(int *pos, int i, int j);

void	count_coins(t_stuff *args);
void	check_coins(t_stuff *args);
void	draw_exit(t_stuff *args);
void	error_and_exit(char *err_message);
void	get_start_pos(char **map, int *pos);
void	free_p_to_p(char **strs);
void	end_game(t_stuff *args, char *message);
void	shutdown(t_stuff *args, char *error);
void	draw_map(t_stuff *args);
void	draw_image(t_stuff *args, char *path, int x, int y);
void	draw_player_move(t_stuff *args, int *pos, int i, int j);

#endif
