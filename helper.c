/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   helper.c                                                                 */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/08 12:03:46 by ||||||                                   */
/*   Updated: 2019/11/14 00:15:11 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

net		*net_neu_concat(neu *a, net *b)
{
	net	*tp;
	net	nn[count_neu(a)];
	net	*p;

	if (!b->id)
	{
		b->id = a->id;
		b->innov = a->innov;
		a = a->next;
	}
	tp = malloc(sizeof(net) * \
		(count_neu(a) + 3));
	p = tp;
	printf("b:%2x (%2x)\ttp:%2x\n", b, b->next, tp);
	while (a)
	{
		p++;
		p->next = p != tp + 1 ? (p - 1) : b;
		p->id = a->id;
		p->innov = a->innov;
		printf("p:%2x\tp->next:%2x\t%d\n",\
			p, p->next,p->id);
		a = a->next;
	}
	print_net(p);
//	return (b);
	return (p);
}

nii		get_neu_from_net \
	(int n, net *l)
{
	nii	out;

	return (out);
}

t_id	count_neu(neu *a)
{
	t_id	c;

	c = 0;
	while (a)
	{
		c++;
		a = a->next;
	}
	return (c);
}

net		*init_net(net *p)
{
	p = malloc(sizeof(net));
	p->id = 0;
	p->innov = 0;
	p->next = 0;
	p->parent = 0;
	p->charge = 0;
	return (p);
}
