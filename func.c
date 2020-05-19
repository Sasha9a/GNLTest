#include "header.h"

static size_t	f_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*f_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = f_strlen((char*)s1) + f_strlen((char*)s2) + 1;
	if (!(res = malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

static char		*f_strjoin_n(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = f_strlen((char*)s1) + f_strlen((char*)s2) + 2;
	if (!(res = malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\n';
	j++;
	res[i + j] = '\0';
	return (res);
}

static char	*f_strdup(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	f_strncmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	*res1;

	i = 0;
	res = (unsigned char *)s1;
	res1 = (unsigned char *)s2;
	while (res[i] && res1[i])
	{
		if (res[i] != res1[i])
			return (res[i] - res1[i]);
		i++;
	}
	if (res[i] != res1[i])
		return (res[i] - res1[i]);
	return (0);
}

void    *testing(char *s, size_t size, int (*f)(int, char**))
{
    int fd;
	char *t;
	char *textFile;
	int	byte;
	char buff[size + 1];

	int fdTest;
	char *result;
	int ret;
	char *line;

    if(!(textFile = f_strdup("")) || !(result = f_strdup("")))
	{
		printf("Error file main.c");
		return (NULL);
	}
    fd = open(s, O_RDONLY);
	while ((byte = read(fd, buff, size)) > 0)
	{
		buff[byte] = '\0';
		t = textFile;
		if (!(textFile = f_strjoin(t, buff)))
		{
			free(textFile);
			printf("Error file main.c");
			return (NULL);
		}
	}
	fdTest = open(s, O_RDONLY);
	while ((ret = f(fdTest, &line)) > 0)
	{
		t = result;
		if (!(result = f_strjoin_n(t, line)))
		{
			free(result);
			free(textFile);
			printf("Error file main.c");
			return (NULL);
		}
	}
	t = result;
	if (!(result = f_strjoin(t, line)))
	{
		free(result);
		free(textFile);
		printf("Error file main.c");
		return (NULL);
	}
	if (!f_strncmp(textFile, result))
		printf("%s[OK]%s ", GREEN, RESET);
	else
		printf("%s[KO]%s ", YELLOW, RESET);
	free(result);
	free(textFile);
    return ((void *)1);
}

void    *testing_bonus(char *s, char *s1, char *s2, char *s3, size_t size, int (*f)(int, char**))
{
    int fd;
	char *t;
	char *textFile;
	int	byte;
	char buff[size + 1];

	int fdTest;
	int fdTest1;
	int fdTest2;
	char *result;
	int ret;
	char *line;

    if(!(textFile = f_strdup("")) || !(result = f_strdup("")))
	{
		printf("Error file main.c");
		return (NULL);
	}
    fd = open(s3, O_RDONLY);
	while ((byte = read(fd, buff, size)) > 0)
	{
		buff[byte] = '\0';
		t = textFile;
		if (!(textFile = f_strjoin(t, buff)))
		{
			free(textFile);
			printf("Error file main.c");
			return (NULL);
		}
	}
	fdTest = open(s, O_RDONLY);
	fdTest1 = open(s1, O_RDONLY);
	fdTest2 = open(s2, O_RDONLY);
	if ((ret = f(fdTest, &line)) > 0)
	{
		t = result;
		if (!(result = f_strjoin_n(t, line)))
		{
			free(result);
			free(textFile);
			printf("Error file main.c");
			return (NULL);
		}
	}
	if ((ret = f(fdTest, &line)) > 0)
	{
		t = result;
		if (!(result = f_strjoin_n(t, line)))
		{
			free(result);
			free(textFile);
			printf("Error file main.c");
			return (NULL);
		}
	}
	if ((ret = f(fdTest2, &line)) > 0)
	{
		t = result;
		if (!(result = f_strjoin_n(t, line)))
		{
			free(result);
			free(textFile);
			printf("Error file main.c");
			return (NULL);
		}
	}
	if ((ret = f(fdTest1, &line)) > 0)
	{
		t = result;
		if (!(result = f_strjoin_n(t, line)))
		{
			free(result);
			free(textFile);
			printf("Error file main.c");
			return (NULL);
		}
	}
	if ((ret = f(fdTest2, &line)) > 0)
	{
		t = result;
		if (!(result = f_strjoin_n(t, line)))
		{
			free(result);
			free(textFile);
			printf("Error file main.c");
			return (NULL);
		}
	}
	while ((ret = f(fdTest1, &line)) > 0)
	{
		t = result;
		if (!(result = f_strjoin_n(t, line)))
		{
			free(result);
			free(textFile);
			printf("Error file main.c");
			return (NULL);
		}
	}
	t = result;
	if (!(result = f_strjoin_n(t, line)))
	{
		free(result);
		free(textFile);
		printf("Error file main.c");
		return (NULL);
	}
	if ((ret = f(fdTest2, &line)) > 0)
	{
		t = result;
		if (!(result = f_strjoin(t, line)))
		{
			free(result);
			free(textFile);
			printf("Error file main.c");
			return (NULL);
		}
	}
	if (!f_strncmp(textFile, result))
		printf("%s[OK]%s ", GREEN, RESET);
	else
		printf("%s[KO]%s ", YELLOW, RESET);
	free(result);
	free(textFile);
    return ((void *)1);
}