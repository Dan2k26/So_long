/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:03:43 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/04 20:19:13 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

//si tiene un objeto ponemos una marca y añadimos 1

static void	objs_and_square(char *line, size_t len)
{
	size_t	i;

	i = 0;
	if (line[i] != '1' || line[len - 1] != '1')
		print_error("LOS MUROS NO SON VÁLIDOS");
	while (line[i])
	{
		if (line[i] == '\n')
			break;
		if (line [i] != '0' && line [i] != '1' && line [i] != 'C' 
			&& line [i] != 'E' && line [i] != 'P')
			print_error("LOS OBJETOS NO SON VÁLIDOS\n");
		check_objects(line[i]);
		i++;
	}
	if (len != i)
		print_error("MAPA NO VÁLIDO\n");
	/*comprobar que estan al menos
	  0->vacio 1->muro C->coleccionable E->salida P->posicion inicial*/
}

void	check_map(int fd)
{
	char	*line;
	t_map	map;
	size_t	i;

	line = get_next_line(fd);
	if (line == NULL)
		print_error("ARCHIVO VACIO\n");
	map.nchars = ft_strlen(line) - 1;
	i = 2;
	while (line)
	{	
		objs_and_square(line, map.nchars);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map.nrows = i;

	//ft_free_malloc(map);
	//Comprobar que la primera y ultima filas son de 1

	//comprobar primer y penultimo caracter son 1

	/*comprobar que estan al menos
	  0->vacio 1->muro C->coleccionable E->salida P->posicion inicial*/
}

//vamos a saber el nuemro de 1 segun e lnumero de filas por la kongitud de caracteres

int	check_argument(char *argv)
{
	char	*point;
	int		fd;

	//mirar la extension
	point = ft_strchr(argv, '.');
	if (point == NULL || ft_strncmp(point, ".ber", 4) != 0)
		print_error("EXTENSION NO VALIDA\n");
	//comprobar que se abre el archivo, que exista
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		print_error("ERROR AL ABRIR EL ARCHIVO\n");
	return (fd);
}
