/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:41:36 by tkannane          #+#    #+#             */
/*   Updated: 2023/12/27 14:34:12 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **head)
{
	if (!*head || !(*head)->next)
		return (-1);
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
	return (0);
}

void	sa(t_stack **a)
{
	if (swap(a) == 0)
		write(1, "sa\n", 3);
	else
		return ;
}

void	sb(t_stack **b)
{
	if (swap(b) == 0)
		write(1, "sb\n", 3);
	else
		return ;
}

void	ss(t_stack **a, t_stack **b)
{
	if (swap(a) == 0 && swap(b) == 0)
		write(1, "ss\n", 3);
	else
		return ;
}
