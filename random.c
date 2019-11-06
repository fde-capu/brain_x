/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   random.c                                                                 */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: fde-c <x@y.z>                              ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/06 00:16:01 by fde-c                                    */
/*   Updated: 2019/11/06 00:16:05 by fde-c                                    */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_rnd()
{
	srand(time(0));
}

float	rnd01(void)
{
	return ((float)rand() / (float)((unsigned)RAND_MAX + 1));
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
