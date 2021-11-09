/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:13:33 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/09 17:21:35 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <libft.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>

# define SZ 32

typedef struct s_objects
{
	int	id;
	int	posx;
	int	posy;
	int	**objs;
}	t_objects;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
} t_window;

typedef struct s_map
{
	size_t		nrows;
	size_t		nchars;
	char		**file;
	int			collect;
	int			character;
	int			exit;
	t_window	window;
	t_objects	objects;
}	t_map;

int		check_argument(char *argv);
void	check_map(int fd, t_map *map);
void	save_map(int fd, t_map *map);
void	run_map(t_map *map);
//UTILS
void	print_error(char *mssg);
//OBJS
void	init_objs(t_map *map);
void	check_objects(char letter, t_map *map);
void	save_objects(t_map *map);
//EVENTS
void	key_pressed(t_map *map);
#endif
