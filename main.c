/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 00:42:43 by ||||||                                   */
/*   Updated: 2019/11/18 13:13:10 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"



int	main(void)
{
	bra	*b;

	init_rnd();
	g_id = 0;
	g_iv = 0;
	init_genome(	\
		GENB,		\
		GENI,		\
		GENH,		\
		GENO,		\
		GENA		\
	);
	print_genome();

	b =	init_brain(	\
		DEFB,		\
		DEFI,		\
		DEFH,		\
		DEFO,		\
		DEFA 		\
	);
	print_brain(b);

	feed(b, 2);
	tic(.5);
	print_brain(b);
	think(b);
	tic(.5);
	print_brain(b);
	tic(.5);
	print_brain(b);
//	tic(.5);
//	print_brain(b);
//	tic(.5);
//	print_brain(b);

	return (0);
}


// v.
// types of action:
//  - threshold
//  - capacitor
//  - capacitor dispenser:
//    above thres outs only diff from thres
//  - linear
//  - partial leak
//  - gradative leak
//  - regressive leak
//  - ducking
//  - reverb
//  - delay
//  - equalizer
//
// types of op:
//  - sigmoid
//
// brain log trace
