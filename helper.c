/* ******************************************* */
/*                                             */
/*                     |:||||||:|||:|:||:||::| */
/* helper.c            |||::|:|:|::||:|:::|||: */
/*                     ::|::|::::||::::::|:||| */
/*     |::||: <|::||:>                         */
/*                                             */
/* C20191211171456 |::||:                      */
/* U20191224175847 |:|:|:                      */
/*                                             */
/* ******************************************* */

#include "header.h"

int		strm(char *a, char *b)
{
	while ((*a) && (*b) && (*a == *b))
	{
		a++;
		b++;
	}
	if ((*a == 0) || (*b == 0)) return (1);
	return (0);
}

tid	count_neu(neu *l)
{
	tid	c;

	c = 0;
	while (l)
	{
		c++;
		l = l->nx;
	}
	return (c);
}

neu	*neuron_by_id(tid id)
{
	neu		*n;
	char	found;
	tid		i;

	i = 0;
	found = 0;
	while ((!found) && (i <= 4))
	{
		n = i_to_g_niche(i);
		while (n)
		{
			if (n->id == id)
			{
				return (n);
			}
			n = n->nx;
		}
		i++;
	}
	FAIL_SSI(NEU_ID_NOT_FOUND, "id", id)
}

neu	*g_axon_by_id(tid id)
{
	neu	*n;

	n = (neu *)g_gnm->axon;
	while (n)
	{
		if (n->id == id)
			return (n);
		n = n->nx;
	}
	return (0);
}

tid	axon_ou(tid id)
{
	return (g_axon_by_id(id)->ou);
}

tid	axon_in(tid id)
{
	return (g_axon_by_id(id)->in);
}

int	find_id(tid id, net *n)
{
	while (n)
	{
		if (n->id == id)
			return (1);
		n = n->nx;
	}
	return (0);
}

net	*neuron_in_brain(bra *b, tid id)
{
	net	*n;
	int	i;

	i = -1;
	while (++i <= 4)
	{
		n = i_to_b_niche(i, b);
		while (n)
		{
			if (n->id == id)
				return (n);
			n = n->nx;
		}
	}
	return (0);
}

net	*i_to_b_niche(int i, bra *b)
{
	net	*n;
	n =	i == 0 ? b->bias :
		i == 1 ? b->inpu :
		i == 2 ? b->hidd :
		i == 3 ? b->outp :
		i == 4 ? b->axon : 0;
	return (n);
}

neu	*i_to_g_niche(int i)
{
	neu	*n;
	n =	i == 0 ? g_gnm->bias :
		i == 1 ? g_gnm->inpu :
		i == 2 ? g_gnm->hidd :
		i == 3 ? g_gnm->outp :
		i == 4 ? g_gnm->axon : 0;
	return (n);
}

double	sigmoid(double v)
{
	return ((pow(EULER, v) / 
		((pow(EULER, v) + 1))) - .5);
}

net		*prepend_cp(net *ne, net *n)
{
	net	*cp;

	cp = init_net();
	cp->id = n->id;
	cp->iv = n->iv;
	cp->bz = n->bz;
	cp->iz = n->iz;
	cp->pt = n->pt;
	cp->nx = ne;
	ne = cp;
	return (cp);
}

char	*filename_str(char *fn)
{
	char	*fn_o;
	char	*p;
	
	fn_o = malloc(sizeof(char) * FNL);
	p = fn_o;
	p = strcpy(p, fn);
	return (fn_o);
}

mod		*init_mod(void)
{
	mod	*nm;

	nm = malloc(sizeof(mod));
	nm->fu[0] = 0;
	nm->ad = 0;
	nm->nx = 0;
	return (nm);
}

void	append_module(char *m_n, void *m_a)
{
	mod	*mp;
	mod	*ns;

	mp = g_module;
	if (!mp->ad)
	{
		ns = mp;
	}
	else
	{
		while (mp->nx)
			mp = mp->nx;
		ns = init_mod();
		mp->nx = ns;
	}
	strcpy(ns->fu, m_n);
	ns->ad = m_a;
	return ;
}

void	exec(char *m_n, net *n)
{
	mod	*m;
	
	m = g_module;
	while (m)
	{
		if (strm(m->fu, m_n))
		{
			printf("%s(%ld)\n", m->fu, n->id);
			m->ad(n);
			return ;
		}
		m = m->nx;
	}
	FAIL_SS("Inconsistent module name", m_n);
	return ;
}
