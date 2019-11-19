/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   thoughts.c                                                               */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/18 12:10:45 by ||||||                                   */
/*   Updated: 2019/11/19 16:39:37 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	feed(bra *b, tid id, fin v)
{
	net	*p;
	neu	*ne;
	int	i;
	int	found;

	found = 0;
	i = -1;
	while (++i <= 4)
	{
		p =	i == 0 ? b->bias :
			i == 1 ? b->inpu :
			i == 2 ? b->hidd :
			i == 3 ? b->outp :
			i == 4 ? b->axon : 0;
		while ((p->id != id) && (p->nx) && (!found))
		{
			p = p->nx;
			if (p->id == id)
			{
				ne = neuron_by_id(p->id);
				ne->re(p, v);
				return ;
			}
		}
	}
	return ;
}

void	feed_nd(net *nd, fin v)
{
	neu	*ne;

	ne = neuron_by_id(nd->id);
	ne->re(nd, v);
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
		ne->op(n, ne);
		n = n->nx;
		i++;
	}
	return ;
}

void	re_sum_clip(net *n, fin v)
{
	n->bz += v;
	n->bz = n->bz > 1 ? 1 : n->bz;
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
				feed_nd(nd, 1 * ni->tr);
				n->bz = 0;
			}
		}
		na = na->nx;
	}
	return ;
}

