#ifndef HEADER_H
# define HEADER_H

# define TYPE_OF_ID unsigned long
# define TYPE_OF_TYPE char
# define TYPE_OF_FINE double
# define TYPE_OF_CHARGE double

# define PRECISION 100000
# define EULER 2.71828

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

# define STRESS 5 
# define STRESS_BRAIN 256
# define STRESSIN int stress = STRESS;
# define STRESS_BRAIN_CREATION int stress = STRESS_BRAIN;
# define STRESSOUT if(!--stress)\
	{FAIL(STRESS_ERROR);}
# define STRESSMSG(s) if(!--stress)\
	{FAIL(s);}

# define STRESS_ERROR "Stress"
# define GENERAL_ERROR "Error"
# define GENERAL_ERROR_DETAIL \
	"Detail"
# define BRAIN_ERROR_MSG "brain creation, stress "
# define BRAIN_ERROR BRAIN_ERROR_MSG STR(STRESS_BRAIN)
# define FAIL(f) FAIL_S(f)
# define FAIL_S(f) \
	{ error_msg(f); exit (1); }
# define FAIL_SSI(f,m,v) \
	{ error_msg(f); imsg(m,v); \
		exit (1); }
# define LOGI(c,n) logi(c,n);
# define NL printf("\n");

# define GNM_TITLE "\n::: GENOME :::\n"
# define GNM_A_STR "%s:[%3d*%3d] [%3d]--%0.5lf-->[%-3d] {%2x} %2x>%2x\n"
# define GNM_A_VAR get_typename(neuron->tp), neuron->id, neuron->iv,\
			neuron->in,neuron->tr,neuron->ou,\
			neuron->op, neuron, neuron->nx
# define GNM_N_STR "%s:[%3d*%3d] [ %0.16lf ] {%2x} %2x>%2x\n"
# define GNM_N_VAR get_typename(neuron->tp), neuron->id, neuron->iv, 	\
			neuron->tr,neuron->op, neuron,neuron->nx
# define BRA_TITLE "\n::: BRAIN ::: ~%2x~ :::\n"
# define NET_A_STR " >[%3d*%3d] --%0.7lf-->[%-3d] {%2x} %2x>%2x\n"
# define NET_A_VAR n->id,n->iv,ni->tr,ni->ou,ni->op,n,n->nx
# define NET_N_STR "%s:[%3d*%3d] ::%0.7lf|%0.5lf {%2x} %2x>%2x\n"
# define NET_N_VAR get_typename(ni->tp),n->id,n->iv,n->bz,ni->tr,\
				ni->op,n, n->nx
# define NET_H_STR " |[%3d*%3d] [%3d]-%0.4lf->[%-3d] {%2x}|%2x>%2x\n"
# define NET_H_VAR 	n->id,n->iv,ni->in,ni->tr,ni->ou,ni->op,n,n->nx


# define GNM_NETS_N 5

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
void	*init_genome(tid b, tid i, tid h, tid o, tid a);
neu		*gen_neuron(typ t, int n);
neu		*init_neu(void);
neu		rnd_from_genome(typ t);

// brain.c
bra		*init_brain(\
			tid b, tid i, \
			tid h, tid o, tid a);
net		*rnd_neuron (typ t, int q, bra *b);
net	*init_net(void);

// thoughts.c
void	feed(bra *b, tid id);
void	think(bra *b);

// helper.c
tid	count_neu(neu *l);
neu	*neuron_by_id(tid id);
int	find_id(tid id, net *n);

// debug.c
void	imsg(char *str, int v);
void	error_msg(char *str);
void	msgs(char *str);
void	msgi(int inty);
void	print_genome(void);
void	print_brain(bra *b);
char	*get_typename(typ t);
void	print_neu_list(neu *n);
void	print_net_list(net *n);
void	print_neuron(neu *neuron);
void	logi(char *c, int n);
void	print_net_herd(net *n);

// random.c
void	init_rnd(void);
float	rnd01(void);
float	rnd(float max);
int		irnd(float max);
int		izrnd(float max);
int		brnd(float chance);
void	tic(fin ms);

#endif
