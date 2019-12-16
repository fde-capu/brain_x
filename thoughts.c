/* ******************************************* */
/*                                             */
/*                     ||::::::||:::|||::||:|| */
/* thoughts.c          ::||:|::::|||::||||:|:| */
/*                     |:||:|:|::|:|:||||||::: */
/*     ||::|| <||::||>                         */
/*                                             */
/* C20191202164840 ||::||                      */
/* U20191216165837 :|::::                      */
/*                                             */
/* ******************************************* */

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
				p->iz += v;
				return ;
			}
			p = p->nx;
		}
	}
	return ;
}

void	feed_nd(net *nd)
{
	neu	*ne;

	if (!nd->iz)	return ;
	ne = neuron_by_id(nd->id);
	ne->re(nd);
	nd->iz = 0;
	return ;
}

void	think(bra *b)
{
	net	*n;
	int	i;

	i = -1;
	while (++i <= 3)
	{
		n = i_to_b_niche(i, b);
		while (n)
		{
			operate(n);
			n = n->nx;
		}
	}
	i = -1;
	while (++i <= 3)
	{
		n = i_to_b_niche(i, b);
		while (n)
		{
			feed_nd(n);
			n = n->nx;
		}
	}
	return ;
}

void	operate(net *n)
{
	neuron_by_id(n->id)->op(n);
	return ;
}

void	re_sum_clip(net *n)
{
	n->bz += n->iz;
	n->bz = n->bz > 1 ? 1 : n->bz;
	return ;
}

void	re_sigmoid(net *n)
{
	n->bz += sigmoid(n->iz);
	if (n->bz > 1) n->bz = 1;
	return ;
}

void	op_spark(net *n)
{
	net		*na;
	char	sparked;
	neu		*ne;
	
	ne = neuron_by_id(n->id);
	sparked = 0;
	if (n->bz >= ne->tr)
	{
		na = n->pt->axon;
		while (na)
		{
			if (axon_in(na->id) == n->id)
			{
				fire(n->pt, 1, na->id);
				sparked = 1;
			}
			na = na->nx;
		}
	}
	if (sparked)
	{
		n->bz = 0;
	}
	return ;
}

void	op_bias_rnd(net *n)
{
	op_spark(n);
	n->bz = rnd01();
	return ;
}

void	op_out(net *n)
{
	if (n->bz >= neuron_by_id(n->id)->tr)
	{
		n->pt->resp = prepend_cp(n->pt->resp, n);
		n->bz = 0;
	}
	return ;
}

void	fire(bra *b, fin f, tid id)
{
	neu	*na;
	net	*ne;

	na = g_axon_by_id(id);
	ne = neuron_in_brain(b, na->ou);
	if (!ne) return ;
	f *= na->tr;
	ne->iz += f;
	return ;
}
