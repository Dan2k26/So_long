/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:03:47 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/10 16:32:05 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<so_long.h>

void	check_leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	//atexit(check_leaks);
	if (argc == 2)
	{
		fd = check_argument(argv[1]);
		check_map(fd, &map);
		close(fd);
		fd = check_argument(argv[1]);
		save_map(fd, &map);
		close(fd);
		run_map(&map);
	}
	else
		print_error("ARGUMENTOS MAL INTRODUCIDOS\n");
	return (0);
}
