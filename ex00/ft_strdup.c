#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *src)
{
	char	*new;
	int		len;

	len = strlen(src);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (*src)
	{
		*new = *src;
		src++;
	}
	*new = '\0';
	return (new);
}
