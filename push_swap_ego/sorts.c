/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sila <sila@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:29:11 by sila              #+#    #+#             */
/*   Updated: 2024/11/27 11:27:36 by sila             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push.h"

void sort_three(t_node **lst)
{
    t_node *maxi;

    maxi = find_max(*lst);
    if(maxi == *lst)
        ra(lst);
    else if ((*lst)->next == maxi)
        rra(lst);
    if((*lst)->num > (*lst)->next->num)
        sa(lst);    
}

        
void rot_both(t_node **a, t_node **b, t_node *ch)
{
    while(*a != ch && *b != ch->target)
        rr(a, b);
    actual_index(*a);
    actual_index(*b);
}
void rev_rot_both(t_node **a, t_node **b, t_node *ch)
{
    while(*a != ch && *b != ch->target)
        rrr(a, b);
    actual_index(*a);
    actual_index(*b);
}

void sort(t_node **a, t_node **b)
{
    
    if(list_len(*a) > 3 && sorted(*a) == -1)
        pb(b, a);
    if(list_len(*a) > 3 && (sorted(*a) == -1))
    {
        pb(b, a);
        //printf("le num de b = %i", (*b)->num);
    }    
    while(list_len(*a) > 3 && sorted(*a) == -1)
    {
        init_lst_a(*a, *b);
        move_a_to_b(a, b);
    }
    sort_three(a);
    while(*b)
    {
        init_lst_b(*a, *b);
        move_b_to_a(a, b);
        pa(a, b);
    }
    actual_index(*a);
    min_to_top(a);
}
void	move_a_to_b(t_node **a, t_node **b) 
{
    t_node *min;
    
    min = get_cheapest(*a);
    if(min->mid == 0 && min->target->mid == 0)
        rot_both(a, b, min);
    else if (!(min->mid == 0) && !(min->target->mid == 0))
        rev_rot_both(a, b, min);
    pre_push(a, min, 'a');
    pre_push(b, min->target, 'b');
    pb(b, a);
}
void move_b_to_a(t_node **a, t_node **b)
{
    pre_push(a, (*b)->target, 'a');
    pa(a, b);
}

void min_to_top(t_node **a)
{
    while((*a)->num != find_min(*a)->num)
    {
        if(find_min(*a)->mid == 0)
            ra(a);
        else
            rra(a);
    }
}