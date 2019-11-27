/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   thoughts.c                                                               */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/18 12:10:45 by ||||||                                   */
/*   Updated: 2019/11/26 14:13:32 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	feed(bra *b, tid id, fin v)
{
	net	*p;
	int	i;

	i = -1;
	while (++i <= 4)
	{
		p = i_to_b_niche(i, b);
		while (p)
		{
			if (p->id == id)
			{
				feed_nd(p, v);
				return ;
			}
			p = p->nx;
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
	int	i;
	i = -1;
	while (++i <= 4)
	{
		n = i_to_b_niche(i, b);
		while (n)
		{
			ne = neuron_by_id(n->id);
			ne->op(n, ne);
			if (ne->tp & TP_B)
			{
				n->bz=rnd01();
			}
			n = n->nx;
		}
	}
	return ;
}

void	re_sum_clip(net *n, fin v)
{
	n->bz += v;
	n->bz = n->bz > 1 ? 1 : n->bz;
	return ;
}

void	re_sigmoid(net *n, fin v)
{
//	v = n->bz +	(pow(EULER, v) / ((pow(EULER, v) + 1)) - .5);
	n->bz = v;
	return ;
}

void	op_spark(net *n, neu *ne)
{ // is addressing corrent? does not seem. xxx
	neu	*na;
	net *no;

	if (n->bz >= ne->tr)
	{
		na = neuron_by_id(n->pt->axon->id);
		while (na)
		{
			if (na->in == n->id)
			{
				no = neuron_in_brain(n->pt, na->ou);
				no->bz += 1 * na->tr;
				n->bz = 0;
			}
			na = na->nx;
		}
	}
	return ;
}

void	op_bias(net *n, neu *ne)
{
	op_spark(n, ne);
	n->bz = 0;
	return ;
}

