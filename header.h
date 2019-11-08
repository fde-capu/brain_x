#ifndef HEADER_H
# define HEADER_H

# define PRECISION 100000
# define EULER 2.71828

# define STRESS 20

# define GENERAL_ERROR "Error"
# define GENERAL_ERROR_DETAIL \
	"Detail"
# define BRAIN_ERROR "brain"
# define FAIL_S(f) \
	{ error_msg(f); exit (1); }
# define FAIL_SSI(f,m,v) \
	{ error_msg(f); imsg(m,v); \
		exit (1); }

# define BIAS_TEST_N 1
# define INPU_TEST_N 3
# define HIDE_TEST_N 5
# define OUTP_TEST_N 3
# define AXON_TEST_N 7

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

# include "typedefs.h"

// main.c
int		main(void);

// brain.c
bra		init_brain(			\
			unsigned int b,	\
			unsigned int i, \
			unsigned int h, \
			unsigned int o, \
			unsigned int a	\
		);

// debug.c
void	imsg(char *str, int v);
void	error_msg(char *str);
void	msgs(char *str);
void	msgi(int inty);

// random.c
void	init_rnd(void);
float	rnd01(void);
float	rnd(float max);
int		irnd(float max);
int		izrnd(float max);
int		brnd(float chance);

#endif
