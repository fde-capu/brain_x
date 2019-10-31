/* ************************************************************************** */
/*                                                                            */
/*                                                               ...... ...   */
/*   debug.c                                                     .  ... . .   */
/*                                                               ..   .. ..   */
/*   By: fde-c <x@y.z>                                            .  ..  .    */
/*                                                               ..    . .    */
/*   Created: 2019/10/31 14:06:25 by fde-c                       .   .  .     */
/*   Updated: 2019/10/31 15:02:11 by fde-c                           .....0   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error_msg(char *str)
{
	printf("Error: %s.\n", str);
}


void            b_plot(brain b)
{
        int             i;
        int             j;
        unsigned int    out_gene;

        i = -1;
        while (++i < 1 + 3 + 5 + 3)
        {
                printf("[%02d:%02d:%10f]\n", b.node[i].id, b.node[i].type, \
                        b.node[i].val);
                j = -1;
                while (out_gene = node_out(b, b.node[i].id, ++j))
                {
                        printf("-%02d->[%02d]\n", out_gene, \
				node_on_gene_out(out_gene).id);
                }
//              j = b.node[i].outs();
        }
        i = -1;
        while (++i < 5)
        {
                printf("%d g in: %d\n",i, b.gene[i].in);
                printf("%d g out: %d\n",i, b.gene[i].out);
                printf("%d g weight: %f\n",i, b.gene[i].weight);
                printf("%d g enabled: %d\n",i, b.gene[i].enabled);
                printf("%d g innov: %d\n",i, b.gene[i].innov);
        }
        return ;
}


