/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:12:50 by disantam          #+#    #+#             */
/*   Updated: 2024/01/10 17:49:16 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (EXIT_FAILURE);
	init_map(&data.map, argv[1]);
	init_mlx(&data, &data.map);
	render_window(&data, &data.map);
	mlx_key_hook(data.mlx, keyhook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	free_data(&data);
	return (EXIT_SUCCESS);
}
