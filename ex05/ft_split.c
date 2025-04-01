#include <stdlib.h>
#include <string.h>
/**
 * 根据多个分隔符拆分字符串。
 *  str  要拆分的字符串
 *  delimiters  分隔符集合
 *  字符串数组（以 NULL 结尾，需要使用 free 释放）
 */
static int	word_count(const char *str, char c)
{
	int	count;
	int	in_word;
	int	i;		/* 查找并返回字符串的字数 */

	i = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (str[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

char	*fill_word(const char *start, const char *end)
{
	char	*word;
	int		len;	/* 留足字数 */

	len = end - start;	/* 将单词复制到上面分配的内存中 */
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	memcpy(word, start, len);
	word[len] = '\0';	/* 返回所分配的字 */
	return (word);
}

void	ft_free(char **str)
{
	int	i;

	if (!str)
		return ;	/* free()分配的一切 */
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}			/* 数组中的每个元素以及数组 */
	free(str);
}

char	**ft_split(const char *s, char c)
{
	const char	*start;
	char		**result;
	int			in_word;
	int			count;
	int			i;

	in_word = 0;
	start = NULL;
	i = 0;	/* 分配一个数组，其大小足以容纳 s 中的所有单词 */
	count = word_count(s, c);
	result = malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	/* 在字符串中循环，找出单词的开头 */
	/* 找到词尾 */
	/* 在字词数组的第一个空闲索引处复制世界 */
	/* 返回我们的单词数组 */
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			start = s;
			in_word = 1;
		}
		else if (*s == c && in_word == 1)
		{
			result[i] = fill_word(start, s);
			if (!result[i])
			{
				ft_free(result);
				return (NULL);
			}
			i++;
			in_word = 0;
		}
		s++;
	}
	if (in_word == 1)
	{
		result[i] = fill_word(start, s);
		if (!result[i])
		{
			ft_free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
