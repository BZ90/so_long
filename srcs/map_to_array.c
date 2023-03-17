/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:04:52 by bzawko            #+#    #+#             */
/*   Updated: 2022/09/08 16:05:19 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_consecutive_newlines(char *map)
{
	int	i;

	i = 0;
	if (!map)
	{
		write(2, "ERROR: unallocated space\n", 25);
		exit(EXIT_FAILURE);
	}
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			write(2, "Error: Empty Line\n", 18);
			return (-1);
		}
		++i;
	}
	return (0);
}

static char	*read_map(int fd)
{
	char	*ret;
	char	*buf;
	int		i;

	i = 1;
	ret = NULL;
	buf = malloc(21);
	while (i)
	{
		i = read(fd, buf, 20);
		if (i == -1)
		{
			free(buf);
			if (ret)
				free(ret);
			perror("ERROR: so_long: read");
			exit(EXIT_FAILURE);
		}
		buf[i] = '\0';
		ret = ft_strjoin(ret, buf);
	}
	free(buf);
	return (ret);
}

static int	is_ber(char *file)
{
	int	i;

	i = (ft_strlen(file) - 4);
	if (i < 0)
	{
		write(2, "ERROR: Invalid file type\n", 25);
		return (-1);
	}
	i = ft_strcmp(&file[i], ".ber");
	if (i == -1)
	{
		write(2, "ERROR: Invalid file type\n", 25);
		return (-1);
	}
	return (0);
}

char	**file_to_array(char *path)
{
	char	*map;
	char	**ret;
	int		fd;

	if (is_ber(path) == -1)
		exit(EXIT_FAILURE);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		perror("ERROR: so_long: open");
	if (fd < 0)
		exit(EXIT_FAILURE);
	map = read_map(fd);
	if (close(fd) == -1)
		perror("ERROR: so_long: close");
	if (map_consecutive_newlines(map) != 0)
	{
		free(map);
		exit(EXIT_FAILURE);
	}
	ret = ft_split(map, '\n');
	free(map);
	return (ret);
}
