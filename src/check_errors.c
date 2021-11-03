/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:03:43 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/03 21:01:26 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	check_walls(char **map, int nrows)
{
	int	i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[i]);
	printf("%s", map[i]);
	while (i < nrows - 1)
	{
		if (len != ft_strlen(map[i]))
		{
			printf("%d   %zd    %s\n", i,len, map[i]);
			exit(0);
		}
		len = ft_strlen(map[i]);
		i++;
	}
	if (ft_strlen(map[nrows - 1]) != len - 1)
			print_error("MAPA ULTIMA FILA\n");
	printf("lololollolol");
}

void	check_map(int fd)
{
	char	*file;
	char	**map;
	int		i;

	i = 0;
	map = ft_calloc(4,sizeof(char));
	if (map == NULL)
		exit(0);
	file = get_next_line(fd);
	while (file)
	{
		map[i] = ft_strdup(file);
		if (map[i] == NULL)
		{
			ft_free_malloc(map);
			exit(0);
		}
		free(file);
		file = get_next_line(fd);
		i++;
	}
	check_walls(map, i);
	//ft_free_malloc(map);
	//Comprobar que la primera y ultima filas son de 1

	//comprobar primer y penultimo caracter son 1

	/*comprobar que estan al menos
	  0->vacio 1->muro C->coleccionable E->salida P->posicion inicial*/
}

int	check_argument(char *argv)
{
	char	*point = NULL;
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
