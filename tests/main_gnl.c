#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char *s;
	int fd;
	int i = 1;
	int ans;

	fd = open("testfile.txt", O_RDONLY);
	while ((ans = get_next_line(fd, &s))  > 0)
	{
		printf("returned |%d|\n", ans);
		printf("%d)%s|\n", i++, s);
		free(s);
	}
		printf("returned |%d|\n", ans);
		printf("%d)%s|\n", i, s);
	free(s);
	return (0);
}
