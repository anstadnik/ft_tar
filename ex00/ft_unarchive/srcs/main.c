#include "ex00.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("{red}Error{eoc}\n");
		return (1);
	}
	return (ft_unarchive(av[1]));
}
