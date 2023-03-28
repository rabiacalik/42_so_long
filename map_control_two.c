/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalik <rcalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:41:57 by rcalik            #+#    #+#             */
/*   Updated: 2023/03/17 14:57:42 by rcalik           ###   ########.fr       */
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
