/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   genome.c                                                                 */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/08 09:28:31 by ||||||                                   */
/*   Updated: 2019/11/19 16:31:42 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*init_genome(tid b, tid i, tid h, tid o, tid a)
{
	g_genome = malloc(sizeof(gnm));
	g_genome->bias = gen_neuron(TP_B, b);
	g_genome->inpu = gen_neuron(TP_I, i);
	g_genome->hidd = gen_neuron(TP_H, h);
	g_genome->outp = gen_neuron(TP_O, o);
	g_genome->axon = gen_neuron(TP_A, a);
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
		if (t & TP_A)
		{
			neuron->in = rnd_from_genome( \
				TP_B + TP_I + TP_H).id;
			neuron->ou = rnd_from_genome( \
				TP_H + TP_O).id;
		}
		else
		{
			neuron->in = 0;
			neuron->ou = 0;
		}
		neuron->tr = rnd01();
		neuron->op = &op_spark;
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
	if(t & TP_B) cb[0]+=count_neu(g_genome->bias);
	if(t & TP_I) cb[1]+=count_neu(g_genome->inpu);
	if(t & TP_H) cb[2]+=count_neu(g_genome->hidd);
	if(t & TP_O) cb[3]+=count_neu(g_genome->outp);
	if(t & TP_A) cb[4]+=count_neu(g_genome->axon);
	c = 0;
	i = 0;
	while (++i <= GNM_NETS_N)
		c += cb[i - 1];
	c = irnd(c);

	n = t & TP_A ? g_genome->axon : init_neu();
	n = t & TP_O ? g_genome->outp : n;
	n = t & TP_H ? g_genome->hidd : n;
	n = t & TP_I ? g_genome->inpu : n;
	n = t & TP_B ? g_genome->bias : n;

	i = t & TP_A ? 4 : 0;
	i = t & TP_O ? 3 : i;
	i = t & TP_H ? 2 : i;
	i = t & TP_I ? 1 : i;
	i = t & TP_I ? 0 : i;

	while (--c)
	{
		n = n->nx;
		if (!n)
		{
			if (i == 0)
			{
				n = t & TP_A ? g_genome->axon : init_neu();
				n = t & TP_O ? g_genome->outp : n;
				n = t & TP_H ? g_genome->hidd : n;
				n = t & TP_I ? g_genome->inpu : n;
			}
			if (i == 1)
			{
				n = t & TP_A ? g_genome->axon : init_neu();
				n = t & TP_O ? g_genome->outp : n;
				n = t & TP_H ? g_genome->hidd : n;

			}
			if (i == 2)
			{
				n = t & TP_A ? g_genome->axon : init_neu();
				n = t & TP_O ? g_genome->outp : n;

			}
			if (i == 3)
			{
				n = t & TP_A ? g_genome->axon : init_neu();
				i = t & TP_A ? 4 : 0;
			}
			if (i == 2)
			{
				i = t & TP_A ? 4 : 0;
				i = t & TP_O ? 3 : i;
			}
			if (i == 1)
			{
				i = t & TP_A ? 4 : 0;
				i = t & TP_O ? 3 : i;
				i = t & TP_H ? 2 : i;
			}
			if (i == 0)
			{
				i = t & TP_A ? 4 : 0;
				i = t & TP_O ? 3 : i;
				i = t & TP_H ? 2 : i;
				i = t & TP_I ? 1 : i;
			}
			if (i == 0) c = 1;
		}
	}
	return (*n);
}
