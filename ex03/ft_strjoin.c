#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char		*result;

	if (s1 != NULL)
		len1 = strlen(s1);
	else
		len1 = 0;
	if (s2 != NULL)
		len2 = strlen(s2);
	else
		len2 = 0;
	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	if (s1 != NULL)
		memcpy(result, s1, len1);
	if (s2 != NULL)
		memcpy(result + len1, s2, len2);
	result[len1 + len2] = '\0';
	return (result);
}

int	main(void)
{
	char	s1[100];
	char	s2[100];
	char	*joined;

	printf("Enter first string.\n");
	fgets(s1, sizeof(s1), stdin);
	s1[strcspn(s1, "\n")] = '\0';
	printf("Enter second string.\n");
	fgets(s2, sizeof(s2), stdin);
	s2[strcspn(s2, "\n")] = '\0';
	joined = ft_strjoin(s1, s2);
	if (joined == NULL)
	{
		printf("Error: Memory allocation failed.\n");
		return (1);
	}
	printf("Result: %s\n", joined);
	free(joined);
	return (0);
}
