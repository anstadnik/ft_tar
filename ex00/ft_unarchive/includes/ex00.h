#ifndef EX00_H
# define EX00_H
# include "../../../libft/includes/libft.h"
# include "fcntl.h"

typedef struct	s_tar
{
	char			filename[100];
	char			filemode[8];
	char			userid[8];
	char			groupid[8];
	char			size[12];
	char			time[12];
	char			checksum[8];
	char			link;
	char			linkname[100];
}				t_tar;

typedef enum
{
	x,
	c = 2,
	v = 4,
	f = 8,
	t = 16,
	p = 32
}	t_params;


void	ft_archive(char **args);
char	ft_unarchive(char *args);

long		ft_strtol(const char *str, char **endptr, int base);
#endif
