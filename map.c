/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:44:38 by disantam          #+#    #+#             */
/*   Updated: 2024/01/18 14:23:39 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, int *cols)
{
	if (map[x][y] != '0' && map[x][y] != 'C'
		&& map[x][y] != 'E' && map[x][y] != 'P')
		return ;
	if (map[x][y] == '1' || map[x][y] == '2')
		return ;
	if (map[x][y] == 'C' || map[x][y] == 'E')
		*cols += 1;
	if (map[x][y] == '0')
		map[x][y] = 'O';
	if (map[x][y] == 'P')
		map[x][y] = '4';
	if (map[x][y] == 'E')
		map[x][y] = '3';
	if (map[x][y] == 'C')
		map[x][y] = '2';
	flood_fill(map, x + 1, y, cols);
	flood_fill(map, x - 1, y, cols);
	flood_fill(map, x, y + 1, cols);
	flood_fill(map, x, y - 1, cols);
}

void	test_map(t_map *map)
{
	int	x;
	int	y;
	int	cols;

	x = -1;
	cols = 0;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y] != '\0')
		{
			if (map->map[x][y] == 'P')
			{
				flood_fill(map->map, x, y, &cols);
			}
		}
	}
	if (cols != map->c[0] + map->c[2])
	{
		ft_map_error(map, "El mapa no tiene un camino valido");
	}
}

void	check_line(t_map *map, int len, int x, int y)
{
	if (map->map[x][0] != '1')
		ft_map_error(map, "Falta un muro");
	while (map->map[x][++y + 1] != '\0')
	{
		if (map->map[x][y] != '0' && map->map[x][y] != 'E'
			&& map->map[x][y] != 'P' && map->map[x][y] != 'C'
			&& map->map[x][y] != '1')
			ft_map_error(map, "Caracter invalido");
		if (map->map[x][y] == 'E')
			map->c[0] += 1;
		if (map->map[x][y] == 'P')
		{
			map->p_x = x;
			map->p_y = y;
			map->c[1] += 1;
		}
		if (map->map[x][y] == 'C')
		{
			map->c[2] += 1;
		}
	}
	if (map->map[x][y] != '1')
		ft_map_error(map, "Falta un muro");
	if (y + 1 != len)
		ft_map_error(map, "El mapa no es rectangular");
}

void	check_map(t_map *map)
{
	int	y;
	int	x;
	int	len;

	y = -1;
	x = 0;
	while (map->map[x][++y] != '\0')
		if (map->map[x][y] != '1')
			ft_map_error(map, "Problema con los muros");
	len = y;
	map->size_y = y * 16;
	y = 0;
	while (map->map[++x + 1] != NULL)
	{
		check_line(map, len, x, y);
	}
	y = -1;
	while (map->map[x][++y])
		if (map->map[x][y] != '1')
			ft_map_error(map, "Problema con los muros");
	if (len != y || map->c[0] != 1
		|| map->c[1] != 1 || map->c[2] == 0)
		ft_map_error(map, "El mapa no cumple los requisitos");
	map->size_x = (x + 1) * 16;
}

void	parse_map(t_map *map, int fd)
{
	char	*tmp;
	char	*line;

	tmp = ft_calloc(1, sizeof(char));
	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
	while (line)
	{
		tmp = ft_join(tmp, line);
		if (!tmp)
			exit(EXIT_FAILURE);
		line = get_next_line(fd);
	}
	map -> map = ft_split(tmp, '\n');
	free(tmp);
	if (!map->map)
		exit(EXIT_FAILURE);
}
