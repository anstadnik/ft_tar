#include "ex00.h"

static void	disp_tar(t_tar *data)
{
	ft_printf("filename[100] = %s\n", data->filename);
	ft_printf("filemode[8] = %s\n", data->filemode);
	ft_printf("userid[8] = %s\n", data->userid);
	ft_printf("groupid[8] = %s\n", data->groupid);
	ft_printf("size[12] = %s\n", data->size);
	ft_printf("time[12] = %s\n", data->time);
	ft_printf("checksum[8] = %s\n", data->checksum);
	ft_printf("link = %c\n", data->link);
	ft_printf("linkname[100] = %s\n", data->linkname);
}

char		ft_unarchive(char *filename)
{
	int		fd;
	t_tar	data;

	ft_printf("Your string is %s\n", filename);
	if (!(fd = open(filename, O_RDONLY)) || read(fd, NULL, 0) == -1)
	{
		ft_printf("{red}Error{eoc}\n");
		return (1);
	}
	read(fd, &data, sizeof(t_tar));
	//TODO
	//use symlink for links
	open(data.filename, O_CREAT | O_RDWR, ft_strtol(data.filemode, NULL, 8));
	disp_tar(&data);
	return (0);
}
