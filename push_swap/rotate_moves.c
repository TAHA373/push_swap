/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:39:28 by tkannane          #+#    #+#             */
/*   Updated: 2023/12/29 17:36:24 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return (-1);
	last = ft_last(*stack);
	last->next = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
	return (0);
}

void	ra(t_stack **a)
{
	if (rotate(a) == 0)
		write(1, "ra\n", 3);
	else
		return ;
}

void	rb(t_stack **b)
{
	if (rotate(b) == 0)
		write(1, "rb\n", 3);
	else
		return ;
}

void	rr(t_stack **a, t_stack **b)
{
	if (rotate(a) == 0 && rotate(b) == 0)
		write (1, "rr\n", 3);
	else
		return ;
}
