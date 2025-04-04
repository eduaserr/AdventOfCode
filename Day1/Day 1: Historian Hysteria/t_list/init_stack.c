#include "../historian_hysteria.h"

t_list	*lstnew(int content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->n = content;
	node->next = NULL;
	return (node);
}
t_list	*init_stack(int	nbr)
{
	t_list	*new_node;

		new_node = lstnew(nbr);
		if (!new_node)
			return (NULL);
	return (new_node);
}

t_list	*ft_lstlast_ps(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	lstadd_back(t_list **stack, t_list *node)
{
	if (!(*stack))
		*stack = node;
	else
		ft_lstlast_ps(*stack)->next = node;
}

void	get_nbrs(char **str, t_list **left, t_list **right)
{
	t_list	*new_node;
	int i = 0;

	while (str[i])
	{
		new_node = init_stack(atoi(str[i]));
		if (!new_node)
			return ;
		if (i % 2 == 0)
		{
			lstadd_back(left, new_node);
		}
		else
		{
			lstadd_back(right, new_node);
		}
		i++;
	}
}