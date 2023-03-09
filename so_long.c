/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalik <rcalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:16:30 by rcalik            #+#    #+#             */
/*   Updated: 2023/03/09 12:15:45 by rcalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_windows(t_game *general, char *argv_incoming)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	general->map = read_map(argv_incoming);
	general->height = general->map->height * 64;
	general->width = general->map->width * 64;
	get_image(general, x, y);
	black_hole_control(general);
	map_size_control(general);
	player_control(general);
	frame_control(general);
	carrot_control(general);
	character_control(general);
}

int	close_frame(void *deneme)
{
	t_game	*general;
	int		i;

	general = deneme;
	i = 0;
	mlx_destroy_image(general->mlx, general->chr->chr_front);
	mlx_destroy_image(general->mlx, general->chr->chr_back);
	mlx_destroy_image(general->mlx, general->chr->chr_left);
	mlx_destroy_image(general->mlx, general->chr->chr_right);
	mlx_destroy_image(general->mlx, general->black_hole);
	mlx_destroy_image(general->mlx, general->bush);
	mlx_destroy_image(general->mlx, general->carrot);
	mlx_destroy_image(general->mlx, general->path);
	free(general->chr);
	free(general->map);
	mlx_destroy_window(general->mlx, general->window);
	exit(1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	general;

	if (argc == 2)
	{
		xpm_control_obje();
		xpm_control_character();
		map_ber_control(argv[1]);
		map_empty_control(argv[1]);
		map_file_control(argv[1]);
		open_windows(&general, argv[1]);
		screen_print(&general);
		mlx_hook(general.window, 2, (1L << 0), walk, &general);
		mlx_hook(general.window, 17, 0, close_frame, &general);
		mlx_loop(general.mlx);
	}
	else
	{
		write(1, "Bir Tane Map Girmelisin\n", 25);
	}
	return (0);
}
