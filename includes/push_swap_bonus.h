/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:55:30 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/06/10 14:55:58 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../srcs/libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>

# define TOGETHER 1
# define SEPARATE 2

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*min;
	struct s_stack	*max;
	struct s_stack	*target;
	int				cost;
	int				index;
	int				above_mer;
	struct s_stack	*cheapest;
}	t_stack;

//get input and error handling
int		ft_atol(const char *str);
void	get_and_check_input_bonus(int argc, char **argv, t_stack **a);
void	free_input(int *input, int argc);
void	check_doubles(int *input, int argc);

//make list
void	ft_stckadd_back(t_stack **a, t_stack *newest);
void	make_stack(int *input, t_stack **a, int argc);
t_stack	*ft_stcklast(t_stack **lst);
void	free_stack(t_stack *stack);
void	display_list(t_stack **a);
void	error_exit(void);
int		is_space(char c);

//operations
void	swap_stack(t_stack **a);
void	op_sa(t_stack **a);
void	op_sb(t_stack **b);
void	op_ss(t_stack **a, t_stack **b);
void	push(t_stack **take, t_stack **put);
void	op_pa(t_stack **a, t_stack **b);
void	op_pb(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	op_ra(t_stack **a);
void	op_rb(t_stack **b);
void	op_rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack);
void	op_rra(t_stack **a);
void	op_rrb(t_stack **b);
void	op_rrr(t_stack **a, t_stack **b);
void	sort_small(t_stack **a);
int		ft_get_length(t_stack **lst);
int		is_sorted(t_stack **a);
int		is_sorted_circular(t_stack **a);
int		do_circular_check(t_stack **a, t_stack *temp, t_stack *min_sep);

//get next line
char	*get_next_line(int fd);
char	*ft_read_and_check(int fd, char *temp);
char	*ft_excerpt_line(char *temp);
char	*keep_rest(char *temp);
int		new_line_check(const char *str);

//get operations
void	make_operation(t_stack **a, t_stack **b, char *line);
void	read_and_make_operations(t_stack **a, t_stack **b);

//big sort
void	sort_big(t_stack **a, t_stack **b);
void	make_targets(t_stack **a, t_stack **b);
void	find_min(t_stack **stack);
void	find_max(t_stack **stack);
void	find_target_b(t_stack *temp, t_stack **b);
void	sorted_push(t_stack **a, t_stack **b);
void	set_indexes_meridians(t_stack **stack);
void	set_indexes_only(t_stack **a);
void	calculate_cost(t_stack **a, t_stack **b);
void	set_cheapest(t_stack **stack);
void	move_node(t_stack **a, t_stack **b);
void	make_reverse_targets(t_stack **a, t_stack **b);
void	find_target_a(t_stack *temp, t_stack **a);
void	reverse_sorted_push(t_stack **a, t_stack **b);
void	reverse_move_node(t_stack **a, t_stack **b);
void	put_min_on_top(t_stack **a);
t_stack	*find_min_for_circular_check(t_stack **stack);
void	move_separately_up_down(t_stack **a, t_stack **b);
void	move_separately_down_up(t_stack **a, t_stack **b);
void	move_together(t_stack **a, t_stack **b, int mer);
void	reverse_move_separately_up_down(t_stack **a, t_stack **b);
void	reverse_move_separately_down_up(t_stack **a, t_stack **b);
void	reverse_move_together(t_stack **a, t_stack **b, int mer);

#endif
