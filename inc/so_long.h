#ifndef SO_LONG_H

# define SO_LONG_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <libft.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
    int nrows;
    int nchars;
}   t_map;


//CHECK_ERRORS
int		check_argument(char *argv);
void	check_map(int fd);
//UTILS
void	print_error(char *mssg);
#endif
