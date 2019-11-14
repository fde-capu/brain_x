/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   debug.c                                                                  */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 00:42:59 by ||||||                                   */
/*   Updated: 2019/11/14 16:01:31 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	imsg(char *str, int v)
{
	printf(GENERAL_ERROR_DETAIL\
		": %s %d.\n", str, v);
}

void	error_msg(char *str)
{
	printf(GENERAL_ERROR\
		": %s.\n", str);
}

void	msgs(char *str)
{
	printf("%s\n", str);
}

void	msgi(int inty)
{
	printf("%d\n", inty);
}

void	logi(char *c, int n)
{
	printf("%s: %d\n",c,n);
}

void	print_genome(void)
{
	printf("\n::: GENOME :::\n");
	neu	*n;
	n = g_genome->bias;
	print_neu_list(n);
	n = g_genome->inpu;
	print_neu_list(n);
	n = g_genome->hidd;
	print_neu_list(n);
	n = g_genome->outp;
	print_neu_list(n);
	n = g_genome->axon;
	print_neu_list(n);
}

void	print_neu_list(neu *n)
{
	while (n)
	{
		print_neuron(n);
		n = n->nx;
	}
}


void	print_brain(bra *b)
{
	printf("\n::: BRAIN ~%2x~ :::\n", b);
	net	*n;
	n = b->bias;
	print_net_list(n);
	n = b->inpu;
	print_net_list(n);
	n = b->hidd;
	print_net_list(n);
	n = b->outp;
	print_net_list(n);
	n = b->axon;
	print_net_list(n);
}

void	print_net_list(net *n)
{
//	while (n)
//	{
//		print_neuron(n->pos);
//		n = n->nx;
//	}
}


char	*get_typename(typ t)
{
	char	out[6];
	char	*p;
	char	*o;

	p = out;
	o = out;
	if (t & TP_B){ *p = TPN_B; p++; }
	if (t & TP_I){ *p = TPN_I; p++; }
	if (t & TP_H){ *p = TPN_H; p++; }
	if (t & TP_O){ *p = TPN_O; p++; }
	if (t & TP_A){ *p = TPN_A; p++; }
	*p = 0;
	return (o);
}

void	print_neuron(neu *neuron)
{
	if (neuron->type & TP_A)
	{
		printf("%s:[%3d*%3d] " 			\
			"[%3d]--%0.5lf-->[%-3d] " 	\
			"{%2x} %2x>%2x\n", 			\
			get_typename(neuron->type), \
			neuron->id, neuron->iv, 	\
			neuron->in, 				\
			neuron->tr,		 			\
			neuron->out, 				\
			neuron->op, neuron, 		\
			neuron->nx);
	}
	else
	{
		printf("%s:[%3d*%3d] " 			\
			"[ %0.16lf ] " 				\
			"{%2x} %2x>%2x\n", 			\
			get_typename(neuron->type), \
			neuron->id, neuron->iv, 	\
			neuron->tr,		 			\
			neuron->op, neuron, 		\
			neuron->nx);
	}
}
