/* ************************************************************************** */
/*                                                                            */
/*                                                               ...... ...   */
/*   main.c                                                      .  ... . .   */
/*                                                               ..   .. ..   */
/*   By: fde-c <x@y.z>                                            .  ..  .    */
/*                                                               ..    . .    */
/*   Created: 2019/10/31 09:17:28 by fde-c                       .   .  .     */
/*   Updated: 2019/10/31 15:20:55 by fde-c                           .....0   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void malloc_globals(void)
{
	int	i;
	b_gene	*p;

	g_node_c = malloc(sizeof(*g_node_c));
	*g_node_c = 0;
	g_gene_c = malloc(sizeof(*g_gene_c));
	*g_gene_c = 0;

	g_gene = malloc(sizeof(*g_gene) * GENOME_TOTAL_GENES);
	p = g_gene;

	i = -1;
	while (++i < GENOME_TOTAL_GENES)
	{
		p->in = irnd(GENOME_TOTAL_NODES);
		p->out = irnd(GENOME_TOTAL_NODES);
		p->weight = rnd(1);
		p->enabled = brnd(.5);
		p->innov = ++*g_gene_c;
		p++;
	}

	return ;
}

void	init(void)
{
	malloc_globals();
	init_rnd();
	return ;
}

int	main(void)
{
	init();

	if (!brain_engine())
		return (0);
	else
		FAIL(BRAIN_ERROR);

}
