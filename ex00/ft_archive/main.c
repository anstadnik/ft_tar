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
	char		*tmp;

	if (stat(filename, &st) < 0)
	{
		error(filename);
		return (NULL);
	}
	node = ft_memalloc(sizeof(t_tar));
	ft_strcpy(node->filename, filename);
	node->filemode = st.st_mode;
	node->userid = st.st_uid;
	node->groupid = st.st_gid;
	ft_asprintf(&tmp, "%hO", st.st_size);
	ft_memcpy(node->size, tmp, 12);
	ft_strdel(&tmp);
	ft_asprintf(&tmp, "%hO", st.st_mtimespec);
	ft_memcpy(node->time, tmp, 12);
	node->checksum = 0;
	unsigned char *bytes = (unsigned char *) node;
	for (int i = 0; i < sizeof(t_tar); i++)
		node->checksum += bytes[i];
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
	ft_printf("mode: %jo\n", t->filemode);
	ft_printf("userid: %jo\n", t->userid);
	ft_printf("groupid: %jo\n", t->groupid);
	ft_printf("size: %s\n", t->size);
	ft_printf("time: %s\n", t->time);
	ft_printf("checksum: %jo\n", t->checksum);
	ft_printf("link: %d\n", t->link);
	ft_printf("linkname: %s\n", t->linkname);
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
