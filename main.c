/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 00:42:43 by ||||||                                   */
/*   Updated: 2019/11/08 10:16:36 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bra	genome;

int	main(void)
{
	bra	*b;

	init_rnd();
	genome = init_genome();

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
