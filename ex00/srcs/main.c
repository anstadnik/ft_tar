#include <fcntl.h>
#include <sys/stat.h>
#include "ex00.h"
#include "unistd.h"


/**
 * Show a human-readable error format with tar: prefix
 * @param message
 */
void	error(char *message)
{
	char *with_prefix;

	with_prefix = ft_strjoin("tar: ", message);
	perror(with_prefix);
	free(with_prefix);
}



/**
 * Create a structure from a filename
 * @param filename
 * @return
 */

t_tar	*create_structure(char *filename)
{
	t_tar		*node;
	struct stat	st;

	if (stat(filename, &st) < 0)
	{
		error(filename);
		return (NULL);
	}
	node = ft_memalloc(sizeof(t_tar));
	ft_strcpy(node->filename, filename);

	return (node);
}

/**
 * Display all fields of a tar structure
 * @param t
 */
void	disp_tar(t_tar *t)
{
	if (!t)
		return ;
	ft_printf("name: %s\n", t->filename);
}



/**
 * Archive all the files
 * @param args
 */
void	ft_archive(char **args)
{
	// for file in args
	// create structure
	// output the header
	// output file content
	(void)args;
}

int	main(int ac, char **av)
{
	(void)ac;
//	int fd = open(av[1], O_RDONLY);
//	if (fd < 0)
//		error(av[1]);

	t_tar *here = create_structure(av[1]);
	disp_tar(here);
	return (0);
}
