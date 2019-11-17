/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   random.c                                                                 */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 00:42:00 by ||||||                                   */
/*   Updated: 2019/11/17 04:22:36 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_rnd()
{
	srand(time(0));
}

float	rnd01(void)
{
	// float 0 ~ 1
	return ((float)rand() / \
	(float)((unsigned)RAND_MAX + 1));
}

float	rnd(float max)
{
	// float 0 ~ max
	return(rnd01() * max);
}

int	irnd(float max)
{
	// int 1 ~ max
	int	r;
	do {
		r = (1 + rnd01() * max);
	} while ((r < 1) || (r > max));
	return (r);
}

int     izrnd(float max)
{
	// int 0 ~ max
    return(rnd01() * (max + 1));
}

int		idxrnd(int arrsize)
{
	// int	0 ~ (arrsize-1)
	return(izrnd(arrsize - 1));
}

int	brnd(float chance)
{
	// int bool 0 or 1
	if (rnd(1) >= chance)
		return (1);
	return (0);
}

void	tic(fin ms)
{
	fflush(stdout);
	usleep(ms * 1000000);
}
