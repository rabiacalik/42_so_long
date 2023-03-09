/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_files_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalik <rcalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:20:15 by rcalik            #+#    #+#             */
/*   Updated: 2023/03/06 15:50:02 by rcalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_control_obje(void)
{
	int	file_black_hole;
	int	file_bush;
	int	file_carrot;
	int	file_path;

	file_black_hole = open("./img/black_hole.xpm", O_RDWR);
	file_bush = open("./img/bush.xpm", O_RDWR);
	file_carrot = open("./img/carrot.xpm", O_RDWR);
	file_path = open("./img/path.xpm", O_RDWR);
	if (file_black_hole <= 0 || file_bush <= 0
		|| file_carrot <= 0 || file_path <= 0)
	{
		write(1, "xpm dosyasında eksik var\n", 35);
		close(file_black_hole);
		close(file_bush);
		close(file_carrot);
		close(file_bush);
		exit(1);
	}
	close(file_black_hole);
	close(file_bush);
	close(file_carrot);
	close(file_bush);
}

void	xpm_control_character(void)
{
	int	file_chr_back;
	int	file_chr_front;
	int	file_chr_left;
	int	file_chr_right;

	file_chr_back = open("./img/character_back.xpm", O_RDWR);
	file_chr_front = open("./img/character_front.xpm", O_RDWR);
	file_chr_left = open("./img/character_left.xpm", O_RDWR);
	file_chr_right = open("./img/character_right.xpm", O_RDWR);
	if (file_chr_back <= 0 || file_chr_front <= 0
		|| file_chr_left <= 0 || file_chr_right <= 0)
	{
		write(1, "xpm dosyasında eksik var!\n", 35);
		close(file_chr_back);
		close(file_chr_front);
		close(file_chr_left);
		close(file_chr_right);
		exit(1);
	}
	close(file_chr_back);
	close(file_chr_front);
	close(file_chr_left);
	close(file_chr_right);
}

void	get_image(t_game *general, int x, int y)
{
	general->mlx = mlx_init();
	general->window = mlx_new_window(general->mlx, general->width,
			general->height, "Adventure Game");
	general->chr = ft_calloc(1, sizeof(t_chr));
	general->chr->loc_x = 0;
	general->chr->loc_y = 0;
	general->chr->point = 0;
	general->chr->chr_front = mlx_xpm_file_to_image(general->mlx, \
			"./img/character_front.xpm", &x, &y);
	general->chr->chr_back = mlx_xpm_file_to_image(general->mlx, \
			"./img/character_back.xpm", &x, &y);
	general->chr->chr_left = mlx_xpm_file_to_image(general->mlx, \
			"./img/character_left.xpm", &x, &y);
	general->chr->chr_right = mlx_xpm_file_to_image(general->mlx, \
			"./img/character_right.xpm", &x, &y);
	general->chr->chr_chr = general->chr->chr_back;
	general->black_hole = mlx_xpm_file_to_image(general->mlx,
			"./img/black_hole.xpm", &x, &y);
	general->bush = mlx_xpm_file_to_image(general->mlx,
			"./img/bush.xpm", &x, &y);
	general->carrot = mlx_xpm_file_to_image(general->mlx,
			"./img/carrot.xpm", &x, &y);
	general->path = mlx_xpm_file_to_image(general->mlx,
			"./img/path.xpm", &x, &y);
}
