/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:17:29 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/11 18:56:28 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<so_long.h>

static void	images_init(t_map *map)
{
	int	i;

	i = 32;
	map->window.img_ptr_floor = mlx_xpm_file_to_image(map->window.mlx_ptr,
			"./img/floor.xpm", &i, &i);
	map->window.img_ptr_wall = mlx_xpm_file_to_image(map->window.mlx_ptr,
			"./img/wall.xpm", &i, &i);
	map->window.img_ptr_character = mlx_xpm_file_to_image(map->window.mlx_ptr,
			"./img/character.xpm", &i, &i);
	map->window.img_ptr_collect = mlx_xpm_file_to_image(map->window.mlx_ptr,
			"./img/item.xpm", &i, &i);
	map->window.img_ptr_exit = mlx_xpm_file_to_image(map->window.mlx_ptr,
			"./img/door.xpm", &i, &i);
}

void	draw_images(t_map *map, size_t i, size_t j)
{
	if (map->file[i][j] == '1')
		mlx_put_image_to_window(map->window.mlx_ptr, map->window.win_ptr,
			map->window.img_ptr_wall, j * SZ, i * SZ);
	else
		mlx_put_image_to_window(map->window.mlx_ptr, map->window.win_ptr,
			map->window.img_ptr_floor, j * SZ, i * SZ);
	if (map->file[i][j] == 'P')
	{
		mlx_put_image_to_window(map->window.mlx_ptr, map->window.win_ptr,
			map->window.img_ptr_character, j * SZ, i * SZ);
		map->objects.posx = j;
		map->objects.posy = i;
	}
	if (map->file[i][j] == 'E')
		mlx_put_image_to_window(map->window.mlx_ptr, map->window.win_ptr,
			map->window.img_ptr_exit, j * SZ, i * SZ);
	if (map->file[i][j] == 'C')
		mlx_put_image_to_window(map->window.mlx_ptr, map->window.win_ptr,
			map->window.img_ptr_collect, j * SZ, i * SZ);
}

void	put_images(t_map *map)
{
	size_t	i;
	size_t	j;

	images_init(map);
	i = 0;
	while (i < map->nrows)
	{
		j = 0;
		while (j < map->nchars)
		{
			draw_images(map, i, j);
			j++;
		}
		i++;
	}
}
