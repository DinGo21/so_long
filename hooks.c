/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:52:05 by disantam          #+#    #+#             */
/*   Updated: 2023/11/09 12:37:37 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyhook_up(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	if (map->map[map->p_x - 1][map->p_y] != '1')
	{
		map->p_x -= 1;
		data->imgs[4]->instances[0].y -= 16;
		data->moves++;
		ft_printf("Movimientos: %i\n", data->moves);
	}
	if (map->map[map->p_x][map->p_y] == '2')
	{
		while (map->p_x != map->cols[i]->x || map->p_y != map->cols[i]->y)
			i++;
		if (data->imgs[2]->instances[map->cols[i]->in].z != 0)
			map->c[2] -= 1;
		data->imgs[2]->instances[map->cols[i]->in].z = 0;
	}
	if (map->map[map->p_x][map->p_y] == '3')
		if (map->c[2] <= 0)
			mlx_close_window(data->mlx);
}

void	keyhook_down(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	if (map->map[map->p_x + 1][map->p_y] != '1')
	{
		map->p_x += 1;
		data->imgs[4]->instances[0].y += 16;
		data->moves++;
		ft_printf("Movimientos: %i\n", data->moves);
	}
	if (map->map[map->p_x][map->p_y] == '2')
	{
		while (map->p_x != map->cols[i]->x || map->p_y != map->cols[i]->y)
			i++;
		if (data->imgs[2]->instances[map->cols[i]->in].z != 0)
			map->c[2] -= 1;
		data->imgs[2]->instances[map->cols[i]->in].z = 0;
	}
	if (map->map[map->p_x][map->p_y] == '3')
		if (map->c[2] <= 0)
			mlx_close_window(data->mlx);
}

void	keyhook_left(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	if (map->map[map->p_x][map->p_y - 1] != '1')
	{
		map->p_y -= 1;
		data->imgs[4]->instances[0].x -= 16;
		data->moves++;
		ft_printf("Movimientos: %i\n", data->moves);
	}
	if (map->map[map->p_x][map->p_y] == '2')
	{
		while (map->p_x != map->cols[i]->x || map->p_y != map->cols[i]->y)
			i++;
		if (data->imgs[2]->instances[map->cols[i]->in].z != 0)
			map->c[2] -= 1;
		data->imgs[2]->instances[map->cols[i]->in].z = 0;
	}
	if (map->map[map->p_x][map->p_y] == '3')
		if (map->c[2] <= 0)
			mlx_close_window(data->mlx);
}

void	keyhook_right(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	if (map->map[map->p_x][map->p_y + 1] != '1')
	{
		map->p_y += 1;
		data->imgs[4]->instances[0].x += 16;
		data->moves++;
		ft_printf("Movimientos: %i\n", data->moves);
	}
	if (map->map[map->p_x][map->p_y] == '2')
	{
		while (map->p_x != map->cols[i]->x || map->p_y != map->cols[i]->y)
			i++;
		if (data->imgs[2]->instances[map->cols[i]->in].z != 0)
			map->c[2] -= 1;
		data->imgs[2]->instances[map->cols[i]->in].z = 0;
	}
	if (map->map[map->p_x][map->p_y] == '3')
		if (map->c[2] <= 0)
			mlx_close_window(data->mlx);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;
	t_data	*data;

	data = param;
	map = &data->map;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		keyhook_up(data, map);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		keyhook_down(data, map);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		keyhook_left(data, map);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		keyhook_right(data, map);
}
