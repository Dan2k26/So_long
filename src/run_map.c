/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:23:11 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/09 18:51:28 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	run_map(t_map *map)
{
	map->window.mlx_ptr = mlx_init();
	map->window.win_ptr = mlx_new_window(map->window.mlx_ptr, map->nchars * SZ, map->nrows * SZ, "Dan");
	key_pressed(map);
	mlx_loop(map->window.mlx_ptr);
}
