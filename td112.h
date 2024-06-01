#ifndef _TD112_
    #define _TD112_
	typedef struct Liste{
		int val;
		struct Liste *next;
	}*Liste;
	Liste init();
	Liste inserthead(Liste t, int v);
	Liste first(Liste t);
	Liste second(Liste t);
	Liste insertbottom(Liste t, int v);
	Liste deletebottom(Liste t);
	Liste deletehead(Liste t);
	int chercherval(Liste t, int val);
	Liste pointeuravantvaleur(Liste t, int v);
	Liste pointeurvaleur(Liste t, int v);
	Liste insertbefore(Liste t, int v, int val);
	Liste insertafter(Liste t, int v, int val);
	Liste deletebefore(Liste t, int v);
	Liste deleteafter(Liste t, int v);
	Liste insertpos(Liste t, int v, int val);
	Liste deletepos(Liste t, int v);
	void affichage(Liste t);
#endif
