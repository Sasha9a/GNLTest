#include "header.h"
#include "../get_next_line.h"

int		main()
{
	char	*line;

	printf("%sget_next_line:%s ", WHITE, RESET);
	if (!(testing("Main/test.txt", BUFFER_SIZE, get_next_line)))
		printf("%s[CRASH]%s ", RED, RESET);
	if (!(testing("Main/test1.txt", BUFFER_SIZE, get_next_line)))
		printf("%s[CRASH]%s ", RED, RESET);
	if (!(testing("Main/test2.txt", BUFFER_SIZE, get_next_line)))
		printf("%s[CRASH]%s ", RED, RESET);
	if (!(testing("Main/test3.txt", BUFFER_SIZE, get_next_line)))
		printf("%s[CRASH]%s ", RED, RESET);
	if (!(testing("Main/test4.txt", BUFFER_SIZE, get_next_line)))
		printf("%s[CRASH]%s ", RED, RESET);

	if (get_next_line(open("Main/test5.txt", O_RDONLY), &line) == -1)
		printf("%s[OK]%s ", GREEN, RESET);
	else
		printf("%s[KO]%s ", YELLOW, RESET);
	printf("\n");
	return (0);
}
