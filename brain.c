/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   brain.c                                                                  */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 02:05:31 by ||||||                                   */
/*   Updated: 2019/11/14 17:32:02 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bra	*init_brain(\
		tid b, tid i, \
		tid h, 	tid o, 	tid a)
{
	bra	*brain;
	brain = malloc(sizeof(brain));
	brain->bias = rnd_neuron(TP_B, b, brain);
	brain->inpu = rnd_neuron(TP_I, i, brain);
	brain->hidd = rnd_neuron(TP_H, h, brain);
	brain->outp = rnd_neuron(TP_O, o, brain);
	brain->axon = rnd_neuron(TP_A, a, brain);
	//putparents
	return (brain);
}

net	*rnd_neuron(typ t, int q, bra *b)
{
	net	*n;
	neu	g;
	net	*nx;

	nx = 0;
	while (--q > -1)
	{
		n = init_net();
		g = rnd_from_genome(t);
		n->id = g.id;
		n->iv = g.iv;
		n->pt = b;
		n->nx = nx;
		nx = n;
	}
	return (n);
}

net	*init_net(void)
{
	net *n;

	n = malloc(sizeof(net));
	n->ps = 0;
	n->id = 0;
	n->iv = 0;
	n->bz = 0;
	n->pt = 0;
	n->nx = 0;
	return (n);
}
