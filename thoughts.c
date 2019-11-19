/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   thoughts.c                                                               */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/18 12:10:45 by ||||||                                   */
/*   Updated: 2019/11/19 12:04:09 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	feed(bra *b, tid id, fin v)
{
	net	*p;

	p = b->inpu;
	while ((p->id != id) && (p->nx))
		p = p->nx;
	p->bz += v;
	return ;
}

void	think(bra *b)
{
	net	*n;
	neu	*ne;
	tid	i;

	i = 0;
	n = b->inpu;
	while (n)
	{
		ne = neuron_by_id(n->id);
		ne->re(n, ne);
		ne->op(n, ne);
		n = n->nx;
		i++;
	}
	return ;
}

void	re_nothi(net *n, neu *ne)
{
	return ;
}

void	op_spark(net *n, neu *ne)
{
	printf("OP_SPARK\n");
	return ;
}

