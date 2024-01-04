/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:15:43 by tkannane          #+#    #+#             */
/*   Updated: 2023/12/29 18:00:37 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_target_b(t_stack *a, t_stack *b)
{
	t_stack	*a_node;
	t_stack	*target;
	long	great_num;

	while (b)
	{
		a_node = a;
		great_num = LONG_MAX;
		while (a_node)
		{
			if (a_node->num > b->num && a_node->num < great_num)
			{
				great_num = a_node->num;
				target = a_node;
			}
			a_node = a_node->next;
		}
		if (great_num == LONG_MAX)
			b->target_node = min_node(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	fill_index(t_stack *stack)
{
	int	i;
	int	midlle;

	i = 0;
	if (!stack)
		return ;
	midlle = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= midlle)
			stack->above_middle = 1;
		else
			stack->above_middle = 0;
		stack = stack->next;
		++i;
	}
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_middle))
			b->push_cost = size_b - (b->index);
		if (b->target_node->above_middle)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += size_a - (b->target_node->index);
		b = b->next;
	}
}

void	find_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	inisialize_b(t_stack *a, t_stack *b)
{
	fill_index(a);
	fill_index(b);
	find_target_b(a, b);
	calculate_cost(a, b);
	find_cheapest(b);
}
