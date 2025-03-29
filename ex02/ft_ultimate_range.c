#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
	{
		tab = NULL;
		return (NULL);
	}
	tab = malloc((max - min) * sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	while (min <= max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	*range = tab;
	return (i);
}
