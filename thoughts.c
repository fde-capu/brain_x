/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   thoughts.c                                                               */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/18 12:10:45 by ||||||                                   */
/*   Updated: 2019/11/19 11:16:28 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	feed(bra *b, tid id, fin v)
{
	net	*p;

	p = b->inpu;
	while ((p->id != id) && (p->nx))
		p = p->nx;
	p->bz += v;///////////
	return ;
}

void	think(bra *b)
{
	net	*p;
	neu	*n;
	tid	i;

	i = 0;
	p = b->inpu;
	while (p)
	{
		n = neuron_by_id(p->id);
		n->re(p);
		n->op(p);
		p = p->nx;
		i++;
	}
	return ;
}

void	re_nothi(net *n)
{
	return ;
}

void	op_spark(net *n)
{
	printf("OP_SPARK\n");
	return ;
}

