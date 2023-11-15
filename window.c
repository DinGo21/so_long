/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:14:14 by disantam          #+#    #+#             */
/*   Updated: 2023/11/08 15:43:09 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_wall(t_data *data, t_map *map, int x, int y)
{
	int	ins;

	x = -1;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y])
		{
			if (map->map[x][y] == '1')
			{
				ins = mlx_image_to_window(data->mlx, data->imgs[1],
						y * 16, x * 16);
				if (ins < 0)
					ft_mlx_error(data);
				data->imgs[1]->instances[ins].z = 5;
			}
		}
	}
}

void	render_player(t_data *data, t_map *map, int x, int y)
{
	int	ins;

	x = -1;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y])
		{
			if (map->map[x][y] == '4')
			{
				ins = mlx_image_to_window(data->mlx, data->imgs[4],
						y * 16, x * 16);
				if (ins < 0)
					ft_mlx_error(data);
				data->imgs[4]->instances[ins].z = 4;
			}
		}
	}
}

void	render_exit(t_data *data, t_map *map, int x, int y)
{
	int	ins;

	x = -1;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y])
		{
			if (map->map[x][y] == '3')
			{
				ins = mlx_image_to_window(data->mlx, data->imgs[3],
						y * 16, x * 16);
				if (ins < 0)
					ft_mlx_error(data);
				data->imgs[3]->instances[ins].z = 3;
			}
		}
	}
}

void	render_collectables(t_data *data, t_map *map, int x, int y)
{
	int	ins;

	x = -1;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y])
		{
			if (map->map[x][y] == '2')
			{
				ins = mlx_image_to_window(data->mlx, data->imgs[2],
						y * 16, x * 16);
				if (ins < 0)
					ft_mlx_error(data);
				map->cols[ins] = malloc(sizeof(t_cols));
				if (!map->cols[ins])
					ft_mlx_error(data);
				data->imgs[2]->instances[ins].z = 2;
				map->cols[ins]->x = x;
				map->cols[ins]->y = y;
				map->cols[ins]->in = ins;
			}
		}
	}
}

void	render_floor(t_data *data, t_map *map, int x, int y)
{
	int	ins;

	x = -1;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y])
		{
			if (map->map[x][y] == 'O' || map->map[x][y] == '2'
				|| map->map[x][y] == '3' || map->map[x][y] == '4')
			{
				ins = mlx_image_to_window(data->mlx, data->imgs[0],
						y * 16, x * 16);
				if (ins < 0)
					ft_mlx_error(data);
				data->imgs[0]->instances[ins].z = 1;
			}
		}
	}
}
