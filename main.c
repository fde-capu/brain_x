/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 00:42:43 by ||||||                                   */
/*   Updated: 2019/11/08 08:16:31 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	bra	*b;

	init_rnd();
	b = \
		init_brain(      \
			BIAS_TEST_N, \
			INPU_TEST_N, \
			HIDE_TEST_N, \
			OUTP_TEST_N, \
			AXON_TEST_N  \
		);

	//init_biases();
//	init_inputs();
//	init_hiddens();
//	init_outputs();
//	init_axons();
	return (0);
}
