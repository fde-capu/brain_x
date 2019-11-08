/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   brain.c                                                                  */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 02:05:31 by ||||||                                   */
/*   Updated: 2019/11/08 08:39:28 by ||||||                                   */
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
	brain->bias = create_neuron(TP_B);
	brain->inpu = create_neuron(TP_B);
	brain->hidd = create_neuron(TP_B);
	brain->outp = create_neuron(TP_B);
	brain->axon = create_neuron(TP_B);
	return (brain);
}

net	*create_neuron(signed char n)
{
	net	*neuron;
	return (neuron);
}
