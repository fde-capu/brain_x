/* ************************************************************************** */
/*                                                                            */
/*                                                               ...... ...   */
/*   typedefs.h                                                  .  ... . .   */
/*                                                               ..   .. ..   */
/*   By: fde-c <x@y.z>                                            .  ..  .    */
/*                                                               ..    . .    */
/*   Created: 2019/10/31 08:54:06 by fde-c                       .   .  .     */
/*   Updated: 2019/10/31 14:32:30 by fde-c                           .....0   */
/*                                                                            */
/* ************************************************************************** */
struct	b_gene
{
	unsigned short int	in;
	unsigned short int	out;
	float			weight;
	signed char		enabled;
	unsigned int		innov;
};
typedef struct b_gene b_gene;

struct	b_node
{
	unsigned int	id;
	short int	type; // -2 = bias, -1 = input, 0 = hidden, 1 = output
	float		val;
};
typedef	struct b_node b_node;

struct	brain
{
	int	size[5];
	b_node	node[1 + 3 + 5 + 3];
	b_gene	gene[5];
};
typedef struct brain brain;


