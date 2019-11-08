/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   random.c                                                                 */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 00:42:00 by ||||||                                   */
/*   Updated: 2019/11/07 00:48:40 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_rnd()
{
	srand(time(0));
}

float	rnd01(void)
{
	return ((float)rand() / \
	(float)((unsigned)RAND_MAX + 1));
}

float	rnd(float max)
{
        return(rnd01() * max);
}

int	irnd(float max)
{
	return (1 + rnd01() * max);
}

int     izrnd(float max)
{
        return(rnd01() * (max + 1));
}

int	brnd(float chance)
{
	if (rnd(1) >= chance)
		return (1);
	return (0);
}
