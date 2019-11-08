/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   genome.c                                                                 */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/08 09:28:31 by ||||||                                   */
/*   Updated: 2019/11/08 12:07:12 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

gnm		*init_genome(void)
{
	gnm *genome;
	genome = malloc(sizeof(gnm));
	genome->bias = gen_neuron(TP_B, 0);
	genome->inpu = gen_neuron(TP_I, 0);
	genome->hidd = gen_neuron(TP_H, 0);
	genome->outp = gen_neuron(TP_O, 0);
	genome->axon = gen_neuron(TP_A, 0);

	return (genome);
}

neu		*gen_neuron(t_type t, neu *next)
{
	neu			*neuron;
	t_id_innov	temp_neuron;

	neuron = malloc(sizeof(neu));
	neuron->id = ++g_id;
	neuron->type = t;
	if (t != TP_A)
	{
		neuron->in = 0;
		neuron->out = 0;
	}
	else
	{
		rnd_from_genome( \
			TP_B + TP_I + TP_H, \
			temp_neuron);
		neuron->in = temp_neuron.id;
		rnd_from_genome( \
			TP_H + TP_O, \
			temp_neuron);
		neuron->out = temp_neuron.id;
	}
	neuron->threshold = rnd01();
	neuron->op = 0;
	neuron->innov = ++g_innov;
	neuron->next = next;
	return (neuron);
}

void	rnd_from_genome \
	(t_type t, t_id_innov id_innov)
{
	net		rnd_list;
	t_id	rnd_l;

	rnd_l = 0;
	if (t & TP_B)
		rnd_l += net_concat(&g_genome->bias, rnd_list);
	if (t & TP_I)
		rnd_l += net_concat(&g_genome->inpu, rnd_list);
	if (t & TP_H)
		rnd_l += net_concat(&g_genome->hidd, rnd_list);
	if (t & TP_O)
		rnd_l += net_concat(&g_genome->outp, rnd_list);
	if (t & TP_A)
		rnd_l += net_concat(&g_genome->axon, rnd_list);

	id_innov.id = 0;
	id_innov.innov = 0;
	return ;
}

// operation_function(t);

