/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 00:42:43 by ||||||                                   */
/*   Updated: 2019/11/26 15:40:20 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	init_env(void)
{
	color(COLOR_FORE);
	init_rnd();
	return (0);
}

int	main(void)
{

	bra	*b;

	init_env();

	g_id = 0; // from file
	g_iv = 0; //

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

	while (1) // until exec break
	{
		think(b);
		print_brain(b);
		tic(TIC_SEC);
	}

	return (0);
}


// v.
// types of action (op):
//	* defaults
//
//  - threshold above
//  - threshold below
//
//  	opt(A) spark  || value* || discr			|| multi			|| leaks		||
//  	       1      || value  || abs(thres - val)	|| multiply by tr	|| thres value 	||
//
//  	opt(B)	accu*				|| disp		|| bias		|| axon
//				accumulate value	|| wastes	|| noise	|| treat tr as
//
//		opt(C) divide bus for each out || same bus for each out
//		opt		clip* || acc+1 || op?
//
//	- axon = threshold multiply
//
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
//  - sum_clip : no reduction, only sum until 1
//  - sigmoid
//  
//	Bias behaviors:
//	- random / static / waveshape
//	- continuous / granular
//  - ADSR
//	- local / global / selective
