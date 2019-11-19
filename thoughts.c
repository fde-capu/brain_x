/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   thoughts.c                                                               */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/18 12:10:45 by ||||||                                   */
/*   Updated: 2019/11/19 14:36:46 by ||||||                                   */
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
	p->bz = p->bz > 1 ? 1 : p->bz;
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
	net	*na;
	neu *ni;
	net *nd;

	na = n->pt->axon;
	while (na)
	{
		ni = neuron_by_id(na->id);
		if (ni->in == n->id)
		{
			nd = neuron_in_brain(n->pt, ni->ou);
			if ((nd) && (n->bz >= ne->tr))
			{
				nd->bz = 1 * ni->tr;
				n->bz = 0;
			}
		}
		na = na->nx;
	}
	return ;
}

