/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:32:14 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/03 11:04:09 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stack
{
	int				num;
	int				index;
	int				above_middle;
	int				push_cost;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	check_arg(t_stack **a, char **av);
t_stack	*ft_last(t_stack *a);
void	insert_node(t_stack **a, int num);
int		check_double(t_stack *a, int n);
int		check_syntax(char *s);
void	free_stack(t_stack **stack);
int		ft_lstsize(t_stack *a);
int		is_digit(char c);
int		swap(t_stack **head);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
int		push(t_stack **stack_to, t_stack **stack_from);
int		pa(t_stack **stack_to, t_stack **stack_from);
int		pb(t_stack **stack_to, t_stack **stack_from);
int		rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
int		rrotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
int		check_sort(t_stack *stack);
t_stack	*max_node(t_stack *stack);
t_stack	*min_node(t_stack *stack);
void	ft_sort_three(t_stack **stack);
void	fill_index(t_stack *stack);
void	calculate_cost(t_stack *a, t_stack *b);
void	find_cheapest(t_stack *stack);
void	inisialize_a(t_stack *a, t_stack *b);
void	inisialize_b(t_stack *a, t_stack *b);
void	stack_sort(t_stack **a, t_stack **b);
t_stack	*cheapest_node(t_stack *stack);
void	check_for_push(t_stack **stack, t_stack *head, char name);
void	min_on_top(t_stack **a);
void	free_error(t_stack **stack);
void	rr_both( t_stack **a, t_stack **b, t_stack *cheapest);
void	rrr_both(t_stack **a, t_stack **b, t_stack *cheapest);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin1(char *left_str, char *buff);
char	*ft_read(char *str_line, int fd);
char	*ft_get_new_str(char *str_line);
char	*ft_get_line(char	*s);
char	*get_next_line(int fd);
int		cmp_do(t_stack **a, t_stack **b, char *cmd);
void	print_checker_res(t_stack **a, t_stack **b);
void	print_error(t_stack **a, t_stack **b);
void	get_the_line(t_stack **a, t_stack **b);
char	**ft_freearg(char **s);
#endif
