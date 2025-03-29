#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*new_nbr;
	int		n;
	int		base_from;
	int		base_to;

	while (isspace(nbr))
		nbr++;
	base_from = strlen(base_from);
	base_to = strlen(base_to);
	n = atoi(nbr);
