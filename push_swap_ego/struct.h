/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sila <sila@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:59:09 by sila              #+#    #+#             */
/*   Updated: 2024/11/26 15:10:18 by sila             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

typedef struct node
{
    int num;
    struct node *next;
    struct node *pre;
    struct node *target;
    int index;
    int cost;
    int mid;
    int cheap;

}       t_node;

#endif