/* ******************************************* */
/*                                             */
/*                     ||:|:|:||:|::|:|:::|:|| */
/* main.c              ::||:|::::|:||::::::||| */
/*                     :||::::|::::::||||||:|: */
/*     :|:||| <:|:|||>                         */
/*                                             */
/* C20191203164737 :|:|||                      */
/* U20191208043139 |:|::|                      */
/*                                             */
/* ******************************************* */

#include "header.h"

int	init_env(void)
{
	color(COLOR_FORE);
	init_rnd();
	return (0);
}

int main(void)
{
	bra	*br;
	bra	*b;
	bra *nb;
	tid	i;
	tid	brains = 6;

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
	nb = 0;
	i = 0;
	while(++i <= brains)
	{
		br = init_brain(\
			DEFB,		\
			DEFI,		\
			DEFH,		\
			DEFO,		\
			DEFA 		\
		);
		b = br;
		b->nx = nb;
		nb = b;
	}
	while (1) // until exec break
	{
		if (CLEAR_SCREEN) CLS
		b = br;
		while (b)
		{
			think(b);
			print_brain(b);
			b = b->nx;
		}
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
//
//  Autoresponse:
//	- For every action, a feedback input in self
//
//  Observation inputs
//
//
