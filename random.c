/* ************************************************************************** */
/*                                                                            */
/*                                                               ...... ...   */
/*   random.c                                                    .  ... . .   */
/*                                                               ..   .. ..   */
/*   By: fde-c <x@y.z>                                            .  ..  .    */
/*                                                               ..    . .    */
/*   Created: 2019/10/31 14:45:20 by fde-c                       .   .  .     */
/*   Updated: 2019/10/31 14:47:45 by fde-c                           .....0   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_rnd()
{
	srand(time(0));
}

double  rnd(double max)
{
        return ((rand() % (int)(max * PRECISION)) / PRECISION);
}

int     irnd(double max)
{
        return(rand() % (int)max);
}

int	brnd(double chance)
{
	if (rnd(1) >= chance)
		return (1);
	return (0);
}
