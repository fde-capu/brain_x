/* ******************************************* */
/*                                             */
/*                     |:||||||:|||:|:||:||::| */
/* typedefs.h          |||::|:|:|::||:|:::|||: */
/*                     ::|::|::::||::::::|:||| */
/*     ::|||| <::||||>                         */
/*                                             */
/* C20191211171721 ::||||                      */
/* U20191219150704 :|::||                      */
/*                                             */
/* ******************************************* */

typedef TYPE_OF_ID		tid;
typedef TYPE_OF_TYPE	typ;
typedef TYPE_OF_FINE	fin;
typedef TYPE_OF_CHARGE	tbz;
typedef TYPE_OF_WORD	wor;

typedef struct	brain		bra;
typedef struct	neuron		neu;
typedef struct	neuro_net	net;

typedef struct	neuro_net
{
	struct brain	*pt;
	tid		id;
	tid		iv;
	tbz		iz;
	tbz		bz;
	struct	neuro_net	*nx;
}	net;

typedef struct	brain
{
	net		*bias;
	net		*inpu;
	net		*hidd;
	net		*outp;
	net		*axon;
	net		*resp;
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
	wor	op[30];
	wor re[30];
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
gnm		*g_gnm;
char	*g_gnm_file;
int		g_continue;
