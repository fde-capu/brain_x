#ifndef HEADER_H
# define HEADER_H

# define TYPE_OF_ID		unsigned long
# define TYPE_OF_TYPE	char
# define TYPE_OF_FINE	double
# define TYPE_OF_CHARGE	double
# define EULER			(double) 2.718281228459045//23536...

# define STRESS_ERROR			"Stress"
# define GENERAL_ERROR			"Error"
# define GENERAL_ERROR_DETAIL	"Detail"
# define BRAIN_ERROR_MSG		"brain creation, (not enough static genome?) stress "
# define NEU_ID_NOT_FOUND		"(internal) neuron not found in genome (version problem?) "

# define TP_B	1
# define TP_I	2
# define TP_H	4
# define TP_O	8
# define TP_A	16

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "defs.h"
# include "helperdefs.h"
# include "typedefs.h"

// main.c
int		init_envt(void);
int		main(int argc, char **argv);
int		main2(void);

// genome.c
void	init_genome(tid b, tid i, tid h, tid o, tid a);
neu		*gen_neuron(typ t, int n);
neu		*init_neu(void);
neu		*rnd_from_genome(typ t);

// brain.c
bra		*init_brain(\
		tid b, tid i, \
		tid h, tid o, tid a);
net		*rnd_neu (typ t, int q, bra *b);
net		*init_net(void);

// thoughts.c
void	feed(bra *b, tid id, fin v);
void	feed_nd(net *nd);
void	think(bra *b);
void	operate(net *n);
void	op_spark(net *n);
void	op_bias_rnd(net *n);
void	op_out(net *n);
void	re_sum_clip(net *n);
void	re_sigmoid(net *n);
void	fire(bra *b, fin f, tid id);

// helper.c
tid		count_neu(neu *l);
neu		*neuron_by_id(tid id);
neu		*g_axon_by_id(tid id);
tid		axon_ou(tid id);
tid		axon_in(tid id);
net		*neuron_in_brain(bra *b, tid nid);
int		find_id(tid id, net *n);
net		*i_to_b_niche(int i, bra *b);
neu		*i_to_g_niche(int i);
double	sigmoid(double v);
net		*prepend_cp(net *ne, net *n);

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
void	logx(char *c, int n);
void	logp(char *c, void *n);
void	print_net_herd(net *n);
void	print_resp(net *n);
char	*gauge_bar(fin v);
char	*format_p(char *str);
int		is_dumb(net *na);
int		is_conn(net *na, net *ni);
int		is_conn_netneu(net *na, neu *ni);

// random.c
void	init_rnd(void);
double	rnd01(void);
double	rnd(double max);
int		irnd(double max);
int		rndi(double min, double max);
int		izrnd(double max);
int		brnd(double chance);
void	tic(fin ms);
void	color(int c);

#endif
