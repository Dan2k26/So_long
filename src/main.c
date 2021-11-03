/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:03:47 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/03 21:25:00 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<so_long.h>

void	check_leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	int	fd;
	
	//atexit(check_leaks);
	if (argc == 2)
	{
		fd = check_argument(argv[1]);
		check_map(fd);
	}
	else
		print_error("ARGUMENTOS MAL INTRODUCIDOS\n");
	return (0);
}
