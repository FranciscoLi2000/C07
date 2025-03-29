#include <stdlib.h>
int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(int) * (max - min));
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}

#include <stdio.h>
int	main(void)
{
	int	*arr;
	int	x;
	int	y;
	int	i;

	x = 3;
	y = 15;
	arr = ft_range(x, y);
	if (!arr)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	i = 0;
	while (i < y - x)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
	return (0);
}
