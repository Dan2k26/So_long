/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:17:29 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/09 20:27:17 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<so_long.h>

void	put_images(t_map *map)
{
	int i = 32;
	map->window.img_ptr_floor = mlx_xpm_file_to_image(map->window.mlx_ptr, "./img/floor.xpm", &i, &i);
	printf("%s\n", map->window.img_ptr_floor);
	mlx_put_image_to_window(map->window.mlx_ptr, map->window.win_ptr,
		map->window.img_ptr_floor, 0 ,0);
	
	map->window.img_ptr_character = mlx_xpm_file_to_image(map->window.mlx_ptr, "./img/player.xpm", &i, &i);
	//printf("%s\n", map->window.img_ptr);
	mlx_put_image_to_window(map->window.mlx_ptr, map->window.win_ptr,
		map->window.img_ptr_character, 0,0);
}
