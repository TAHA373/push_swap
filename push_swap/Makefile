# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 11:08:57 by tkannane          #+#    #+#              #
#    Updated: 2024/01/03 11:05:04 by tkannane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmd = cc
flags = -Wall -Werror -Wextra
sources = split.c push_swap.c ft_strjoin.c check_errors.c first_step.c push_moves.c swap_moves.c rotate_moves.c rrotate_moves.c sort_three.c stack_utils.c stack_sort.c prepare_a_to_b.c prepare_b_to_a.c
s_bonus = checker.c checker_utils.c get_next_line.c get_next_line_utils.c split.c check_errors.c first_step.c push_moves.c swap_moves.c rotate_moves.c rrotate_moves.c sort_three.c stack_utils.c stack_sort.c prepare_a_to_b.c prepare_b_to_a.c ft_strjoin.c
objs_bns =  $(s_bonus:.c=.o)
objs = $(sources:.c=.o)
NAME = push_swap
BONUS = checker

all: $(NAME) 

$(NAME): $(objs)
		$(cmd) $(flags) $(objs) -o $@

%.o:%.c push_swap.h
		$(cmd) $(flags) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(objs_bns)
		$(cmd) $(flags) $(objs_bns) -o $@

clean:
		rm -rf $(objs) $(objs_bns)

fclean: clean
		rm -rf $(NAME) $(BONUS)

re: fclean all