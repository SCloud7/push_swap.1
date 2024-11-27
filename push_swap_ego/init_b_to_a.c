/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sila <sila@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:02:05 by sila              #+#    #+#             */
/*   Updated: 2024/11/22 21:58:50 by sila             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push.h"

void set_target_b(t_node *a, t_node *b)
{
    long maxi;
    t_node *target;
    t_node *cur;

    while(b)
    {
        cur = a;
        maxi = LONG_MAX;
        while(cur)
        {
            if(cur->num > b->num && cur->num < maxi)
            {
                target = cur;
                maxi = cur->num;
            }
            cur = cur->next;
        }
        if(maxi == LONG_MAX)
            b->target = find_min(a);
        else
            b->target = target;
        b = b->next;
    }
}
void init_lst_b(t_node *a, t_node *b)
{
    actual_index(a);
    actual_index(b);
    set_target_b(a, b);
}
