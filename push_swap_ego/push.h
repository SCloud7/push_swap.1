/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sila <sila@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:32:10 by sila              #+#    #+#             */
/*   Updated: 2024/11/22 21:40:11 by sila             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
#define PUSH_H


#include"struct.h"
#include<unistd.h>
# include<stdio.h>
# include <limits.h> 
# include "./lib/libft.h"


//commands
void push(t_node **dst, t_node **src);
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);
void reverse_rotate(t_node **lst);
void	rra(t_node **a);
void	rrb(t_node **b);
void rotate(t_node** lst);
void	ra(t_node **a);
void	rb(t_node **b);
void swap(t_node **lst);
void	sa(t_node **a);
void	sb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	rr(t_node **a, t_node **b);


// errors
int bad_syntax(char *str);
int error_dup(t_node *a, int n);
void free_lst(t_node **lst);
void free_errors(t_node **lst);

//init_a
void    actual_index(t_node *lst);
void set_target_a(t_node *a, t_node *b);
void cost_a(t_node *a, t_node *b);
void set_cheapest(t_node *st);
void init_lst_a(t_node *a, t_node *b);


//init_b
void set_target_b(t_node *a, t_node *b);
void init_lst_b(t_node *a, t_node *b);


//init list
long	ft_atol(const char *s);
void add_nodes(t_node **lst, int n);
void prep_lst_a(t_node **a, char **av);
t_node *get_cheapest(t_node *lst);
void pre_push(t_node **lst, t_node *top, char c);


//utils
int list_len(t_node *lst);
t_node *find_last(t_node *lst);
int sorted(t_node *lst);
t_node *find_min(t_node *lst);
t_node *find_max(t_node *lst);


void sort_three(t_node **lst);
void rot_both(t_node **a, t_node **b, t_node *ch);
void rev_rot_both(t_node **a, t_node **b, t_node *ch);
void sort(t_node **a, t_node **b);
void	move_a_to_b(t_node **a, t_node **b) ;
void min_to_top(t_node **a);



void sort_three(t_node **lst);
void rot_both(t_node **a, t_node **b, t_node *ch);
void rev_rot_both(t_node **a, t_node **b, t_node *ch);
void sort(t_node **a, t_node **b);
void	move_a_to_b(t_node **a, t_node **b);
void move_b_to_a(t_node **a, t_node **b);
void min_to_top(t_node **a);


#endif
