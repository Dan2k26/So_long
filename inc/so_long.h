#ifndef SO_LONG_H

# define SO_LONG_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <libft.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_objects
{
	int	colect;
	int	character;
	int	exit;
	int	floor;
	int	wall;
}	t_objects;


typedef struct	s_map
{
	size_t		nrows;
	size_t		nchars;
	char		**file;
	t_objects	objects;
}	t_map;


//CHECK_ERRORS
int		check_argument(char *argv);
void	check_map(int fd);
//UTILS
void	print_error(char *mssg);
#endif
