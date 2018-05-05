#include "ex00.h"

static void	disp_tar(t_tar *data)
{
	ft_printf("filename[100] = %s\n", data->filename);
	ft_printf("filemode = %s\n", &data->filemode);
	ft_printf("userid = %s\n", &data->userid);
	ft_printf("groupid = %s\n", &data->groupid);
	ft_printf("size[12] = %s\n", &data->size);
	ft_printf("time[12] = %lld\n", &data->time);
	ft_printf("checksum = %s\n", &data->checksum);
	ft_printf("link = %s\n", &data->link);
	ft_printf("linkname[100] = %s\n", data->linkname);
	ft_printf("size_l = %s\n", data->size_l);
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
	read(fd, &data, sizeof(t_tar) - sizeof(long));
	data.size_l = ft_strtol(data.size, NULL, 8);
	ft_printf("\n");
	disp_tar(&data);
	return (0);
}
