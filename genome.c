/* ******************************************* */
/*                                             */
/*                     |:||||||:|||:|:||:||::| */
/* genome.c            |||::|:|:|::||:|:::|||: */
/*                     ::|::|::::||::::::|:||| */
/*     ||:|:: <|:::||>                         */
/*                                             */
/* C20191211172320 ||:|::                      */
/* U20191224120240 :|||:|                      */
/*                                             */
/* ******************************************* */

#include "header.h"

void	init_genome()
{
	g_gnm = malloc(sizeof(gnm));
	// v1.0 get setup from genome_config_default.x
	g_gnm->bias = gen_neuron(TP_B, GENB);
	g_gnm->inpu = gen_neuron(TP_I, GENI);
	g_gnm->hidd = gen_neuron(TP_H, GENH);
	g_gnm->outp = gen_neuron(TP_O, GENO);
	g_gnm->axon = gen_neuron(TP_A, GENA);
	save_genome(g_gnm_file, g_gnm);
	return ;
}

neu		*gen_neuron(typ t, int n)
{
	if (!n)	return (0);

	neu	*neuron;
	neu	*nx;

	nx = 0;
	while (--n > -1)
	{
		neuron = init_neu();
		neuron->id = ++g_id;
		neuron->tp = t;
		// is axon just a neuron?
		TTPA
		{
			neuron->in = irnd(g_id);
			neuron->ou = irnd(g_id);
		}
		else
		{
			neuron->in = 0;
			neuron->ou = 0;
		}
		neuron->tr = rnd01();
		TTPA
		{
			strcpy(neuron->re, DEF_RE_AXON);
			strcpy(neuron->op, DEF_OP_AXON);
		}
		else
		{
			strcpy(neuron->re, DEF_RE);
			TTPB
				strcpy(neuron->op, DEF_OP_BIAS);
			else
				strcpy(neuron->op, DEF_OP);
		}
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
	if (!c) return (init_neu());
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

	n = calloc(1, sizeof(neu));
	n->id = 0;
	n->iv = 0;
	n->tp = 0;
	n->in = 0;
	n->ou = 0;
	n->tr = 0;
	int i = -1;
	while (++i < 16)
	{
		n->op[i] = 0;
		n->re[i] = 0;
	}
	n->nx = 0;
	return (n);
}
