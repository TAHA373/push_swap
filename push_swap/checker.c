/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:53:53 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/03 13:12:18 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_the_line(t_stack **a, t_stack **b)
{
	char	*get_line;

	get_line = get_next_line(0);
	while (get_line)
	{
		if (cmp_do(a, b, get_line))
			print_error(a, b);
		free(get_line);
		get_line = get_next_line(0);
	}
}

static void	check_init(t_stack **a, t_stack **b, char **av, int ac)
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
	ft_freearg(av);
	free(str);
	get_the_line(a, b);
	print_checker_res(a, b);
}

static int	space_arg1(char *str)
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		if (!space_arg1(av[1]))
			return (write(1, "Error\n", 6), 0);
		av = ft_split(av[1], ' ');
	}
	check_init(&a, &b, av, ac);
}
