/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:39:32 by tkannane          #+#    #+#             */
/*   Updated: 2023/12/30 11:39:26 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return (-1);
	last = ft_last(*stack);
	last->prev->next = NULL;
	last->next = (*stack);
	last->prev = NULL;
	(*stack) = last;
	last->next->prev = last;
	return (0);
}

void	rra(t_stack **a)
{
	if (rrotate(a) == 0)
		write(1, "rra\n", 4);
	else
		return ;
}

void	rrb(t_stack **b)
{
	if (rrotate(b) == 0)
		write(1, "rrb\n", 4);
	else
		return ;
}

void	rrr(t_stack **a, t_stack **b)
{
	if (rrotate(a) == 0 && rrotate(b) == 0)
		write (1, "rrr\n", 4);
	else
		return ;
}
