/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sila <sila@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:37:49 by sila              #+#    #+#             */
/*   Updated: 2024/11/27 11:27:20 by sila             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push.h"

int main(int ac, char **av)
{
    t_node *a;
    t_node *b;

    a = NULL;
    b = NULL;
    if(ac == 1 || (ac == 2 && !av[1][0]))
        return(1);
    else if (ac == 2)
        av = ft_split(av[1], ' ');
    prep_lst_a(&a, av + 1);
    
    if( sorted(a) == -1)
    {
        //printf("dernier cheakpoint\n");

        if(list_len(a) == 2)
            sa(&a);
        else if (list_len(a) == 3)
            sort_three(&a);
        else
            sort(&a, &b);
    }
    free_lst(&a);
    return(0);
}