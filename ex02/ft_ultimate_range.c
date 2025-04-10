#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
	{
		tab = NULL;
		return (0);
	}
	tab = malloc((max - min) * sizeof(int));
	if (!tab)
		return (0);
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

#include <stdio.h>

int	main(void)
{
	int	*tab;
	int	val1;
	int	val2;
	int	i;

	printf("Enter two integers: ");
	scanf("%i %i", &val1, &val2);
	i = ft_ultimate_range(&tab, val1, val2);
	printf("the array has %i elements.\n", i);
	return (0);
}
