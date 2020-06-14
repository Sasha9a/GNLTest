#include "header.h"
#include "../get_next_line_bonus.h"

int		main()
{
    char	*line;

	printf("%sget_next_line_bonus:%s ", WHITE, RESET);
	if (!(testing_bonus("Bonus/test.txt", "Bonus/test1.txt", "Bonus/test2.txt", "Bonus/Result/Res.txt", BUFFER_SIZE, get_next_line)))
		printf("%s[CRASH]%s ", RED, RESET);
    if (!(testing_bonus("Bonus/test3.txt", "Bonus/test1.txt", "Bonus/test.txt", "Bonus/Result/Res1.txt", BUFFER_SIZE, get_next_line)))
		printf("%s[CRASH]%s ", RED, RESET);
    
    if (get_next_line(open("Bonus/test3.txt", O_RDONLY), &line) == -1)
		printf("%s[OK]%s ", GREEN, RESET);
	else
		printf("%s[KO]%s ", YELLOW, RESET);
	free(line);
	printf("\n");
	return (0);
}
