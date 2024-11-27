/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_verif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sila <sila@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:46:16 by sila              #+#    #+#             */
/*   Updated: 2024/11/22 22:05:48 by sila             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push.h"

int bad_syntax(char *str_n)
{
    if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9'))) //Check if the first character of the input string does not contain a sign or a digit
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9')) //Check if the first character of the input string contains a sign, but the second character does not contain a digit
		return (1);
	while (*++str_n) //If the error conditions above are passed, pre-increment to point to the next character in the string, and loop until the end of the string is reached
	{
		if (!(*str_n >= '0' && *str_n <= '9')) //Check if the next character in the string is not a digit
			return (1);
	}
	return (0);
}


int error_dup(t_node *a, int n)
{
    if(!a)
        return(0);
    while(a)
    {
        if(a->num == n)
            return(-1);
        a = a->next;
    }
    return(0);
}

void free_lst(t_node **lst)
{
    t_node *way;
    t_node *way_next;
    
    if(!lst)
        return;
    way = *lst;
    while(way)
    {
        way_next = way->next;
        way->num = 0;
        free(way);
        way = way_next;
    }
    *lst = NULL;
}

void free_errors(t_node **lst)
{
    free_lst(lst);
    printf("error\n");
    exit(1);
}