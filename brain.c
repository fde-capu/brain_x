/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   brain.c                                                                  */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 02:05:31 by ||||||                                   */
/*   Updated: 2019/11/08 12:49:28 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bra	*init_brain(        \
		unsigned int b, \
		unsigned int i, \
		unsigned int h, \
		unsigned int o, \
		unsigned int a	\
	)
{
	bra	*brain;
	brain = malloc(sizeof(brain));
	brain->bias = rnd_neuron(TP_B, b);
	brain->inpu = rnd_neuron(TP_I, i);
	brain->hidd = rnd_neuron(TP_H, h);
	brain->outp = rnd_neuron(TP_O, o);
	brain->axon = rnd_neuron(TP_A, a);
	//putparents
	return (brain);
}

net	*rnd_neuron(t_type t, int n)
{
	net	*neu_in_b;
	net	*next;
	t_id_innov	temp_neuron;

	next = 0;
	while (--n > -1)
	{
		neu_in_b = malloc(sizeof(net));
		rnd_from_genome(t, temp_neuron);
		neu_in_b->id = temp_neuron.id;
		neu_in_b->innov = temp_neuron.innov;
		neu_in_b->charge = 0;
		neu_in_b->next = next;
		next = neu_in_b;
	}

	return (neu_in_b);
}
