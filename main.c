#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		main(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcd\n", 5);
	write(fd, "efgh\n", 5);
	close(p[1]);
	dup2(out, fd);
	ret = get_next_line(p[0], &line);
	ft_printf("line:%s\ndiff:%d\n", line, strcmp(line, "abcd"));
	ft_printf("ret:%i\n", ret);
	ret = get_next_line(p[0], &line);
	ft_printf("line:%s\ndiff:%d\n", line, strcmp(line, "efgh"));
	ft_printf("ret:%i\n", ret);
	ret = get_next_line(p[0], &line);
	ft_printf("ret:%i\n", ret);
	/*int fd = open("../togetnextline.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		ft_printf("%s:endline\n", line);*/
	return (0);
}
