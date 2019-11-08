/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   genome.c                                                                 */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/08 09:28:31 by ||||||                                   */
/*   Updated: 2019/11/08 10:46:23 by ||||||                                   */
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
	neu	*neuron;
	neuron = malloc(sizeof(neu));
	neuron->id = ++g_id;
	neuron->type = t;
	neuron->in = 0;
	neuron->out = 0;
	neuron->threshold = 0;
	neuron->op = 0;
	neuron->innov = ++g_innov;
	neuron->next = next;
	return (neuron);
}

void	rnd_from_genome \
	(t_type t, t_id_innov id_innov)
{
	id_innov.id = 0;
	id_innov.innov = 0;
	return ;
}

// operation_function(t);

