/* ************************************************************************** */
/*                                                                            */
/*                                                               ...... ...   */
/*   brain_helpers.c                                             .  ... . .   */
/*                                                               ..   .. ..   */
/*   By: fde-c <x@y.z>                                            .  ..  .    */
/*                                                               ..    . .    */
/*   Created: 2019/10/31 14:08:15 by fde-c                       .   .  .     */
/*   Updated: 2019/10/31 15:21:57 by fde-c                           .....0   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

b_gene		gene_by_id(unsigned int g_id)
{
	return (g_gene[g_id]);
}

b_node		node_on_gene_out(unsigned int g_id)
{
	return (node_by_id(gene_by_id(g_id).out));
}

b_node          node_by_id(brain b, unsigned int n_id)
{
        int     i;

        i = -1;
        while (++i < 12)
        {
                if (b.node[i].id == n_id)
                        return (b.node[i]);
        }

        b_node  t;
        t.id = 0;
        return (t);
}

unsigned int    node_out(brain b, unsigned int n_id, int j)
{
        int     i;
        int     x;

        x = -1;
        i = -1;
        while (++i < 5)
        {
                if (b.gene[i].in == nodebyId(b, n_id).id)
                {
                        x++;
                        if (x == j)
                                return(b.gene[i].innov);
                }

        }
        return (0);
}
