/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   typedefs.h                                                               */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/06 13:46:58 by ||||||                                   */
/*   Updated: 2019/11/14 11:06:20 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

typedef TYPE_OF_ID		tid;
typedef TYPE_OF_TYPE	typ;
typedef TYPE_OF_FINE	fin;
typedef TYPE_OF_CHARGE	t_charge;
typedef TYPE_OF_INNOV	tin;

typedef struct	brain		bra;
typedef struct	neuron		neu;
typedef struct	neuro_net	net;

typedef struct	neuro_net
{
	tid				id;
	tin				iv;
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
	tid	id;
	typ	type;
	tid	in;
	tid	out;
	fin	threshold;
	fin	(*op)(bra *, neu *);
	// op = &function;
	// (*op)(a,b);
	tin	iv;
	struct	neuron	*next;
}	neu;

typedef struct	genome
{
	neu		*bias;
	neu		*inpu;
	neu		*hidd;
	neu		*outp;
	neu		*axon;
}	gnm;

typedef struct	tuplet_id_inn
{
	tid	id;
	tin	iv;
} nii;

/// GLOBALS ///
tid		g_id;
tin		g_iv;
gnm		*g_genome;
