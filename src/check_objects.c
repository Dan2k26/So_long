/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:57:12 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/09 16:42:51 by dlerma-c         ###   ########.fr       */
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

static size_t	objects_positions(t_map *map, size_t pos, int x, int y)
{
	int	id;

	id = 0;
	if (map->file[y][x] == 'P')
		id = 1;
	else if (map->file[y][x] == 'E')
		id = 2;
	else if (map->file[y][x] == 'C')
		id = 3;
	if (id != 0)
	{
		map->objects.objs[pos] = malloc(3 * sizeof(int));
		if (map->objects.objs[pos] == NULL)
			print_error("NO SE HA GUARDADO OBJS\n");
		map->objects.objs[pos][0] = id;
		map->objects.objs[pos][1] = x;
		map->objects.objs[pos][2] = y;
		return (1);
	}
	return (0);
}

void	save_objects(t_map *map)
{
	size_t	num_objs;
	size_t	i;
	size_t	j;
	size_t	pos;

	num_objs = map->character + map->exit + map->collect;
	map->objects.objs = malloc(num_objs * sizeof(int *));
	if (map->objects.objs == NULL)
		print_error("NO SE HA PODIDO GENERAR MALLOC DE OBJ\n");
	i = 0;
	pos = 0;
	while (i < map->nrows)
	{
		j = 0;
		while (j < map->nchars)
		{
			pos += objects_positions(map, pos, j, i);
			j++;
		}
		i++;
	}
}
