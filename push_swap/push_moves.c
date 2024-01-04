/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:40:12 by tkannane          #+#    #+#             */
/*   Updated: 2023/12/30 11:58:18 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*node;

	if (!(*stack_from))
		return (-1);
	node = *stack_from;
	(*stack_from) = (*stack_from)->next;
	if (*stack_from)
		(*stack_from)->prev = NULL;
	node->prev = NULL;
	if (!(*stack_to))
	{
		(*stack_to) = node;
		node->next = NULL;
	}
	else
	{
		node->next = (*stack_to);
		node->next->prev = node;
		(*stack_to) = node;
	}
	return (1);
}

int	pb(t_stack **stack_to, t_stack **stack_from)
{
	if (push(stack_to, stack_from) == -1)
		return (-1);
	write (1, "pb\n", 3);
	return (0);
}

int	pa(t_stack **stack_to, t_stack **stack_from)
{
	if (push(stack_to, stack_from) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}
