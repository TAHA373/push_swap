/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:18:51 by tkannane          #+#    #+#             */
/*   Updated: 2023/12/30 12:20:44 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_syntax(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '+' || s[i] == '-') && !is_digit(s[i + 1]))
		return (1);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (is_digit(s[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_double(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->num == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current_node;

	current_node = *stack;
	if (!stack)
		return ;
	while (current_node)
	{
		tmp = current_node->next;
		current_node->num = 0;
		free(current_node);
		current_node = tmp;
	}
	*stack = NULL;
}

void	free_error(t_stack **stack)
{
	free_stack(stack);
	write (1, "Error\n", 7);
	exit(1);
}
