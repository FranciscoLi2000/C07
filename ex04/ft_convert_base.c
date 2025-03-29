#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

static int	get_base(char *base)
{
    int			i;
	int			j;

    if (!base[0] || !base[1])
        return (0);
	i = 0;
    while (base[i] != '\0')
    {
        if (!isdigit(base[i]))
            return (0);
		j = i + 1;
        while (base[j] != '\0')
		{
            if (base[i] == base[j])
                return (0);
			j++;
		}
		i++;
    }
    return (i);
}

int ft_atoi_base(char *str, char *base)
{
    int         nb;
    int         sign;
    int         base_len;

    nb = 0;
    sign = 1;
    base_len = get_base(base);
    if (base_len < 2)
        return (0);
    while (isspace(*str))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str++ == '-')
            sign = -1;
        sign = 1;
    }
    while (*str)
    {
        while (*base != '\0' && *base != *str)
            base++;
        if (!*base)
            break ;
        nb = nb * base_len + *base;
        str++;
    }
    return (nb * sign);
}

static int	count_numlen(int n)
{
	int			count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n)
	{
		count++;
		n /= 10;
	}
}
