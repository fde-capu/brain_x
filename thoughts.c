/* ******************************************* */
/*                                             */
/*                     ||::::::||:::|||::||:|| */
/* thoughts.c          ::||:|::::|||::||||:|:| */
/*                     |:||:|:|::|:|:||||||::: */
/*     ||::|| <||::||>                         */
/*                                             */
/* C20191202164840 ||::||                      */
/* U20200113230632 |:||:|                      */
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
	neu	*ne;

	ne = neuron_by_id(n->id);
	if(exec(ne->op, n))
	{
		if (ne->tp & TP_O)
			n->pt->resp = prepend_cp(n->pt->resp, n);
	}
	return ;
}

void	feed_nd(net *nd)
{
	neu	*ne;

	if (!nd->iz)	return ;
	ne = neuron_by_id(nd->id);
	exec(\
		ne->re\
	, nd);
	nd->iz = 0;
	return ;
}

int		re_sum_clip(net *n)
{
	n->bz += n->iz;
	n->bz = n->bz > 1 ? 1 : n->bz;
	return (1);
}

int		re_acc_sigmoid(net *n)
{
	n->bz += sigmoid(n->iz);
	if (n->bz > 1) n->bz = 1;
	return (1);
}

int		op_spark(net *n)
{
	net		*na;
	char	sparked;
	neu		*ne;
	
	ne = neuron_by_id(n->id);
	if (n->bz >= ne->tr)
	{
		na = n->pt->axon;
		while (na)
		{
			if (axon_in(na->id) == n->id)
				fire(n->pt, 1, na->id);
			na = na->nx;
		}
		n->bz = 0;
		return (1);
	}
	return (0);
}

int		op_random(net *n)
{
	op_spark(n);
	n->bz = rnd01();
	return (1);
}

void	re_inputonly(net *n) //to do
{
	(void)n;
	return ;
}

void	op_multiply(net *n) //to do
{
	(void)n;
	return ;
}

void	load_modules(void)
{
	append_module("re_inputonly", re_inputonly);
	append_module("op_multiply", op_multiply);
	append_module("op_random", op_random);
	append_module("op_spark", op_spark);
	append_module("re_acc_sigmoid", re_acc_sigmoid);
	append_module("re_sum_clip", re_sum_clip);
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
