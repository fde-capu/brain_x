/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 00:42:43 by ||||||                                   */
/*   Updated: 2019/11/08 10:43:46 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_id g_id;
t_innov g_innov;
gnm	*g_genome;

int	main(void)
{
	bra	*b;

	init_rnd();
	g_id = 0;
	g_innov = 0;
	g_genome = init_genome();


	b = \
		init_brain(	\
			DEFB,	\
			DEFI,	\
			DEFH,	\
			DEFO,	\
			DEFA 	\
		);

	//init_biases();
//	init_inputs();
//	init_hiddens();
//	init_outputs();
//	init_axons();
	return (0);
}
