/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:58:57 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/10 16:54:49 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<so_long.h>

static int	deal_key(int key, t_map *map)
{
	if (key == 53)
	{
		mlx_destroy_window(map->window.mlx_ptr, map->window.win_ptr);
		exit(0);
	}
	if (key == 13)
	{
		printf("W");

	}
	if (key == 2)
	{
		printf("D");
	}
	if (key == 0)
	{
		printf("A");
	}
	if (key == 1)
	{
		printf("S");
	}
	printf("%d\n", key);
	return(0);
}

void	key_pressed(t_map *map)
{
	mlx_key_hook (map->window.win_ptr, deal_key, map);
}
