/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:36:39 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/03 11:04:35 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atolong(char *s)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*s == '\t' || *s == '\n'
		|| *s == '\v' || *s == '\f'
		|| *s == '\r' || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (is_digit(*s))
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result * sign);
}

int	ft_lstsize(t_stack *a)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = a;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

t_stack	*ft_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

void	insert_node(t_stack **a, int num)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!a)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->num = num;
	new_node->next = NULL;
	if (!(*a))
	{
		*a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_last(*a);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	check_arg(t_stack **a, char **av)
{
	int		i;
	long	num;

	i = 0;
	while (av[i])
	{
		if (check_syntax(av[i]))
			free_error(a);
		num = ft_atolong(av[i]);
		if (check_double(*a, (int)num))
			free_error(a);
		if (num > INT_MAX || num < INT_MIN)
			free_error(a);
		insert_node(a, (int)num);
		i++;
	}
}
