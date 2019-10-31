#ifndef HEADER_H
# define HEADER_H

# define PRECISION 10000.0
# define EULER 2.71828

# define GENOME_TOTAL_NODES 12
# define GENOME_TOTAL_GENES 5

# define BRAIN_ERROR "brain"
# define FAIL(f) { error_msg(f); return (1); }

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

# include "typedefs.h"

long int	*g_node_c;
long int	*g_gene_c;
b_gene		*g_gene;
b_node		*g_node;

// main.c
void	malloc_globals(void);
void	init(void);
int	main(void);

// brain.c
brain	gen_brain(int b_size[5]);
int	brain_engine(void);

// brain_helpres.c
b_gene	gene_by_id(unsigned int g_id);
b_node	node_on_gene_out(unsigned int g_id);
b_node	node_by_id(brain b, unsigned int n_id);
unsigned int	node_out(brain b, unsigned int n_id, int j);

// think.c
float	b_fractal(brain b, int in[3], b_node n);
int	b_think(brain b, int in[3]);

// debug.c
void	error_msg(char *str);
void	b_plot(brain b);

// random.c
void	init_rnd(void);
double	rnd(double max);
int	irnd(double max);
int	brnd(double chance);

#endif
