/* ******************************************* */
/*                                             */
/*                     |||:|||:|:||||::|||:::| */
/* main.c              |:||:|::||::|:||::::|:| */
/*                     :|:::|::|::::::||||||:| */
/*     |:|||: <|:|||:>                         */
/*                                             */
/* C20191211154835 |:|||:                      */
/* U20191226171504 ||||||                      */
/*                                             */
/* ******************************************* */

#include "header.h"

int main(int argc, char **argv)
{
	bra	*ind;

	init_envt();
	while (--argc)
		option(argv[argc]);
	// v0.5 case g_continue, init from file
	init_genome();
	print_genome();
	ind = init_brain(DEFB,DEFI,DEFH,DEFO,DEFA);
	while (1)
	{
		if (CLEAR_SCREEN) CLS
		print_genome();
		print_brain(ind);
		think(ind);
		tic(TIC_SEC);
	}
	return (0);
}

int		init_envt(void)
{
	g_continue = 0;
	g_gnm_file = filename_str(DEF_GENOME);
	color(COLOR_FORE);
	g_module = init_mod();
	load_modules();
	print_modules();
	init_rnd();
	return (0);
}

void	option(char	*op)
{
	char	*p;

	p = op;
	while ((*p) && (*p != '='))
		p++;
	p++;
	if (strm(op, "genome"))
		{ g_gnm_file = p; RE }
	if (strm(op, "continue"))
		{ g_continue = 1; RE }
	FAIL_S("Invalid option");
	return ;
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
	init_genome();
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
