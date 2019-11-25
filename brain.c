/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   brain.c                                                                  */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 02:05:31 by ||||||                                   */
/*   Updated: 2019/11/24 23:05:33 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bra	*init_brain(\
		tid b, tid i, \
		tid h, 	tid o, 	tid a)
{
	bra	*brain;
	brain = malloc(sizeof(brain));
 brain->bias = rnd_neu(TP_B, b, brain);
 brain->inpu = rnd_neu(TP_I, i, brain);
 brain->hidd = rnd_neu(TP_H, h, brain);
 brain->outp = rnd_neu(TP_O, o, brain);
 brain->axon = rnd_neu(TP_A, a, brain);
	return (brain);
}

net	*rnd_neu(typ t, int q, bra *b)
{
	net	*n;
	neu	g;
	net	*nx;

	n = 0;
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
	n->id = 0;
	n->iv = 0;
	n->bz = 0;
	n->iz = 0;
	n->pt = 0;
	n->nx = 0;
	return (n);
}
