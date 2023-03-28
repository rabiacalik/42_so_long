/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalik <rcalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:37:51 by rcalik            #+#    #+#             */
/*   Updated: 2023/03/20 17:32:46 by rcalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	recur_func(int **int_map, t_map *map, int x, int y)
{
	if (map->mappin[y][x] == 'P' || map->mappin[y][x] == 'C')
		map->read_count++;
	if (map->mappin[y][x + 1] != '1' && int_map[y][x + 1] < 1)
	{
		int_map[y][x + 1] = int_map[y][x] + 1;
		map->r = recur_func(int_map, map, x + 1, y);
	}
	if (map->mappin[y + 1][x] != '1' && int_map[y + 1][x] < 1)
	{
		int_map[y + 1][x] = int_map[y + 1][x] + 1;
		map->b = recur_func(int_map, map, x, y + 1);
	}
	if (map->mappin[y][x - 1] != '1' && int_map[y][x - 1] < 1)
	{
		int_map[y][x - 1] = int_map[y][x] + 1;
		map->l = recur_func(int_map, map, x - 1, y);
	}
	if (map->mappin[y - 1][x] != '1' && int_map[y - 1][x] < 1)
	{
		int_map[y - 1][x] = int_map[y][x] + 1;
		map->t = recur_func(int_map, map, x, y - 1);
	}
	if ((map->r || map->l || map->b || map->t))
		return (1);
	return (0);
}

static void	int_map_free(int **int_map, t_game *general)
{
	int	i;

	i = 0;
	while (i < general->height)
	{
		free(int_map[i]);
		i++;
	}
	free(int_map);
}

void	placeholder(t_game *general, int x, int y)
{
	int	**int_map;
	int	i;
	int	j;

	i = -1;
	j = -1;
	int_map = (int **)malloc(sizeof(int *) * general->height);
	while (++i < general->height)
	{
		int_map[i] = (int *)malloc(sizeof(int) * general->width);
		j = -1;
		while (j < general->width)
		{
			int_map[i][++j] = 0;
		}
	}
	int_map[y][x] = 1;
	general->map->read_count = 0;
	recur_func(int_map, general->map, x, y);
	if (general->map->read_count != general->map->crrt_count + 1)
	{
		write(1, "Harita Tamamlanabilir Degil..\n", 32);
		exit (1);
	}
	int_map_free(int_map, general);
}
