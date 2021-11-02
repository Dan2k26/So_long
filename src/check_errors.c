/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:03:43 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/02 19:44:26 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<so_long.h>

void	check_argument(char *argv)
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
	//Comprobar que la primera y ultima filas son de 1
	printf("%s\n", get_next_line(fd));
	//comprobar primer y penultimo caracter son 1

	/*comprobar que estan al menos
	  0->vacio 1->muro C->coleccionable E->salida P->posicion inicial*/

}
