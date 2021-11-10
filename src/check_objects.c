/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:57:12 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/10 17:38:28 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_objs(t_map *map)
{
	map->collect = 0;
	map->character = 0;
	map->exit = 0;
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
