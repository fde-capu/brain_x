#ifndef HEADER_H
# define HEADER_H

# define TYPE_OF_ID unsigned long
# define TYPE_OF_TYPE signed char
# define TYPE_OF_FINE long
# define TYPE_OF_CHARGE double
# define TYPE_OF_INNOV unsigned long

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

# define TP_B -2
# define TP_I -1
# define TP_H  0
# define TP_O  1
# define TP_A  2

# define DEFB 1
# define DEFI 3
# define DEFH 5
# define DEFO 3
# define DEFA 7
# define GENB 2
# define GENI 3
# define GENH 5
# define GENO 3
# define GENA 7

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

# include "typedefs.h"

// main.c
int		main(void);

// genome.c
gnm		*init_genome(void);
neu		*gen_neuron(t_type t, neu *next);
void	rnd_from_genome \
	(t_type t, t_id_innov id_innov);

// brain.c
bra		*init_brain(        \
			unsigned int b, \
			unsigned int i, \
			unsigned int h, \
			unsigned int o, \
			unsigned int a  \
		);
net		*create_neuron (t_type t, int n);

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
