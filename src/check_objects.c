/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:57:12 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/08 13:59:26 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_objs(t_map *map)
{
	map->objects.collect = 0;
	map->objects.character = 0;
	map->objects.exit = 0;
	map->objects.floor = 0;
}

void	check_objects(char letter, t_objects *objects)
{
	if (letter == 'C')
		objects->collect++;
	if (letter == 'P')
		objects->character++;
	if (letter == 'E')
		objects->exit++;
	if (letter == '0')
		objects->floor++;
}
