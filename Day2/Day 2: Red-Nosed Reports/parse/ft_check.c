#include "../Red-Nosed.h"

int diff(int n1, int n2)
{
	if (n1 < n2)
		return (n2 - n1);
	return (n1 - n2);
}

int	check_order(char **str)
{
	int i = 1;
	int j = 0;
	int	n1;
	int n2;

	while (str[j + 1])
	{
		n1 = atoi(str[j]);
		n2 = atoi(str[j + 1]);
		if (n1 == n2)
			return (0);
		j++;
	}
	n1 = atoi(str[0]);
	n2 = atoi(str[1]);
	while (str[i] && n1 < n2)
	{
		n1 = atoi(str[i - 1]);
		n2 = atoi(str[i]);
		if ((n1 > n2) || diff(n1, n2) > 3)
			return (0);
		i++;
	}
	while (str[i] && n1 > n2)
	{
		n1 = atoi(str[i - 1]);
		n2 = atoi(str[i]);
		if ((n1 < n2) || diff(n1, n2) > 3)
			return (0);
		i++;
	}
	return (1);
}
