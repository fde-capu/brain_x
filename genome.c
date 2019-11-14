/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   genome.c                                                                 */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/08 09:28:31 by ||||||                                   */
/*   Updated: 2019/11/14 00:15:06 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		*init_genome(void)
{
	g_genome = malloc(sizeof(gnm));
	g_genome->bias = gen_neuron(TP_B, GENB);
	g_genome->inpu = gen_neuron(TP_I, GENI);
	g_genome->hidd = gen_neuron(TP_H, GENH);
	g_genome->outp = gen_neuron(TP_O, GENO);
	g_genome->axon = gen_neuron(TP_A, GENA);

	print_genome();
	return ;
}

neu			*gen_neuron(t_type t, int n)
{
	neu			*neuron;
	neu			*next;

	next = 0;
	while (--n > -1)
	{
		neuron = malloc(sizeof(neu));
		neuron->id = ++g_id;
		neuron->type = t;
		if (t & TP_A)
		{
			neuron->in = rnd_from_genome( \
				TP_B + TP_I + TP_H).id;
			neuron->out = rnd_from_genome( \
				TP_H + TP_O).id;
		}
		else
		{
			neuron->in = 0;
			neuron->out = 0;
		}
		neuron->threshold = rnd01();
		neuron->op = 0;
		neuron->innov = ++g_innov;
		neuron->next = next;
		next = neuron;
	}
	return (neuron);
}

nii	rnd_from_genome(t_type t)
{
	net		*p;
	nii		out;

	p = init_net(p);
	printf("i->%2x\t%d\n", p, p->id);
	if (t & TP_B)
		p = net_neu_concat\
			(g_genome->bias, p);
	if (t & TP_I)
		p = net_neu_concat\
			(g_genome->inpu, p);
	if (t & TP_H)
		p = net_neu_concat\
			(g_genome->hidd, p);
	if (t & TP_O)
		p = net_neu_concat\
			(g_genome->outp, p);
	if (t & TP_A)
		p = net_neu_concat\
			(g_genome->axon, p);
	printf("o->%2x\t%d\n", p, p->id);
//	print_net(p);


	out.id = 0;
	out.innov = 0;
	//out = get_neu_from_net(\
			irnd(rnd_l), rnd_list);
	return (out);
}
