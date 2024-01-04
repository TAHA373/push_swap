/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:42:05 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/03 12:16:21 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	cmp_do(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		return (push(a, b), 0);
	if (!ft_strcmp(cmd, "pb\n"))
		return (push(b, a), 0);
	if (!ft_strcmp(cmd, "sa\n"))
		return (swap(a));
	if (!ft_strcmp(cmd, "sb\n"))
		return (swap(b), 0);
	if (!ft_strcmp(cmd, "ss\n"))
		return (swap(a), swap(b), 0);
	if (!ft_strcmp(cmd, "ra\n"))
		return (rotate(a), 0);
	if (!ft_strcmp(cmd, "rb\n"))
		return (rotate(b), 0);
	if (!ft_strcmp(cmd, "rr\n"))
		return (rotate(a), rotate(b), 0);
	if (!ft_strcmp(cmd, "rra\n"))
		return (rrotate(a), 0);
	if (!ft_strcmp(cmd, "rrb\n"))
		return (rrotate(b), 0);
	if (!ft_strcmp(cmd, "rrr\n"))
		return (rrotate(a), rrotate(b), 0);
	else
		return (1);
}

void	print_checker_res(t_stack **a, t_stack **b)
{
	if (check_sort(*a))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	if (*a)
		free_stack(a);
	if (*b)
		free_stack(b);
}

void	print_error(t_stack **a, t_stack **b)
{
	if (*a)
		free_stack(a);
	if (*b)
		free_stack(b);
	write(1, "Error\n", 6);
	exit(1);
}
