/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:27:04 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/03 13:04:11 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	free_a(t_stack **stack)
{
	free_stack(stack);
}

static int	space_arg(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (is_digit(str[i]))
			count++;
		i++;
	}
	return (count);
}

static void	push_swap(t_stack **a, t_stack **b)
{
	if ((check_sort(*a)) == 0)
	{
		if (ft_lstsize(*a) == 2)
			sa(a);
		else if (ft_lstsize(*a) == 3)
			ft_sort_three(a);
		else
			stack_sort(a, b);
	}
}

static void	init(t_stack **a, t_stack **b, char **av, int ac)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (ac > 2)
	{
		while (++i < ac)
			str = ft_strjoin(str, av[i]);
		av = ft_split(str, ' ');
		if (!av[0])
		{
			free(str);
			ft_freearg(av);
			write(1, "Error\n", 6);
			return ;
		}
	}
	check_arg(a, av);
	push_swap(a, b);
	free_a(a);
	free(str);
	ft_freearg(av);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		if (!space_arg(av[1]))
			return (write(1, "Error\n", 6), 0);
		av = ft_split(av[1], ' ');
	}
	init(&a, &b, av, ac);
}
