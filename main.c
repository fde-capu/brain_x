/* ******************************************* */
/*                                             */
/*                     |||:|||:|:||||::|||:::| */
/* main.c              |:||:|::||::|:||::::|:| */
/*                     :|:::|::|::::::||||||:| */
/*     |:|||: <|:|||:>                         */
/*                                             */
/* C20191211154835 |:|||:                      */
/* U20200115014626 ::|::|                      */
/*                                             */
/* ******************************************* */

#include "header.h"

int main(int argc, char **argv)
{
	bra	*ind;
	bra *bloop;
	int bn = 2;

	init_envt();
	while (--argc)
		option(argv[argc]);
	// v0.5 case g_continue, init from file
	init_genome();
	VERB print_genome();
	ind = init_brain(g_db,g_di,g_dh,g_do,g_da);
	bloop = ind;
	while (--bn)
	{
		bloop->nx = init_brain(g_db,g_di,g_dh,g_do,g_da);
		bloop = bloop->nx;
	}
	while (VERBOSE && 1)
	{
		bloop = ind;
		while (bloop)
		{
			think(bloop);
			bloop = bloop->nx;
		}
		bloop = ind;
		if (CLEAR_SCREEN) CLS
		VERB2 print_genome();
		while (bloop)
		{
			print_brain(bloop);
			bloop = bloop->nx;
		}
		tic(TIC_SEC);
	}
	return (0);
}

int		init_envt(void)
{
	g_db = DEFB;
	g_di = DEFI;
	g_dh = DEFH;
	g_do = DEFO;
	g_da = DEFA;
	// v1.0 get g_dbihoa from genome_config_default.x or genome_config.x
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
