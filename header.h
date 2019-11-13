#ifndef HEADER_H
# define HEADER_H

# define TYPE_OF_ID unsigned long
# define TYPE_OF_TYPE char
# define TYPE_OF_FINE double
# define TYPE_OF_CHARGE double
# define TYPE_OF_INNOV unsigned long

# define PRECISION 100000
# define EULER 2.71828

# define STRESS 20
# define STRESS_IN int stress = STRESS;
# define STRESS_OUT if(!--stress)\
	{FAIL(STRESS_ERROR);}

# define STRESS_ERROR "Stress"
# define GENERAL_ERROR "Error"
# define GENERAL_ERROR_DETAIL \
	"Detail"
# define BRAIN_ERROR "brain"
# define FAIL(f) FAIL_S(f)
# define FAIL_S(f) \
	{ error_msg(f); exit (1); }
# define FAIL_SSI(f,m,v) \
	{ error_msg(f); imsg(m,v); \
		exit (1); }
# define LOGI(c,n) logi(c,n);

# define TP_B 1
# define TP_I 2
# define TP_H 4
# define TP_O 8
# define TP_A 16

# define TPN_B 'B'
# define TPN_I 'I'
# define TPN_H 'H'
# define TPN_O 'O'
# define TPN_A 'A'

# define DEFB 1
# define DEFI 3
# define DEFH 5
# define DEFO 3
# define DEFA 7
# define GENB 1
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
void		*init_genome(void);
neu			*gen_neuron(t_type t, int n);
neuidinn	rnd_from_genome(t_type t);

// brain.c
bra		*init_brain(        \
			unsigned int b, \
			unsigned int i, \
			unsigned int h, \
			unsigned int o, \
			unsigned int a  \
		);
net		*rnd_neuron (t_type t, int n);

// helper.c
t_id	net_neu_concat(neu *a, net *b);
neuidinn	get_neu_from_net \
	(int n, net *l);

// debug.c
void	imsg(char *str, int v);
void	error_msg(char *str);
void	msgs(char *str);
void	msgi(int inty);
void	print_net(net *n);
void	print_genome(void);
char	*get_typename(t_type t);
void	print_neu_list(neu *n);
void	print_neuron(neu *neuron);
void	logi(char *c, int n);

// random.c
void	init_rnd(void);
float	rnd01(void);
float	rnd(float max);
int		irnd(float max);
int		izrnd(float max);
int		brnd(float chance);

#endif
