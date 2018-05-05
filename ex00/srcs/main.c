#include "ex00.h"

int	main(int ac, char **av)
{
	open(av[1], O_RDONLY);
	ft_printf("{red}Hello, World\n{eoc}");
	return (0);
}
