/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sila <sila@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:35:19 by sila              #+#    #+#             */
/*   Updated: 2024/11/27 00:37:19 by sila             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"push.h"

void push(t_node **dst, t_node **src)
{
    // Vérifie si la liste source est vide
    if (!*src)
        return;

    // Récupère le premier nœud de la source
    t_node *new = *src;
    *src = (*src)->next;  // Avance la tête de la source

    // Si la source a encore des nœuds, ajuste le pointeur 'pre' du nouveau premier nœud
    if (*src)
        (*src)->pre = NULL;

    // Prépare le nœud transféré
    new->pre = NULL;

    // Si la destination est vide, initialise avec le nœud transféré
    if (!*dst)
    {
        *dst = new;
        new->next = NULL;
    }
    else
    {
        // Ajoute le nœud transféré au début de la destination
        new->next = *dst;
        (*dst)->pre = new;  // Ajuste le pointeur 'pre' de l'ancien premier nœud
        *dst = new;         // Met à jour la tête de la destination
    }
}



void	pa(t_node **a, t_node **b)
{
	push(a, b); 
	printf("pa\n");
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	printf("pb\n");
}

void reverse_rotate(t_node **lst)
{
    if(*lst == NULL || (*lst)->next == NULL)
        return;
    
    t_node *last;

    last = find_last(*lst);
    last->pre->next = NULL;
    last->next = *lst;
    last->pre = NULL;
    *lst = last;
    last->next->pre = last;
}


void	rra(t_node **a)
{
	reverse_rotate(a);
	printf("rra\n");
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	printf("rrb\n");
}

void rotate(t_node** lst)
{
    t_node *last;
    
    if(!*lst || !(*lst)->next)
        return;

    last = find_last(*lst);

    last->next = *lst;
    *lst = (*lst)->next;
    (*lst)->pre = NULL;
    last->next->pre = last;
    last->next->next = NULL;
}

void	ra(t_node **a)
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_node **b)
{
	rotate(b);
	printf("rb\n");
}

void swap(t_node **lst)
{
    if (!*lst || !(*lst)->next)
    {
        return;
    }
	*lst = (*lst)->next; 
	(*lst)->pre->pre = *lst;
	(*lst)->pre->next = (*lst)->next;
	if ((*lst)->next) 
		(*lst)->next->pre = (*lst)->pre; 
	(*lst)->next = (*lst)->pre;
	(*lst)->pre = NULL;
}

void sa(t_node **a) 
{
	swap(a);
	printf("sa\n");
}

void sb(t_node **b) 
{
	swap(b);
    printf("sb\n");
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}
