/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:57:12 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/08 19:46:46 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_objs(t_map *map)
{
	map->collect = 0;
	map->character = 0;
	map->exit = 0;
	map->floo
}

void	check_objects(char letter, t_map *map)
{
	if (letter == 'C')
		map->collect++;
	if (letter == 'P')
		map->character++;
	if (letter == 'E')
		map->exit++;
}

void	save_position()
{

}
