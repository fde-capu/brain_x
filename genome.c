/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   genome.c                                                                 */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/08 09:28:31 by ||||||                                   */
/*   Updated: 2019/11/24 16:53:29 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*init_genome(tid b, tid i, \
		tid h, tid o, tid a)
{
	g_gnm = malloc(sizeof(gnm));
	g_gnm->bias = gen_neuron (TP_B, b);
	g_gnm->inpu = gen_neuron (TP_I, i);
	g_gnm->hidd = gen_neuron (TP_H, h);
	g_gnm->outp = gen_neuron (TP_O, o);
	g_gnm->axon = gen_neuron (TP_A, a);
	return ;
}

neu		*gen_neuron(typ t, int n)
{
	neu	*neuron;
	neu	*nx;
	neu	*head;

	nx = 0;
	while (--n > -1)
	{
		neuron = init_neu();
		neuron->id = ++g_id;
		neuron->tp = t;
		TTPA
		{
			neuron->in = \
				rnd_from_genome( \
				TP_B + TP_I + TP_H).id;
			neuron->ou = \
				rnd_from_genome( \
				TP_H + TP_O).id;
		}
		else
		{
			neuron->in = 0;
			neuron->ou = 0;
		}
		neuron->tr = t & TP_B ? \
				0 : rnd01();
		neuron->op = t & TP_B ? \
				&op_bias : &op_spark;
		neuron->re = ALL_RE;
		neuron->iv = ++g_iv;
		neuron->nx = nx;
		nx = neuron;
	}
	return (neuron);
}

neu		*init_neu(void)
{
	neu *n;

	n = malloc(sizeof(neu));
	n->id = 0;
	n->tp = 0;
	n->in = 0;
	n->ou = 0;
	n->tr = 0;
	n->op = 0;
	n->re = 0;
	n->iv = 0;
	n->nx = 0;
	return (n);
}

neu		rnd_from_genome(typ t)
{
	tid	cb[GNM_NETS_N];
	tid	i;
	tid c;
	neu *n;

	i = 0;
	while (++i <= GNM_NETS_N)
		cb[i - 1] = 0;
	TTPB cb[0] += count_neu(g_gnm->bias);
	TTPI cb[1] += count_neu(g_gnm->inpu);
	TTPH cb[2] += count_neu(g_gnm->hidd);
	TTPO cb[3] += count_neu(g_gnm->outp);
	TTPA cb[4] += count_neu(g_gnm->axon);
	c = 0;
	i = 0;
	while (++i <= GNM_NETS_N)
		c += cb[i - 1];
	c = irnd(c);
	n = init_neu();
	TTPA n = g_gnm->axon;
	TTPO n = g_gnm->outp;
	TTPH n = g_gnm->hidd;
	TTPI n = g_gnm->inpu;
	TTPB n = g_gnm->bias;
	TTPA i = 4;
	TTPO i = 3;
	TTPH i = 2;
	TTPI i = 1;
	TTPO i = 0;
	while (--c)
	{
		n = n->nx;
		if (!n)
		{
			n = init_neu();
			if (i == 0)
			{
				TTPA n = g_gnm->axon;
				TTPO n = g_gnm->outp;
				TTPH n = g_gnm->hidd;
				TTPI n = g_gnm->inpu;
			}
			if (i == 1)
			{
				TTPA n = g_gnm->axon;
				TTPO n = g_gnm->outp;
				TTPH n = g_gnm->hidd;
			}
			if (i == 2)
			{
				TTPA n = g_gnm->axon;
				TTPO n = g_gnm->outp;
			}
			if (i == 3)
			{
				TTPA n = g_gnm->axon;
				i = 0;
				TTPA	i = 4;
			}
			if (i == 2)
			{
				i = 0;
				TTPA	i = 4;
				TTPO	i = 3;
			}
			if (i == 1)
			{
				i = 0;
				TTPA	i = 4;
				TTPO	i = 3;
				TTPH	i = 2;
			}
			if (i == 0)
			{
				i = 0;
				TTPA	i = 4;
				TTPO	i = 3;
				TTPH	i = 2;
				TTPI	i = 1;
			}
			if (i == 0)	c = 1;
		}
	}
	return (*n);
}
