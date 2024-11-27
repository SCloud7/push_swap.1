/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sila <sila@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:17:48 by sila              #+#    #+#             */
/*   Updated: 2024/11/27 11:31:20 by sila             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"push.h"

void    actual_index(t_node *lst)
{
    int i;
    int m;

    i = 0;
    if(!lst)
        return;
    m = list_len(lst) / 2;
    while(lst)
    {
        lst->index = i;
        if(i <= m)
        {
            //printf("la");
            lst->mid = 0;
        }
            
        else
        {
            //printf("l0");
            lst->mid = 1;
        }
        lst = lst->next;
        //printf("%i \n", lst->mid);
        //printf("le num = %i l'index = %i le mid = %i", lst->num, lst->index, lst->mid);
        ++i;
    }
}

void set_target_a(t_node *a, t_node *b)
{
    t_node *way_b;
    t_node *target;
    long min;

    if(b == NULL)
        printf("b est nul");
    while (a) 
    {
        way_b = b;
        target = NULL; // Initialisation explicite
        min = LONG_MIN;

        while (way_b) 
        {
            if (way_b->num < a->num && way_b->num > min) {
                min = way_b->num;
                target = way_b;
            }
            way_b = way_b->next;
        }
        
        //printf("Le num est : %i et son min est : %li\n", a->num, min);
        if (min == LONG_MIN) 
            a->target = find_max(b);
        else 
            a->target = target;
        a = a->next;
    }
}


void cost_a(t_node *a, t_node *b)
{
    int len_a;
    int len_b;
    
    len_a = list_len(a);
    len_b = list_len(b);
    
    while(a)
    {
        if(a->target == NULL)
            printf("ici\n");
        a->cost = a->index;
        if(a->mid == 1)
            a->cost = len_a - (a->index);
        if(a->target->mid == 0)
            a->cost += a->target->index;
        else
            a->cost += len_b - (a->target->index);
        
        a = a->next;
    }
}

void set_cheapest(t_node *st)
{
    long cheapest;
    t_node *ch;

    if(!st)
        return;
    cheapest = LONG_MAX;
    while(st)
    {
        if(st->cost < cheapest)
        {
            cheapest = st->num;
            ch = st;
        }
        st = st->next;
    }
    ch->cheap = 1;
}
void init_lst_a(t_node *a, t_node *b)
{
    //printf("le a\n");
    actual_index(a);
    //printf("le b\n");
    actual_index(b);
    set_target_a(a, b);
    cost_a(a, b);
    set_cheapest(a);
}