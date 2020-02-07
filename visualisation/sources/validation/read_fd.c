# include "validation.h"
# include "errors.h"

char	*read_fd(int fd)
{
	char	*string;
	char	*temp;
	char	read_buf[65536 + 1];
	ssize_t	rd;

	string = NULL;
	while ((rd = read(fd, read_buf, 65536)))
	{
		if (rd == -1)
			error_found(ERR_READ_FD);
		read_buf[rd] = '\0';
		if (string)
		{
			temp = string;
			string = ft_strjoin(string, read_buf);
			free(temp);
		}
		else
			string = ft_strdup(read_buf);
		if (!string)
			error_found(ERR_READ_FD_MEM);
	}
	return (string);
}
