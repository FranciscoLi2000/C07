#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* strjoin: 连接多个字符串，使用指定的分隔符
 * size 字符串数量
 * strs 字符串数组
 * sep 分隔符
 * return 连接后的新字符串（需 free 释放） */
static int	get_totallen(int size, char **strs, char *sep)
{
	int	sep_len;
	int	total_len;
	int	i;
	
	if (size == 0)
		return (0);
	sep_len = strlen(sep);
	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += strlen(strs[i]);
		i++;
	}
	total_len += sep_len * (size - 1) + 1;
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_len;
	char	*ptr;
	int			i;

	total_len = get_totallen(size, strs, sep);
	result = (char *)malloc(total_len);
	if (!result)
		return (NULL);
	ptr = result;
	i = 0;
	while (i < size)
	{
		strcpy(ptr, strs[i]);
		ptr += strlen(strs[i]);
		if (i < size - 1)
		{
			strcpy(ptr, sep);
			ptr += strlen(sep);
		}
		i++;
	}
	*ptr = '\0';
	return (result);
}

int	main(int argc, char **argv)
{
	char	*separator;
	char	*result;

	if (argc < 3)
	{
		fprintf(stderr, "Uso: %s <sep> <str1> [str2 ... strN]\n", argv[0]);
		return (1);
	}
	separator = argv[1];
	result = ft_strjoin(argc - 2, &argv[2], separator);
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
	else
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		return (1);
	}
	return (0);
}
