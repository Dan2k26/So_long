/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:03:43 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/05 20:38:26 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	check_objects(char letter, t_objects *objects)
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

static void	objs_and_square(char *line, size_t len, t_map *map)
{
	size_t	i;

	i = 0;
	if (line[i] != '1' || line[len - 1] != '1')
		print_error("LOS MUROS NO SON VÁLIDOS\n");
	while (line[i])
	{
		check_objects(line[i], &map->objects);
		if (line[i] == '\n')
			break ;
		if (line [i] != '0' && line [i] != '1' && line [i] != 'C'
			&& line [i] != 'E' && line [i] != 'P')
			print_error("LOS OBJETOS NO SON VÁLIDOS\n");
		i++;
	}
	if (len != i)
		print_error("MAPA NO VÁLIDO\n");
}

static void	init_objs(t_map *map)
{
	map->objects.collect = 0;
	map->objects.character = 0;
	map->objects.exit = 0;
	map->objects.floor = 0;
}

void	check_map(int fd, t_map *map)
{
	char	*line;
	size_t	i;

	line = get_next_line(fd);
	if (line == NULL)
		print_error("ARCHIVO VACIO\n");
	init_objs(map);
	map->nchars = ft_strlen(line) - 1;
	i = 2;
	while (line)
	{	
		objs_and_square(line, map->nchars, map);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->nrows = i;
	if (map->objects.floor == 0 || map->objects.character != 1
		|| map->objects.exit != 1)
		print_error("HAS METIDO OBJETOS DE MAS\n");
}

int	check_argument(char *argv)
{
	char	*point;
	int		fd;

	point = ft_strchr(argv, '.');
	if (point == NULL || ft_strncmp(point, ".ber", 4) != 0)
		print_error("EXTENSION NO VALIDA\n");
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		print_error("ERROR AL ABRIR EL ARCHIVO\n");
	return (fd);
}

void	save_map(int fd, t_map *map)
{
	char	*line;
	char	**archive;
	int		i;
		
	line = get_next_line(fd);
	if (line == NULL)
		print_error("ARCHIVO VACIO\n");
	archive = ft_calloc(map->nrows, sizeof(char));
	if (archive == NULL)
		print_error("CALLOC ES NULO\n");
	i = 2;
	while (line)
	{	
		if (line != NULL)
		{
			archive[i] = line;

			printf("%s", archive[i]);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	
}
