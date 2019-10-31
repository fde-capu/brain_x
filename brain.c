/* ************************************************************************** */
/*                                                                            */
/*                                                            :::::::  ::::   */
/*   brain.c                                                    ::: : :::     */
/*                                                             :: :: :  ::    */
/*   By: fde-c <x@y.z>                                         :  :    : :    */
/*                                                            :   :  :        */
/*   Created: 2019/10/31 13:34:28 by fde-c                     :::::: ::::    */
/*   Updated: 2019/10/31 15:14:17 by fde-c                     ::: : :::      */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

brain		gen_brain(int b_size[5])
{
	brain	*out;
	int	i;

	out = malloc(sizeof(brain) +
		(sizeof(b_node) *
		 	(b_size[0] + b_size[1] + b_size[2] + b_size[3])) +
		(sizeof(b_gene) * b_size [4]));

	i = -1;
	while (++i < 4)
		out->size[i] = b_size[i];

	i = -1;
	while (++i < 1)	// bias
	{
		out->node[i].id = ++*g_node_c;
		out->node[i].type = -2;
		out->node[i].val = rnd(1);
	}
	i--;
	while (++i < (1 + 3)) // input
	{
		out->node[i].id = ++*g_node_c;
		out->node[i].type = -1;
		out->node[i].val = 0;
	}
		i--;
	while (++i < (1 + 3 + 5)) // hidden
	{
		out->node[i].id = ++*g_node_c;
		out->node[i].type = 0;
		out->node[i].val = 0;
	}
	i--;
	while (++i < (1 + 3 + 5 + 3)) // output
	{
		out->node[i].id = ++*g_node_c;
		out->node[i].type = 1;
		out->node[i].val = 0;
	}

	i = -1;
	while (++i < 5)	// gene
	{
		out->gene[i].in = irnd(1 + 3 + 5 + 3);
		out->gene[i].out = irnd(1 + 3 + 5 + 3);
		out->gene[i].weight = rnd(1);
		out->gene[i].enabled = brnd(.5);
		out->gene[i].innov = ++*g_gene_c;
	}
	return (*out);
}

int	brain_engine(void)
{
	brain		dig;
	int		response;
	int		feed[3];
	int		brain_size[4]; // bias, in, hidden, out

	feed[0] = 1;
	feed[1] = 0;
	feed[2] = 0;

	dig = gen_brain(brain_size);
	b_plot(dig);

	response = b_think(dig, feed);	
	printf("\n\n---|| %d ||---\n\n", response);

	return (0);
}
