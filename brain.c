/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   brain.c                                                                  */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 02:05:31 by ||||||                                   */
/*   Updated: 2019/11/23 22:38:56 by ||||||                                   */
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
		n->nx = nx;
		STRESS_BRAIN_CREATION
		do {
			STRESSMSG(BRAIN_ERROR)
			g = rnd_from_genome(t);
		} while (find_id(g.id, n));
		nx = n;
		n->id = g.id;
		n->iv = g.iv;
		n->pt = b;
	}
	return (n);
}

net	*init_net(void)
{
	net *n;

	n = malloc(sizeof(net));
//	n->ps = 0;
	n->id = 0;
	n->iv = 0;
	n->bz = 0;
	n->bz_ = 0;
	n->pt = 0;
	n->nx = 0;
	return (n);
}
