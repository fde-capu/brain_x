/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   helper.c                                                                 */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/08 12:03:46 by ||||||                                   */
/*   Updated: 2019/11/26 01:43:37 by ||||||                                   */
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
	while ((!found) && (i <= 4))
	{
		n = i_to_g_niche(i);
		while (n)
		{
			if (n->id == id)
			{
				return (n);
			}
			n = n->nx;
		}
		i++;
	}
	FAIL_SSI(NEU_ID_NOT_FOUND, "id", id)
}

neu	*g_axon_by_id(tid id)
{
	neu	*n;

	n = (neu *)g_gnm->axon;
	while (n)
	{
		if (n->id == id)
			return (n);
		n = n->nx;
	}
	return (0);
}

tid	axon_ou(tid id)
{
	return (g_axon_by_id(id)->ou);
}

tid	axon_in(tid id)
{
	return (g_axon_by_id(id)->in);
}

int	find_id(tid id, net *n)
{
	while (n)
	{
		if (n->id == id)
			return (1);
		n = n->nx;
	}
	return (0);
}

net	*neuron_in_brain(bra *b, tid id)
{
	net	*n;
	int	i;

	i = -1;
	while (++i <= 4)
	{
		n = i_to_b_niche(i, b);
		while (n)
		{
			if (n->id == id)
				return (n);
			n = n->nx;
		}
	}
	return (0);
}

net	*i_to_b_niche(int i, bra *b)
{
	net	*n;
	n =	i == 0 ? b->bias :
		i == 1 ? b->inpu :
		i == 2 ? b->hidd :
		i == 3 ? b->outp :
		i == 4 ? b->axon : 0;
	return (n);
}

neu	*i_to_g_niche(int i)
{
	neu	*n;
	n =	i == 0 ? g_gnm->bias :
		i == 1 ? g_gnm->inpu :
		i == 2 ? g_gnm->hidd :
		i == 3 ? g_gnm->outp :
		i == 4 ? g_gnm->axon : 0;
	return (n);
}

double	sigmoid(double v)
{
	return ((pow(EULER, v) / ((pow(EULER, v) + 1))) - .5);
}
