#include "../historian_hysteria.h"

int	getmax(int left, int right)
{
	if (left >= right)
		return (left);
	return (right);
}

int	getmin(int left, int right)
{
	if (left < right)
		return (left);
	return (right);
}

int	operation(t_list **left, t_list **right)
{
	int max;
	int min;
	int result = 0;

	while (*left && *right)
	{
		max = getmax((*left)->n, (*right)->n);
		min = getmin((*left)->n, (*right)->n);
		result += (max - min);
		*left = (*left)->next;
		*right = (*right)->next;
	}
	return (result);
}