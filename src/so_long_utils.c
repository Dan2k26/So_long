/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:03:39 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/11 18:55:05 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<so_long.h>

void	print_error(char *mssg)
{
	write(1, "ERROR\n", 6);
	write(1, mssg, ft_strlen(mssg));
	exit(0);
}

void	print_moves(t_map map)
{
	write(1, "MOVES: ", 7);
	ft_putnbr_fd(map.objects.move, 1);
	write(1, "\n", 1);
}
