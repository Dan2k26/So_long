
#include<so_long.h>

void	check_argument(char *argv)
{
	char	*point;
	int		fd;

	//mirar la extension
	point = strchr(argv, '.');
	if (strcmp(point, ".ber") != 0)
	{
		printf("EXTENSION NO VALIDA\n");
		exit(0);
	}
	//intentar abrirlo
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("ARCHIVO NO EXISTE\n");
		exit(0);
	}
}
