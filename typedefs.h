/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   typedefs.h                                                               */
/*                                                  ||||||:||||::|||:|:|||:   */
/*   By: |||||| <::::::>                            ::||:||:|::||::|:||::::   */
/*                                                  |:|:|:::|::|::::::|||||   */
/*   Created: 2019/11/06 13:46:58 by ||||||                                   */
/*   Updated: 2019/11/07 01:45:22 by ||||||                                   */
/*                                                                            */
/* ************************************************************************** */

typedef struct	brain		bra;
typedef struct	neuron		neu;
typedef struct	neuro_net	net;

typedef struct	neuro_net
{
	long	id;
	bra		*parent;
	double	charge;
	struct	neuro_net	*next;
}	net;

typedef struct	brain
{
	net		*bias;		// -2
	net		*input;		// -1
	net		*hidden;	//  0
	net		*output;	//  1
	net		*axon;		//  2
	struct	brain	*next;
}	bra;

typedef struct	neuron
{
	long	id;
	// types: see struct brain
	signed char	\
			type;
	net		*in;
	net		*out;
	float	threshold;
	float	(*op)(bra *, neu *);
	// op = &function;
	// (*op)(a,b);
	struct	neuron	*next;
}	neu;

