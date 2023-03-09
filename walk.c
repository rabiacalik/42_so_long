/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalik <rcalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:28:58 by rcalik            #+#    #+#             */
/*   Updated: 2023/03/06 14:09:50 by rcalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putchr(t_game *general, int keycode)
{
	if (keycode == 2)
		general->chr->chr_chr = general->chr->chr_right;
	if (keycode == 0)
		general->chr->chr_chr = general->chr->chr_left;
	if (keycode == 13)
		general->chr->chr_chr = general->chr->chr_back;
	if (keycode == 1)
		general->chr->chr_chr = general->chr->chr_front;
}

void	print_score(t_game *general)
{
	ft_printf("%d\n", general->chr->point);
}

void	move_p(t_game *general, int side, int x, int y)
{
	if (general->map->crrt_count == 0 && general->map->mappin[y / 64]
		[x / 64] == 'E')
	{
		general->chr->point += 1;
		print_score(general);
		write(1, "Kazandiinn!", 13);
		close_frame(general);
	}
	if (general->map->mappin[y / 64][x / 64] != '1'
		&& general->map->mappin[y / 64][x / 64] != 'E')
	{
		putchr(general, side);
		general->chr->point += 1;
		if (general->map->mappin[y / 64][x / 64] == 'C')
			general->map->crrt_count -= 1;
		general->map->mappin[general->chr->loc_y / 64]
		[general->chr->loc_x / 64] = '0';
		general->map->mappin[general->map->loc_end_y / 64]
		[general->map->loc_end_x / 64] = 'E';
		general->map->mappin[y / 64][x / 64] = 'P';
		print_score(general);
	}
}

int	walk(int keycode, t_game *general)
{
	mlx_clear_window(general->mlx, general->window);
	if (keycode == 2)
		move_p(general, keycode, general->chr->loc_x + 64, general->chr->loc_y);
	if (keycode == 0)
		move_p(general, keycode, general->chr->loc_x - 64, general->chr->loc_y);
	if (keycode == 13)
		move_p(general, keycode, general->chr->loc_x, general->chr->loc_y - 64);
	if (keycode == 1)
		move_p(general, keycode, general->chr->loc_x, general->chr->loc_y + 64);
	if (keycode == 53)
		close_frame(general);
	screen_print(general);
	return (keycode);
}
