/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 00:42:43 by ||||||                                   */
/*   Updated: 2019/11/18 17:22:47 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"



int	main(void)
{
	color(COLOR_FORE);
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

	feed(b, 2, rnd01());
	tic(.5);
	print_brain(b);
	think(b);
	tic(.5);
	print_brain(b);
//	tic(.5);
//	print_brain(b);
//	tic(.5);
//	print_brain(b);
//	tic(.5);
//	print_brain(b);

	return (0);
}


// v.
// types of action (op):
//  - threshold
//  	(after threshold yelds 1)
//  - capacitor
//  	(after threshold yelds val)
//  - capacitor dispenser:
//    	(above thres outs only diff from thres)
//  - linear
//  	(multiply by threshold) <-- axons
//  - partial leak
//  	(leak only threshold by each time)
//  - gradative leak
//  	(leak from bz/tr proportion increasinly) 
//  - regressive leak
//  	(leak from bz/tr proportion diminishing) 
//  - ducking
//  	(after tr, tr goes 0 and gradually increases) 
//  - reverb
//  	(always sum fraction of previous out)
//  - delay
//  	(remember past steps and repeat in cicles, decreasinly)
//  - equalizer
//  	(filter bands)
//
// types of reduction (re):
//  - sigmoid
//
// brain log trace
