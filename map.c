/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalik <rcalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:57:09 by rcalik            #+#    #+#             */
/*   Updated: 2023/03/20 17:22:53 by rcalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_element_one(char c, t_game *general, int x, int y)
{
	mlx_put_image_to_window(general->mlx, general->window, general->path, x, y);
	if (c == 'P')
	{
		general->chr->loc_x = x;
		general->chr->loc_y = y;
		mlx_put_image_to_window(general->mlx, general->window,
			general->chr->chr_chr, x, y);
	}
	if (c == '1')
		mlx_put_image_to_window(general->mlx, general->window,
			general->bush, x, y);
}

void	put_element(char c, t_game *general, int x, int y)
{
	put_element_one(c, general, x, y);
	if (c == 'C')
	{
		mlx_put_image_to_window(general->mlx, general->window,
			general->carrot, x, y);
	}
	if (c == 'E')
	{
		general->map->loc_end_x = x;
		general->map->loc_end_y = y;
		mlx_put_image_to_window(general->mlx, general->window,
			general->black_hole, x, y);
	}
}

void	put_score(t_game *general)
{
	char	*score;

	score = ft_itoa(general->chr->point);
	mlx_string_put(general->mlx, general->window, 20, 20, 0xFFFFFFFF, score);
	free(score);
}

void	screen_print(t_game *general)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (general->map->mappin[i])
	{
		j = 0;
		x = 0;
		while (general->map->mappin[i][j])
		{
			put_element(general->map->mappin[i][j], general, x, y);
			put_score(general);
			x += 64;
			j++;
		}
		i++;
		y += 64;
	}
}
