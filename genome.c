/* ******************************************* */
/*                                             */
/*                     |:||||||:|||:|:||:||::| */
/* genome.c            |||::|:|:|::||:|:::|||: */
/*                     ::|::|::::||::::::|:||| */
/*     ||:|:: <|:::||>                         */
/*                                             */
/* C20191211172320 ||:|::                      */
/* U20191227170952 ::||:|                      */
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
		neuron->tp = t;
		TTPA
		{
			neuron->in = rnd_from_genome(TP_TOT - TP_A);
			neuron->ou = rnd_from_genome(TP_TOT - TP_A);
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
			{
				strcpy(neuron->op, DEF_OP_BIAS);
			}
			else
			{
				strcpy(neuron->op, DEF_OP);
			}
		}
		neuron->id = ++g_id;
		neuron->iv = ++g_iv;
		neuron->nx = nx;
		nx = neuron;
		printf("Generated %ld: ", nx->id);
		print_neuron(nx);	
	}
	return (neuron);
}

tid		rnd_from_genome(typ t)
{
	tid	o;
	neu	*n;

	o = irnd(g_id);
	n = neuron_by_id(o);
	while((!n) || ((n) && (n->tp & (TP_TOT - t))))
	{
		o = irnd(g_id);
		n = neuron_by_id(o);
	}
	return	(o);
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
