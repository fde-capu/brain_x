/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   helper.c                                                                 */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/08 12:03:46 by ||||||                                   */
/*   Updated: 2019/11/14 17:50:06 by ||||||                                   */
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

neu	*neuron_by_nii(tid id, tid iv)
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
			if ((n->id == id) && (n->iv == iv))
				return (n);
			n = n->nx;
		}
		i++;
	}
	return (0);
}
