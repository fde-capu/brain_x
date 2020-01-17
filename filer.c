/* ******************************************* */
/*                                             */
/*                     ||::|::|:|::||::|||:::| */
/* filer.c             :::||:|::::|:||::::::|| */
/*                     ||:|:|:|||:||:||||||::| */
/*     :|:||: <:|:||:>                         */
/*                                             */
/* C20191222195718 :|:||:                      */
/* U20200116234934 ::|:||                      */
/*                                             */
/* ******************************************* */

#include "header.h"

void	save_genome(char *fn, void *dt)
{
	int fd;
	neu	*n;
	int	i;

	fd = open(fn, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd <= 0) FAIL("Save genome error.");
	i = -1;
	while (++i <= 4)
	{
	 n = i_to_g_niche(i);
	 while (n)
	 {
	  write(fd, &(n->id), sizeof(((neu*)0)->id));
	  write(fd, &(n->iv), sizeof(((neu*)0)->iv));
	  write(fd, &(n->tp), sizeof(((neu*)0)->tp));
	  write(fd, &(n->in), sizeof(((neu*)0)->in));
	  write(fd, &(n->ou), sizeof(((neu*)0)->ou));
	  write(fd, &(n->tr), sizeof(((neu*)0)->tr));
	  write(fd, &(n->op), sizeof(((neu*)0)->op));
	  write(fd, &(n->re), sizeof(((neu*)0)->re));
	  n = n->nx;
	 }
	}
	write(fd, "\0", 1);
	close(fd);
	VERB printf("Saved genome file: %s\n", fn);
	return ;
}

void	load_genome(char *fn, void *dt)
{
	int		fd;
	neu		*n;
	tid		b;

	fd = open(fn, O_RDONLY);
	if (fd <= 0) FAIL("load_genome error");
	while(\
	 read(fd, &b, sizeof(((neu*)0)->id))\
	)
	{
	 n = init_neu();
	 n->id = b;
	 read(fd, &(n->iv), sizeof(((neu*)0)->iv));
	 read(fd, &(n->tp), sizeof(((neu*)0)->tp));
	 read(fd, &(n->in), sizeof(((neu*)0)->in));
	 read(fd, &(n->ou), sizeof(((neu*)0)->ou));
	 read(fd, &(n->tr), sizeof(((neu*)0)->tr));
	 read(fd, &(n->op), sizeof(((neu*)0)->op));
	 read(fd, &(n->re), sizeof(((neu*)0)->re));
	 if (n->tp & TP_B)
	 {
		n->nx = g_gnm->bias;
		g_gnm->bias = n;
	 }
	 if (n->tp & TP_I)
	 {
		n->nx = g_gnm->inpu;
		g_gnm->inpu = n;
	 }
	 if (n->tp & TP_H)
	 {
		n->nx = g_gnm->hidd;
		g_gnm->hidd = n;
	 }
	 if (n->tp & TP_O)
	 {
		n->nx = g_gnm->outp;
		g_gnm->outp = n;
	 }
	 if (n->tp & TP_A)
	 {
		n->nx = g_gnm->axon;
		g_gnm->axon = n;
	 }
	 if (n->id) VERB2 print_neuron(n);
	}
	printf("Above was read from file.\n");
	return ;
}
