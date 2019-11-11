/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   debug.c                                                                  */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 00:42:59 by ||||||                                   */
/*   Updated: 2019/11/11 12:20:31 by ||||||                                   */
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

void	print_net(net n)
{
	
}

void	print_genome(void)
{
	printf("::: GENOME :::\n");
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
	printf("[%3d*%3d] %s:[%3d]--%0.5lf-->[%3d] {%2x}%2x>%2x\n", \
		neuron->id, neuron->innov, \
		get_typename(neuron->type), neuron->in, \
		neuron->threshold, neuron->out, \
		neuron->op, neuron, \
		neuron->next);
}
