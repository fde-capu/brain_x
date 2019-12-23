/* ******************************************* */
/*                                             */
/*                     |:||||||:|||:|:||:||::| */
/* defs.h              |||::|:|:|::||:|:::|||: */
/*                     ::|::|::::||::::::|:||| */
/*     |:||:| <|:||:|>                         */
/*                                             */
/* C20191211160336 |:||:|                      */
/* U20191223164728 ::::::                      */
/*                                             */
/* ******************************************* */

/*
** Default functions:
*/
# define DEF_RE			"re_sigmoid"
# define DEF_OP			"op_spark"
# define DEF_OP_BIAS	"op_random"

/*
** Default files:
*/
# define DEF_GENOME		"genome_table_default.x"

/*
** Default initial creation values:
*/
# define DEFB 1
# define DEFI 1
# define DEFH 2
# define DEFO 1
# define DEFA 8
# define GENB 2
# define GENI 1
# define GENH 2
# define GENO 1 
# define GENA 16 

/*
** Printing definitions:
*/
# define GNM_TITLE "\n::: GENOME ::: :%p: :::\n"
# define GNM_A_STR "%s:[%3lu*%-3lu] [%3lu]--%0.5lf-->[%-3lu] {%15s|%-15s} %p>%p\n"
# define GNM_A_VAR get_typename(neuron->tp), neuron->id, neuron->id,\
			neuron->in,neuron->tr,neuron->ou,\
			neuron->re, neuron->op, neuron, neuron->nx
# define GNM_N_STR "%s:[%3lu*%-3lu] [ %0.16lf ] {%15s|%-15s} %p>%p\n"
# define GNM_N_VAR get_typename(neuron->tp), neuron->id, neuron->id, 	\
			neuron->tr, neuron->re, neuron->op, neuron,neuron->nx
# define BRA_TITLE "\n::: BRAIN ::: ~%p~ :::\n"
# define NET_A_STR " >[ %5lu ] <-------- %0.5lf -- [%3lu*%-3lu] {%p|%-p} %p>%p\n"
# define NET_A_VAR ni->ou,ni->tr,n->id,n->id,ni->re,ni->op,n,n->nx
# define NET_N_STR "%s:[%3lu*%-3lu] : %0.5lf %s [| %0.2lf ] {%p|%-p} %p>%p\n"
# define NET_N_VAR get_typename(ni->tp),n->id,n->id,n->bz,gauge_bar(n->bz),ni->tr,\
				ni->re, ni->op,n,n->nx
# define NET_H_STR " |[%3lu*%-3lu] [%3lu]-%0.4lf->[%-3lu] {%p|%-p}|%p>%p\n"
# define NET_H_VAR 	n->id,n->id,   ni->in,ni->tr,ni->ou,ni->re,ni->op,n,n->nx
# define CLIPCHAR '+'
# define TPN_B	'B'
# define TPN_I	'I'
# define TPN_H	'H'
# define TPN_O	'O'
# define TPN_A	'A'

/*
** System macros:
*/
# define COLOR_FORE 69
# define STRESS 5
# define STRESS_BRAIN 256
# define TIC_SEC .025
# define CLEAR_SCREEN 1
# define PRINT_ADDRESS 0
# define PRINT_HERD 0
# define FILE_NAME_LIMIT 30
# define FNL FILE_NAME_LIMIT
