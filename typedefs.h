/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   typedefs.h                                                               */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/06 13:46:58 by ||||||                                   */
/*   Updated: 2019/11/13 18:32:46 by ||||||                                   */
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
	t_innov				innov;
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
	t_id	in;
	t_id	out;
	t_fine	threshold;
	t_fine	(*op)(bra *, neu *);
	// op = &function;
	// (*op)(a,b);
	t_innov	innov;
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
	t_id	id;
	t_innov	innov;
} nii;

/// GLOBALS ///
t_id	g_id;
t_innov	g_innov;
gnm		*g_genome;
