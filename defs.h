# define COLOR_FORE 104
# define STRESS 5
# define STRESS_BRAIN 256

# define GNM_TITLE "\n::: GENOME ::: :%p: :::\n"
# define GNM_A_STR "%s:[%3lu*%-3lu] [%3lu]--%0.5lf-->[%-3lu] {%p|%-p} %p>%p\n"
# define GNM_A_VAR get_typename(neuron->tp), neuron->id, neuron->id,\
			neuron->in,neuron->tr,neuron->ou,\
			neuron->re, neuron->op, neuron, neuron->nx
# define GNM_N_STR "%s:[%3lu*%-3lu] [ %0.16lf ] {%p|%-p} %p>%p\n"
# define GNM_N_VAR get_typename(neuron->tp), neuron->id, neuron->id, 	\
			neuron->tr, neuron->re, neuron->op, neuron,neuron->nx
# define BRA_TITLE "\n::: BRAIN ::: ~%p~ :::\n"
# define NET_A_STR " >[ %5lu ] <-------- %0.5lf -- [%3lu*%-3lu] {%p|%-p} %p>%p\n"
# define NET_A_VAR ni->ou,ni->tr,n->id,n->id,    ni->re,ni->op,n,n->nx
# define NET_N_STR "%s:[%3lu*%-3lu] : %0.5lf %s [| %0.2lf ] {%p|%-p} %p>%p\n"
# define NET_N_VAR get_typename(ni->tp),n->id,n->id,    n->bz,gauge_bar(n->bz),ni->tr,\
				ni->re, ni->op, n, n->nx
# define NET_H_STR " |[%3lu*%-3lu] [%3lu]-%0.4lf->[%-3lu] {%p|%-p}|%p>%p\n"
# define NET_H_VAR 	n->id,n->id,   ni->in,ni->tr,ni->ou,ni->re,ni->op,n,n->nx
# define CLIPCHAR '+'

# define TIC_SEC .25

# define DEFB 1
# define DEFI 3
# define DEFH 5
# define DEFO 3
# define DEFA 15

# define GENB 1
# define GENI 3
# define GENH 5
# define GENO 3
# define GENA 15

# define ALL_RE &re_sigmoid
