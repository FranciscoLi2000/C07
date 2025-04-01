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
	char	*str;
	int		total_len;
	int		i;

	total_len = get_totallen(size, strs, sep);
	result = (char *)malloc(total_len);
	if (!result)
		return (NULL);
	str = result;
	i = 0;
	while (i < size)
	{
		strcpy(str, strs[i]);
		str += strlen(strs[i]);
		if (i < size - 1)
		{
			strcpy(str, sep);
			str += strlen(sep);
		}
		i++;
	}
	str[i] = '\0';
	return (result);
}
