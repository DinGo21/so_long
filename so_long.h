/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:32:21 by disantam          #+#    #+#             */
/*   Updated: 2023/11/08 16:59:50 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "mlx/include/MLX42/MLX42.h"

typedef struct s_cols
{
	int	x;
	int	y;
	int	in;
}	t_cols;

typedef struct s_map
{
	char		**map;
	t_cols		**cols;
	int			c[3];
	int			size_y;
	int			size_x;
	int			p_x;
	int			p_y;
}				t_map;

typedef struct s_data
{
	t_map			map;
	mlx_t			*mlx;
	mlx_image_t		*imgs[5];
	mlx_texture_t	*textures[5];
	int				moves;
}					t_data;

/* utils.c */
void	free_map(t_map *map);
void	free_data(t_data *data);
void	ft_mlx_error(t_data *data);
char	*ft_join(char *s1, char *s2);
void	ft_map_error(t_map *map, char *text);

/* init.c */
void	load_textures(t_data *data);
void	init_map(t_map *map, char *file);
void	init_mlx(t_data *data, t_map *map);
void	render_window(t_data *data, t_map *map);

/* map.c */
void	test_map(t_map *map);
void	check_map(t_map *map);
void	parse_map(t_map *map, int fd);
void	check_line(t_map *map, int len, int x, int y);

/* window.c */
void	render_wall(t_data *data, t_map *map, int x, int y);
void	render_exit(t_data *data, t_map *map, int x, int y);
void	render_floor(t_data *data, t_map *map, int x, int y);
void	render_player(t_data *data, t_map *map, int x, int y);
void	render_collectables(t_data *data, t_map *map, int x, int y);

/* hooks.c */
void	keyhook_up(t_data *data, t_map *map);
void	keyhook_down(t_data *data, t_map *map);
void	keyhook_left(t_data *data, t_map *map);
void	keyhook_right(t_data *data, t_map *map);
void	keyhook(mlx_key_data_t keydata, void *param);

#endif
