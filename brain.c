/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   brain.c                                                                  */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 02:05:31 by ||||||                                   */
/*   Updated: 2019/11/14 15:57:24 by ||||||                                   */
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

	n = init_net(b);
	return (n);
}

net	*init_net(bra *b)
{
	net *n;

	n = malloc(sizeof(net));
//	n->ps = ;
	n->id = 0;
	n->iv = 0;
	n->bz = 0;
	n->pt = b;
	n->nx = 0;
	return (n);
}
