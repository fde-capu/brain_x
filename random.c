/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   random.c                                                                 */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 00:42:00 by ||||||                                   */
/*   Updated: 2019/11/26 15:25:41 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_rnd()
{
	srand(time(0));
//	srand(11);//
}

double	rnd01(void)
{
	// double 0 ~ 1
	return ((double)rand() / \
	(double)((unsigned)RAND_MAX + 1));
}

double	rnd(double max)
{
	// double 0 ~ max
	return(rnd01() * max);
}

int	irnd(double max)
{
	// int 1 ~ max
	int	r;
	do {
		r = (1 + rnd01() * max);
	} while ((r < 1) || (r > max));
	return (r);
}

int	rndi(double min, double max)
{
	// min ~ max
	int	r;
	do {
		r = rnd(irnd((max + 2) - \
			(min - 2)) + (min - 1));
	} while ((r < min) || (r > max));
	return(r);
}

int     izrnd(double max)
{
	// int 0 ~ max
    return(rnd01() * (max + 1));
}

int		idxrnd(int arrsize)
{
	// int	0 ~ (arrsize-1)
	return(izrnd(arrsize - 1));
}

int	brnd(double chance)
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
	return ;
}

void	color(int c){ // whats this here?
	printf("\e[38;5;%dm", c);
	return ;
}
