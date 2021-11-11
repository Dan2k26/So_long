/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:58:57 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/11 19:05:26 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<so_long.h>

static void	change_position(t_map *map, int type)
{
	if (type == 0)
		map->objects.posy = map->objects.posy - 1;
	else if (type == 1)
		map->objects.posx = map->objects.posx + 1;
	else if (type == 2)
		map->objects.posx = map->objects.posx - 1;
	else if (type == 3)
		map->objects.posy = map->objects.posy + 1;
}

static int	check_door(t_map *map, int type)
{
	int	tempx;
	int	tempy;

	tempx = map->objects.posx;
	tempy = map->objects.posy;
	change_position(map, type);
	if (map->collect == map->objects.items
		&& map->file[map->objects.posy][map->objects.posx] == 'E')
	{
		mlx_destroy_window(map->window.mlx_ptr, map->window.win_ptr);
		exit(0);
	}
	else if ((map->collect != map->objects.items
			&& map->file[map->objects.posy][map->objects.posx] == 'E'))
	{
		map->objects.posy = tempy;
		map->objects.posx = tempx;
		return (0);
	}
	return (1);
}

static int	move_character(t_map *map, int type)
{
	int	boo;

	boo = 0;
	mlx_put_image_to_window(map->window.mlx_ptr, map->window.win_ptr,
		map->window.img_ptr_floor, map->objects.posx * SZ,
		map->objects.posy * SZ);
	boo = check_door(map, type);
	mlx_put_image_to_window(map->window.mlx_ptr, map->window.win_ptr,
		map->window.img_ptr_character, map->objects.posx * SZ,
		map->objects.posy * SZ);
	map->objects.move++;
	if (boo != 0)
		print_moves(*map);
	if (map->file[map->objects.posy][map->objects.posx] == 'C')
		return (1);
	return (0);
}

static int	deal_key(int key, t_map *map)
{
	if (key == 53)
	{
		mlx_destroy_window(map->window.mlx_ptr, map->window.win_ptr);
		exit(0);
	}
	if (key == 13)
		if (map->file[map->objects.posy - 1][map->objects.posx] != '1')
			map->objects.items += move_character(map, 0);
	if (key == 2)
		if (map->file[map->objects.posy][map->objects.posx + 1] != '1')
			map->objects.items += move_character(map, 1);
	if (key == 0)
		if (map->file[map->objects.posy][map->objects.posx - 1] != '1')
			map->objects.items += move_character(map, 2);
	if (key == 1)
		if (map->file[map->objects.posy + 1][map->objects.posx] != '1')
			map->objects.items += move_character(map, 3);
	return (0);
}

void	key_pressed(t_map *map)
{
	mlx_key_hook (map->window.win_ptr, deal_key, map);
}
