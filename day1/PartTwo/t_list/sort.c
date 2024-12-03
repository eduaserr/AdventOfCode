#include "../historian_hysteria.h"

t_list	*sort_list(t_list* lst)
{
	int		swp;
	t_list	*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if (lst->n > lst->next->n)
		{
			swp = lst->n;
			lst->n = lst->next->n;
			lst->next->n = swp;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}