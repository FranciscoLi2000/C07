#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *src)
{
	char	*new;
	char	*tmp;
	int		len;

	len = strlen(src);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	tmp = new;
	while (*src)
		*tmp++ = *src++;
	*tmp = '\0';
	return (new);
}

#include <stdio.h>

int	main(void)
{
	char	str[50];
	char	*new;

	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	new = ft_strdup(str);
	printf("Mine %s\n", new);
	free(new);
	return (0);
}
