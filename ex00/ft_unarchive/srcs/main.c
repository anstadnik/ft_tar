#include "ex00.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("{red}Error{eoc}");
		return (1);
	}
	ft_unarchive(av[1]);
}
