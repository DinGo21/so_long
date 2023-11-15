/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:21:50 by disantam          #+#    #+#             */
/*   Updated: 2023/11/09 12:31:14 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (map->map)
	{
		i = -1;
		while (map->map[++i])
		{
			if (map->map[i])
				free(map->map[i]);
		}
		free(map->map);
	}
	if (map->cols)
	{
		i = -1;
		while (map->cols[++i])
		{
			if (map->cols[i])
				free(map->cols[i]);
		}
		free(map->cols);
	}
}

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (data->imgs[i])
		{
			mlx_delete_image(data->mlx, data->imgs[i]);
		}
		if (data->textures[i])
		{
			mlx_delete_texture(data->textures[i]);
		}
	}
	free_map(&data->map);
}

void	ft_mlx_error(t_data *data)
{
	const char	*error;

	error = mlx_strerror(mlx_errno);
	write(STDERR_FILENO, error, ft_strlen(error));
	free_data(data);
	exit(EXIT_FAILURE);
}

void	ft_map_error(t_map *map, char *text)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, text, ft_strlen(text));
	free_map(map);
	exit(EXIT_FAILURE);
}

char	*ft_join(char *s1, char *s2)
{
	size_t	i;
	size_t	c1;
	size_t	c2;
	char	*str;

	c1 = ft_strlen(s1);
	c2 = ft_strlen(s2);
	str = malloc(c1 + c2 + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < c1)
	{
		str[i] = s1[i];
	}
	i = -1;
	while (c1 + ++i < c1 + c2)
	{
		str[c1 + i] = s2[i];
	}
	str[c1 + c2] = '\0';
	free(s1);
	free(s2);
	return (str);
}
