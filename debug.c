/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   debug.c                                                                  */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/07 00:42:59 by ||||||                                   */
/*   Updated: 2019/11/20 03:46:58 by ||||||                                   */
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
	printf(GNM_TITLE);
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
	return ;
}

void	print_neu_list(neu *n)
{
	while (n)
	{
		print_neuron(n);
		n = n->nx;
	}
	return ;
}


void	print_brain(bra *b)
{
	printf(BRA_TITLE, b);
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
	print_net_herd(n);
	return ;
}

void	print_net_list(net *n)
{
	neu	*ni;
	net	*na;

	while (n)
	{
		ni = neuron_by_id(n->id);
		if (ni->tp & TP_A)
		{
			printf(NET_A_STR, NET_A_VAR);
			return ;
		}
		else
		{
			printf(NET_N_STR, NET_N_VAR);
			na = n->pt->axon;
			while (na)
			{
				if (neuron_by_id(na->id)->in == n->id) //&& ou is con
					print_net_list(na);
				na = na->nx;
			}
		}

		n = n->nx;
	}
	return ;
}


void	print_net_herd(net *n)
{
	neu		*ni;
	net		*na;
	tid		found;
	tid		i;

	while (n)
	{
		ni = neuron_by_id(n->id);
		if (ni->tp & TP_A)
		{
			found = 0;
			i = 0;
			while ((i <= 3) && (!found))
			{
				na =	i == 0 ? n->pt->bias : \
						i == 1 ? n->pt->inpu : \
						i == 2 ? n->pt->hidd : \
							n->pt->outp;
				while ((na) && (!found))
				{
					if (na->id == ni->in) // && ni->ou is con
						found = 1;
					na = na->nx;
				}
				i++;
			}
			if (!found)
				printf(NET_H_STR, NET_H_VAR);
		}
		n = n->nx;
	}
	return ;
}

void	print_neuron(neu *neuron)
{
	if (neuron->tp & TP_A)
		printf(GNM_A_STR, GNM_A_VAR);
	else
		printf(GNM_N_STR, GNM_N_VAR);
	return ;
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

char	*gauge_bar(fin v)
{
	char	*out;
	char	*p;
	char	*o;
	int		i;
	int		c;
	int		c2;

	out = malloc(sizeof(char) * 12);
	p = out;
	o = out;
	i = -1;

	c2 = 0;
	c = (int)(v * 10);
	c = c < 0 ? 0 : c;
	while (++i < 10)
	{
		if (i < c)
			*(p + i) = '|';
		else
		{
			if (!c2)
			{
				c2 = (int)(v * (c == 0 ? 100 : 100)) % 10;
				if (c2 >= 5)
				{
					*(p + i) = ':';
				}
				else
					*(p + i) = ' ';
			}
			else
			{
				*(p + i) = ' ';
			}
		}
	}
	if (v >= 1)
		*(p + i - 1) = CLIPCHAR;
	*(p + i) = 0;
	return (out);
}
