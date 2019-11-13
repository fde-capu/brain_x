/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   helper.c                                                                 */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/08 12:03:46 by ||||||                                   */
/*   Updated: 2019/11/12 07:12:38 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_id	net_neu_concat(neu *a, net *b)
{
	t_id	alen;
	net		new_b;
	alen = 1;
	while (a)
	{
		new_b.id = a->id;
		new_b.innov = a->innov;
		new_b.next = 0;
		b->next = &new_b;
		a = a->next;
		b = b->next;
		alen++;
		print_net(b);
	}
	return (alen);
}

neuidinn	get_neu_from_net \
	(int n, net *l)
{
	neuidinn	out;

	printf("get n:%d ",n);
	while(--n)
		l++;
	out.id = l->id;
	printf("id:%d?\n",out.id);
	out.innov = l->innov;
	return (out);
}
