/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   helper.c                                                                 */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/08 12:03:46 by ||||||                                   */
/*   Updated: 2019/11/17 04:26:37 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

tid	count_neu(neu *l)
{
	tid	c;

	c = 0;
	while (l)
	{
		c++;
		l = l->nx;
	}
	return (c);
}

neu	*neuron_by_id(tid id)
{
	neu		*n;
	char	found;
	tid		i;

	i = 0;
	found = 0;
	while (!found)
	{
		n = i == 0 ? g_genome->bias : init_neu();
		n = i == 1 ? g_genome->inpu : n;
		n = i == 2 ? g_genome->hidd : n;
		n = i == 3 ? g_genome->outp : n;
		n = i == 4 ? g_genome->axon : n;
		while (n)
		{
			if (n->id == id)
				return (n);
			n = n->nx;
		}
		i++;
	}
	return (n);
}

int	find_id(tid id, net *n)
{
	while (n)
	{
		if (id == n->id) return (1);
		n = n->nx;
	}
	return (0);
}

void	feed(bra *b, tid id)
{
	net	*p;

	p = b->inpu;
	while ((p->id != id) && (p->nx))
		p = p->nx;
	p->bz = 1;
	return ;
}

void	think(bra *b)
{
	return ;
}
