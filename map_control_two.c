/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalik <rcalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:41:57 by rcalik            #+#    #+#             */
/*   Updated: 2023/03/06 13:01:07 by rcalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	character_control(t_game *general)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (general->map->mappin[++i])
	{
		while (general->map->mappin[i][++j])
		{
			if (general->map->mappin[i][j] != '0'
				&& general->map->mappin[i][j] != '1'
				&& general->map->mappin[i][j] != 'P'
				&& general->map->mappin[i][j] != 'C'
				&& general->map->mappin[i][j] != 'E')
			{
				write(1, "Haritada Tanimlanamayan Karakter Var\n", 38);
				close_frame(general);
			}
		}
		j = 0;
	}
}

void	no_exit(t_game *general)
{
	int	sol;
	int	sag;
	int	yukari;
	int	asagi;

	sag = general->map->mappin[general->map->loc_end_y / 64]
	[(general->map->loc_end_x / 64) + 1];
	sol = general->map->mappin[general->map->loc_end_y / 64]
	[(general->map->loc_end_x / 64) - 1];
	asagi = general->map->mappin[(general->map->loc_end_y / 64) + 1]
	[general->map->loc_end_x / 64];
	yukari = general->map->mappin[(general->map->loc_end_y / 64) - 1]
	[general->map->loc_end_x / 64];
	if (sag == '1' && sol == '1' && yukari == '1' && asagi == '1')
	{
		write(1, "Cikis Yolu Kapatilmis\n", 23);
		close_frame(general);
		exit (1);
	}
}

void	cant_pick_carrots(t_game *general)
{
	int	sol;
	int	sag;
	int	yukari;
	int	asagi;

	sag = general->map->mappin[general->map->loc_c_y / 64]
	[(general->map->loc_c_x / 64) + 1];
	sol = general->map->mappin[general->map->loc_c_y / 64]
	[(general->map->loc_c_x / 64) - 1];
	asagi = general->map->mappin[(general->map->loc_c_y / 64) + 1]
	[general->map->loc_c_x / 64];
	yukari = general->map->mappin[(general->map->loc_c_y / 64) - 1]
	[general->map->loc_c_x / 64];
	if (sag == '1' && sol == '1' && yukari == '1' && asagi == '1')
	{
		write(1, "Tum Kemikler Toplanabilir Sekilde Degil\n", 41);
		close_frame(general);
		exit (1);
	}
}

void	carrot_control(t_game *general)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (general->map->mappin[++i])
	{
		while (general->map->mappin[i][++j])
		{
			if (general->map->mappin[i][j] == 'C')
			{
				general->map->crrt_count++;
			}
		}
		j = 0;
	}
	if (general->map->b_h_count < 1)
	{
		write(1, "En Az Bir Tane Toplanabilir Nesne Olmali\n", 42);
		close_frame(general);
	}
}
