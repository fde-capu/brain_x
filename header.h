#ifndef HEADER_H
# define HEADER_H

# define PRECISION 100000
# define EULER 2.71828

# define STRESS 20

# define GENERAL_ERROR "Error"
# define GENERAL_ERROR_DETAIL "Detail"
# define BRAIN_ERROR "brain"
# define FAIL_S(f) { error_msg(f); exit (1); }
# define FAIL_SSI(f,m,v) { error_msg(f); imsg(m,v); exit (1); }

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

# include "typedefs.h"

// main.c
int		main(void);

// brain.c

// brain_ops.c

// brain_helpers.c

// think.c

// debug.c
void	imsg(char *str, int v);
void	error_msg(char *str);

// random.c
void	init_rnd(void);
float	rnd01(void);
float	rnd(float max);
int		irnd(float max);
int		izrnd(float max);
int		brnd(float chance);

#endif
