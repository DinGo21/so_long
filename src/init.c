/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:23:45 by disantam          #+#    #+#             */
/*   Updated: 2023/11/09 16:12:48 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_window(t_data *data, t_map *map)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	render_floor(data, map, x, y);
	render_collectables(data, map, x, y);
	render_exit(data, map, x, y);
	render_player(data, map, x, y);
	render_wall(data, map, x, y);
}

void	load_textures(t_data *data)
{
	data->textures[0] = mlx_load_png("./sprites/floor.png");
	if (!data ->textures[0])
		ft_mlx_error(data);
	data->textures[1] = mlx_load_png("./sprites/wall.png");
	if (!data->textures[1])
		ft_mlx_error(data);
	data->textures[2] = mlx_load_png("./sprites/key.png");
	if (!data->textures[2])
		ft_mlx_error(data);
	data->textures[3] = mlx_load_png("./sprites/chest.png");
	if (!data->textures[3])
		ft_mlx_error(data);
	data->textures[4] = mlx_load_png("./sprites/knight.png");
	if (!data->textures[4])
		ft_mlx_error(data);
}

void	init_mlx(t_data *data, t_map *map)
{
	int	i;

	data->mlx = mlx_init(map->size_y, map->size_x, "testing :)", true);
	if (!data->mlx)
		ft_mlx_error(data);
	load_textures(data);
	i = -1;
	while (++i < 5)
	{
		data->imgs[i] = mlx_texture_to_image(data->mlx, data->textures[i]);
		if (!data->imgs[i])
			ft_mlx_error(data);
	}
	data->moves = 0;
}

void	init_map(t_map *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	map->c[0] = 0;
	map->c[1] = 0;
	map->c[2] = 0;
	map->cols = NULL;
	parse_map(map, fd);
	close(fd);
	check_map(map);
	test_map(map);
	map->cols = malloc(sizeof(t_cols *) * (map->c[2] + 1));
	map->cols[map->c[2]] = NULL;
}
