#include "../historian_hysteria.h"

int	operation(t_list *left, t_list *right)
{
	int	res = 0;
	int i;
	t_list *tmp;

	while (left)
	{
		tmp = right;
		i = 0;
		while (tmp)
		{
			if (left->n == tmp->n)
			{
				i++;
			}
			tmp = tmp->next;
		}
		res += left->n * i;
		left = left->next;
	}
	return (res);
}