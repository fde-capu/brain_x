/* ******************************************* */
/*                                             */
/*                     |||:|||:|:||||::|||:::| */
/* main.c              |:||:|::||::|:||::::|:| */
/*                     :|:::|::|::::::||||||:| */
/*     |:|||: <|:|||:>                         */
/*                                             */
/* C20191211154835 |:|||:                      */
/* U20191218083816 :||::|                      */
/*                                             */
/* ******************************************* */

#include "header.h"
# define FNL FILE_NAME_LIMIT

int		init_envt(void)
{
	char	def_gnm[] = DEF_GENOME;
	char	*p;
	char	*r;

	g_gnm_file = malloc(sizeof(char) * FNL);
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
	if (strm(op, "genome")) g_gnm_file = p;
	return ;
}

int main(int argc, char **argv)
{
	init_envt();
	while (argc > 1)
	{
		option(argv[argc - 1]);
		argc--;
	}
	printf("%s\n", g_gnm_file);
	init_genome(						\
		GENB,GENI,GENH,GENO,GENA		\
	);
	(void)argv;
	return (0);
}

int		main2(void) // oldie currently unused
{
	bra	*br;
	bra	*b;
	bra *nb;
	tid	i;
	tid	brains = 6;

	init_envt();
	g_id = 0; // from file
	g_iv = 0; //
	init_genome(						\
		GENB,GENI,GENH,GENO,GENA		\
	);
	print_genome();
	nb = 0;
	i = 0;
	while(++i <= brains)
	{
		br = init_brain(				\
			DEFB,DEFI,DEFH,DEFO,DEFA	\
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
