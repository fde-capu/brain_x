/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   typedefs.h                                                               */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/06 13:46:58 by ||||||                                   */
/*   Updated: 2019/11/19 11:20:03 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

typedef TYPE_OF_ID		tid;
typedef TYPE_OF_TYPE	typ;
typedef TYPE_OF_FINE	fin;

typedef struct	brain		bra;
typedef struct	neuron		neu;
typedef struct	neuro_net	net;

typedef struct	neuro_net
{
	struct	neuron		*ps;
	tid		id;
	tid		iv;
	fin		bz;
	bra		*pt;
	fin		_bz;
	struct	neuro_net	*nx;
}	net;

typedef struct	brain
{
	net		*bias;
	net		*inpu;
	net		*hidd;
	net		*outp;
	net		*axon;
	struct	brain	*nx;
}	bra;

typedef struct	neuron
{
	tid	id;
	tid	iv;
	typ	tp;
	tid	in;
	tid	ou;
	fin	tr;
	void	(*op)();
//	void	(*op)(bra *, neu *);
	// op = &function;
	// (*op)(a,b);
	void	(*re)();
//	void	(*re)(bra *, neu *);
	struct	neuron	*nx;
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
	tid	iv;
} nii;

/// GLOBALS ///
tid		g_id;
tid		g_iv;
gnm		*g_genome;
