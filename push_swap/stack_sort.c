/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:02:34 by tkannane          #+#    #+#             */
/*   Updated: 2023/12/29 19:14:54 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_b(t_stack **a, t_stack **b)
{
	t_stack	*the_cheapest;

	the_cheapest = cheapest_node(*b);
	if (the_cheapest->above_middle && the_cheapest->target_node->above_middle)
		rr_both(a, b, the_cheapest);
	else if (the_cheapest->above_middle == 0
		&& the_cheapest->target_node->above_middle == 0)
		rrr_both(a, b, the_cheapest);
	check_for_push(b, the_cheapest, 'b');
	check_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	rr_both( t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest != *b && cheapest->target_node != *a)
		rr(a, b);
	fill_index(*a);
	fill_index(*b);
}

void	rrr_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest != *b && cheapest->target_node != *a)
		rrr(a, b);
	fill_index(*a);
	fill_index(*b);
}

void	stack_sort(t_stack **a, t_stack **b)
{
	int		stack_size;
	t_stack	*max;
	t_stack	*min;
	int		med;

	stack_size = ft_lstsize(*a);
	max = max_node(*a);
	min = min_node(*a);
	med = (max->num + min->num) / 2;
	while (stack_size-- > 3 && !(check_sort(*a)))
	{
		inisialize_a(*a, *b);
		pb(b, a);
		if ((*b)->num >= med)
			rb(b);
	}
	ft_sort_three(a);
	while (*b)
	{
		inisialize_b(*a, *b);
		move_b(a, b);
	}
	fill_index(*a);
	min_on_top(a);
}
