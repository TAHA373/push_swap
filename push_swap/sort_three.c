/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:09:14 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/03 10:55:14 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	t_stack	*big_node;

	big_node = max_node(*stack);
	if (big_node == (*stack))
		ra(stack);
	else if ((*stack)->next == big_node)
		rra(stack);
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
}

void	min_on_top(t_stack **a)
{
	while ((*a)->num != min_node(*a)->num)
	{
		if (min_node(*a)->above_middle)
			ra(a);
		else
			rra(a);
	}
}

char	**ft_freearg(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}
