/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   typedefs.h                                                               */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/06 13:46:58 by ||||||                                   */
/*   Updated: 2019/11/08 09:38:16 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

typedef TYPE_OF_ID		t_id;
typedef TYPE_OF_TYPE	t_type;
typedef TYPE_OF_FINE	t_fine;
typedef TYPE_OF_CHARGE	t_charge;
typedef TYPE_OF_INNOV	t_innov;

typedef struct	brain		bra;
typedef struct	neuron		neu;
typedef struct	neuro_net	net;

typedef struct	neuro_net
{
	t_id				id;
	bra					*parent;
	t_charge			charge;
	struct	neuro_net	*next;
}	net;

typedef struct	brain
{
	net		*bias;
	net		*inpu;
	net		*hidd;
	net		*outp;
	net		*axon;
	struct	brain	*next;
}	bra;

typedef struct	neuron
{
	t_id	id;
	t_type	type;
	net		*in;
	net		*out;
	t_fine	threshold;
	t_fine	(*op)(bra *, neu *);
	// op = &function;
	// (*op)(a,b);
	t_innov	innov;
	struct	neuron	*next;
}	neu;

