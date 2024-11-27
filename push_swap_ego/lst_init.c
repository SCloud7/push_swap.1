/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sila <sila@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:12:26 by sila              #+#    #+#             */
/*   Updated: 2024/11/26 22:04:57 by sila             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push.h"

 long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

void add_nodes(t_node **stack, int n)
{
    t_node	*node; //To store a pointer to the new node to be created with the value `n`
	t_node	*last_node; //To store a pointer to the current last node of the stack

	if (!stack)
		return ;
	node = malloc(sizeof(t_node)); //Allocate memory for the new node
	if (!node)
		return ;
	node->next = NULL; //Set the next pointer of the new node to NULL because it will be the last node in the list
	node->num = n; //Set the `next` data of of the new node to `n` value
	// other elements in the struct could be initialised as well but for now, this was the only one causing a valgrind issue
	if (!(*stack)) //Check if the stack is empty or currently pointing to NULL, indicating a first node needs to be found
	{
		*stack = node; //If empty, update the pointer *stack to point to the node, effectively making it the new head of the linked list
		node->pre = NULL; //Set the head node's previous pointer to NULL as it's the first node
	}
	else //If the stack is not empty, it means there are existing nodes in the linked list
	{
		last_node = find_last(*stack); //In which case, find the last node
		last_node->next = node; //Append the new node to the last node
		node->pre = last_node; //Update the previous pointer of the new node and complete the appending
	}
}

void prep_lst_a(t_node **a, char **av)
{
    long n;
    int i;
    
    i = 0;
    while(av[i])
    {
        if(bad_syntax(av[i]) == -1)
            free_errors(a);
        n = atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
            free_errors(a);
        if(error_dup(*a, n) == -1)
            free_errors(a);
        add_nodes(a, n);
        i++;
    }
}

t_node* get_cheapest(t_node *lst)
{
    if(!lst)
        return(NULL);
    while(lst)
    {
        if(lst->cheap == 1)
            return(lst);
        lst = lst->next;
    }
    return(NULL);
}

void pre_push(t_node **lst, t_node *top, char c)
{
    while(*lst != top)
    {
        if(c == 'a')
        {
            if(top->mid == 0)
                ra(lst);
            else
                rra(lst);
        }
        
        if(c == 'b')
        {
            if(top->mid == 0)
                rb(lst);
            else
                rrb(lst);
        }
    }
}
