/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sila <sila@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:40:25 by sila              #+#    #+#             */
/*   Updated: 2024/11/27 11:24:28 by sila             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push.h"


int list_len(t_node *lst)
{
    int i;

    if(!lst)
        return(0);
    i = 0;
    while(lst)
    {   
        lst = lst->next;
        i++;
    }
    return(i);
}

t_node *find_last(t_node *lst)
{
    if(!lst)
        return(NULL);
        
    while(lst->next)
        lst = lst->next;
    return(lst);
}

int sorted(t_node *lst)
{
    if(!lst)
        return(0);
    while(lst->next)
    {
        if(lst->num > lst->next->num)
            return(-1);
        lst = lst->next;
    }
    return(0);
}

t_node *find_min(t_node *lst)
{
    long min;
    t_node *min_node;

    if(!lst)
        return(NULL);
    min = LONG_MAX;
    while(lst)
    {
        if(lst->num < min)
        {
            min = lst->num;
            min_node = lst;
        }
        lst = lst->next;
    }
    return(min_node);
}

t_node *find_max(t_node *lst)
{
    long max;
    t_node *max_node;

    if(!lst)
        return(NULL);
    max = LONG_MIN;
    while(lst)
    {
        if(lst->num > max)
        {
            max = lst->num;
            max_node = lst;
        }
        lst = lst->next;
    }
    return(max_node);
}
