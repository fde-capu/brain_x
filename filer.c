/* ******************************************* */
/*                                             */
/*                     ||::|::|:|::||::|||:::| */
/* filer.c             :::||:|::::|:||::::::|| */
/*                     ||:|:|:|||:||:||||||::| */
/*     :|:||: <:|:||:>                         */
/*                                             */
/* C20191222195718 :|:||:                      */
/* U20191226175102 ::::||                      */
/*                                             */
/* ******************************************* */

#include "header.h"

void	save_genome(char *fn, void *dt)
{
	int fd;
	neu	*n;
	int	i;

	printf("genome file: %s\n", fn);
	fd = open(fn, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd <= 0) FAIL("save_genome error");
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
	return ;
}
