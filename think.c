/* ************************************************************************** */
/*                                                                            */
/*                                                            :::::::  ::::   */
/*   think.c                                                    ::: : :::     */
/*                                                             :: :: :  ::    */
/*   By: fde-c <x@y.z>                                         :  :    : :    */
/*                                                            :   :  :        */
/*   Created: 2019/10/31 14:04:37 by fde-c                     :::::: ::::    */
/*   Updated: 2019/10/31 14:05:40 by fde-c                     ::: : :::      */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

float           b_fractal(brain b, int in[3], b_node n)
{
        int     i;
        i = -1;
        while (++i < 5)
        {
        // sigmoid children
        }
        return (123);
}

int             b_think(brain b, int in[3])
{
        int     i;

        i = -1;
        while (++i < 3)
        {
                b.node[i].val = b_fractal(b, in, b.node[i]);
                printf("[%d] %f || ", i, b.node[i].val);
        }
        return (1);
}
