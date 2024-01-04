/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:56:21 by tkannane          #+#    #+#             */
/*   Updated: 2023/12/23 16:00:32 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*max_node(t_stack *stack)
{
	long	max;
	t_stack	*max_n;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->num > max)
		{
			max = stack->num;
			max_n = stack;
		}
		stack = stack->next;
	}
	return (max_n);
}

t_stack	*min_node(t_stack *stack)
{
	long	min;
	t_stack	*min_n;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->num < min)
		{
			min = stack->num;
			min_n = stack;
		}
		stack = stack->next;
	}
	return (min_n);
}

t_stack	*cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	check_for_push(t_stack **stack, t_stack *head, char name)
{
	while ((*stack) != head)
	{
		if (name == 'a')
		{
			if (head->above_middle)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (head->above_middle)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
