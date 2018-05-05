#ifndef EX00_H
# define EX00_H
# include "../../libft/includes/libft.h"

typedef struct	s_tar
{
	char			filename[100];
	unsigned long	filemode;
	unsigned long	userid;
	unsigned long	groupid;
	char			size[12];
	char			time[12];
	unsigned long	checksum;
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
void	ft_unarchive(char **args);

#endif
