
#include<so_long.h>

void	check_argument(char *argv)
{
	char	*point;

	//mirar la extension
	point = ft_strncmp(argv, ".", (int) ft_strlen(argv));
	if (ft_strcmp(point, ".ber") != 0)
	{
		printf("EXTENSION NO VALIDA\n");
		exit(0);
	}
}
