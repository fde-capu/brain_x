/* ******************************************* */
/*                                             */
/*                     ::|::|:::|:|::||::|:||: */
/* genome.c            ||:|:|:||::|:|||::::::| */
/*                     :|||:||:||||||::::::|:: */
/*     |::::| <|::::|>                         */
/*                                             */
/* C20191206173522 |::::|                      */
/* U20191209185313 ||:|||                      */
/*                                             */
/* ******************************************* */

#include "header.h"

void	init_genome(tid b, tid i, \
		tid h, tid o, tid a)
{
	g_gnm = malloc(sizeof(gnm));
	g_gnm->bias = gen_neuron(TP_B, b);
	g_gnm->inpu = gen_neuron(TP_I, i);
	g_gnm->hidd = gen_neuron(TP_H, h);
	g_gnm->outp = gen_neuron(TP_O, o);
	g_gnm->axon = gen_neuron(TP_A, a);
	return ;
}

neu		*gen_neuron(typ t, int n)
{
	neu	*neuron;
	neu	*nx;

	nx = 0;
	while (--n > -1)
	{
		neuron = init_neu();
		neuron->id = ++g_id;
		neuron->tp = t;
		TTPA
		{
			neuron->in = rnd_from_genome(	\
				TP_B + TP_I + TP_H			\
				+ TP_O						\
				)->id;
			neuron->ou = rnd_from_genome(	\
				TP_H + TP_O					\
				+ TP_B + TP_I				\
				)->id;
		}
		else
		{
			neuron->in = 0;
			neuron->ou = 0;
		}
		neuron->tr = rnd01();
		neuron->op = t & TP_B ?	&DEF_OP_BIAS :\
					 t & TP_O ?	&DEF_OP_OUT	 :\
								&DEF_OP		 ;
		neuron->re = &DEF_RE;
		neuron->iv = ++g_iv;
		neuron->nx = nx;
		nx = neuron;
	}
	return (neuron);
}

neu		*rnd_from_genome(typ t)
{
	int	c;
	neu	*n;
	int	i;

	c = 0;
	TTPB c += GENB;
	TTPI c += GENI;
	TTPH c += GENH;
	TTPO c += GENO;
	TTPA c += GENA;
	TTPA i = 4;
	TTPO i = 3;
	TTPH i = 2;
	TTPI i = 1;
	TTPB i = 0;
	c = irnd(c);
	n = i_to_g_niche(i);
	while ((i <= 4) && (c > 1))
	{
		while ((n) && (c > 1))
		{
			n = n->nx;
			if (i == 0)	TTPB c--;
			if (i == 1)	TTPI c--;
			if (i == 2)	TTPH c--;
			if (i == 3)	TTPO c--;
			if (i == 4)	TTPA c--;
		}
		i++;
		if (!n)
			n = i_to_g_niche(i);
	}
	return (n);
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
