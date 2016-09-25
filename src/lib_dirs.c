#include "ftls.h"

t_list	*ft_dir_get_ents(t_lsdata *topdir)
{
	t_list			*ent;
	struct dirent	*dirent;
	t_lsdata		data;
	DIR				*stream;

	ent = NULL;
	stream = opendir(topdir->path);
	while ((dirent = readdir(stream)))
	{
		data.path = ft_strjoin(topdir->path, "/");
		data.path = ft_strjoin(data.path, dirent->d_name);
		/* ft_printf("looking at file: %s\n", data.path); */
		/* ft_printf("stat ret: %i\n", stat(data.path, &data.stat)); */
		lstat(data.path, &data.stat);
		data.dirent = dirent;
		/* char *date = ctime(&data.stat.st_mtime); */
		/* date[ft_strlen(date) - 1] = '\0'; */
		/* ft_printf("%s %i %s\n", date, data.stat.st_ino, data.dirent->d_name); */
		ft_lstadd(&ent, ft_lstnew(&data, sizeof(data)));
	}
	closedir(stream);
	return (ent);
}
