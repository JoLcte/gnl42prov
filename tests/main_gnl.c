#include <stdio.h>
#include "../get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char *s;
	int fd;
	int i = 1;

	fd = open("testfile.txt", O_RDONLY);
	while (get_next_line(fd, &s)  > 0)
		printf("%d)%s|\n", i++, s); 
	return (0);
}
