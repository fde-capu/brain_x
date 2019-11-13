/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   debug.c                                                                  */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 00:42:59 by ||||||                                   */
/*   Updated: 2019/11/12 07:11:13 by ||||||                                   */
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

void	print_net(net *n)
{
	STRESS_IN
	while (n)
	{
		printf("net id:%2d*%2d %2x>%2x\n", \
			n->id, n->innov,
			n, n->next);
		n = n->next;
		STRESS_OUT
	};
}

void	print_genome(void)
{
	printf("::: GENOME :::\n");
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
	do
	{
		print_neuron(n);
		n = n->next;
	} while (n);
}

char	*get_typename(t_type t)
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
	printf("%s:[%3d*%3d]|[%3d]--%0.5lf-->[%3d] {%2x} %2x>%2x\n", \
		get_typename(neuron->type), \
		neuron->id, neuron->innov, \
		neuron->in, \
		neuron->threshold, neuron->out, \
		neuron->op, neuron, \
		neuron->next);
}
