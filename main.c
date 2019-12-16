/* ******************************************* */
/*                                             */
/*                     |||:|||:|:||||::|||:::| */
/* main.c              |:||:|::||::|:||::::|:| */
/*                     :|:::|::|::::::||||||:| */
/*     |:|||: <|:|||:>                         */
/*                                             */
/* C20191211154835 |:|||:                      */
/* U20191216155512 :|::||                      */
/*                                             */
/* ******************************************* */

#include "header.h"

int	init_envt(void)
{
	char	def_gnm[] = DEF_GENOME;
	char	*p;
	char	*r;

	g_gnm_file = malloc(sizeof(char) * \
		FILE_NAME_LIMIT);
	p = g_gnm_file;
	r = def_gnm;
	while (*r != 0)
	{
		*p = *r;
		r++;
		p++;
	}
	*p = 0;
	color(COLOR_FORE);
	init_rnd();
	return (0);
}

void	option(char	*op)
{
	char	*p;

	p = op;
	while (*p != '=')
		p++;
	p++;
	if (strm(op, "genome"))
		g_gnm_file = p;
	return ;
}

int main(int argc, char **argv)
{
	init_envt();
	//while (argc > 1)
	//{
	//	option(argv[argc - 1]);
	//	argc--;
	//}
	//printf("%s\n", g_gnm_file);
	//init_genome(	\
	//	GENB,		\
	//	GENI,		\
	//	GENH,		\
	//	GENO,		\
	//	GENA		\
	//);
	//(void)argv;
	return (0);
}

int main2(void)
{
	bra	*br;
	bra	*b;
	bra *nb;
	tid	i;
	tid	brains = 6;

	init_envt();
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
