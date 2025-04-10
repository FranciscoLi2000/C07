#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	len;

	if (max < min)
		len = (max - min) * (-1) + 1;
	len = max - min + 1;
	arr = malloc(len * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	while (i < len)
	{
		if (min < max)
			arr[i] = min++;
		else
			arr[i] = min--;
		i++;
	}
	return (arr);
}

#include <stdio.h>

int	main(void)
{
	int	min;
	int	max;
	int	*arr;
	int	i;
	int	n;

	printf("Enter two integers: ");
	scanf("%i %i", &min, &max);
	if (max < min)
		n = (max - min) * (-1) + 1;
	n = max - min + 1;
	arr = ft_range(min, max);
	i = 0;
	while (i < n)
	{
		printf("%i  ", arr[i]);
		i++;
	}
	return (0);
}
