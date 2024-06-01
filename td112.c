#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"td112.h"
Liste init(){
	return NULL;
}
Liste inserthead(Liste t, int v){
	Liste l = (Liste) malloc (sizeof(Liste));
	l->val = v;
	l->next = t;
	t=l;
	return t;
}
Liste first(Liste t){
	Liste l=t;
	if(l==NULL){
		printf("Liste vide");
		return NULL;
	}else{
		while(l->next!=NULL){
			l = l->next;
		}
	}
	return l;
}
Liste second(Liste t){
	Liste l=t;
	if(l==NULL){
		printf("Liste vide");
		return NULL;
	}else{
		while(l->next->next!=NULL){
			l = l->next;
		}
	}
	return l;
}
Liste insertbottom(Liste t, int v){
	if(t==NULL){
		t=inserthead(t,v);
		return t;
	}
	Liste l;
	l=first(t);
	l->next= (Liste) malloc (sizeof(Liste));
	l->next->next = NULL;
	l->next->val = v;
	return t;
}
Liste deletebottom(Liste t){
	Liste l = t;
	if(t==NULL){
		printf("Liste vide");
		return t;
	}else if(l->next==NULL){
		free(l);
		l=NULL;
		return l;
	}else{
		l=second(t);
		free(l->next);	
		l->next=NULL;	
		return t;
	}
}
Liste deletehead(Liste t){
	if(t==NULL){
		printf("Liste vide");
		return t;
	}else{
		t=t->next;
		return t;
	}
}
//
int chercherval(Liste t, int val){
	Liste l=t;
	if(l==NULL){
		printf("Liste vide\n");
		return -1;
	}else if(l->val==val){
		return 0;
	}else{
		while((l->val!=val)&&(l!=NULL)){
			l = l->next;
		}
		if(l==NULL){
			printf("La valeure %d n'a pas ete trouve !",val);
			return -1;
		}else{
			printf("La valeure %d a ete trouvee !",val);
			return 0;
		}
	}
}
Liste pointeuravantvaleur(Liste t, int v){
	Liste l=t;
	int d=chercherval(t,v);
	if(d==0){
		if(l->val==v){
			return NULL;
		}else{
			while((l->next->val!=v)&&(l->next->next!=NULL)){
				l = l->next;
			}
			return l;
		}
	}else{
		return t;
	}
}
Liste pointeurvaleur(Liste t, int v){
	Liste l=t;
	int d=chercherval(t,v);
	if(d==0){
		if(l->val==v){
			return t;
		}else{
			while((l->val!=v)&&(l->next!=NULL)){
				l = l->next;
			}
			return l;
		}
	}else{
		return t;
	}
}
Liste insertbefore(Liste t, int v, int val){
	Liste l=pointeuravantvaleur(t,v);
	if(l==NULL){
		t=inserthead(t,val);
	}else{
		Liste m = (Liste) malloc (sizeof(Liste));
		m->val=val;
		m->next=l->next;
		l->next=m;
	}
	return t;
}
Liste insertafter(Liste t, int v, int val){
	Liste l=pointeurvaleur(t,v);
	Liste m = (Liste) malloc (sizeof(Liste));
	m->val=val;
	m->next=l->next;
	l->next=m;
	return t;
}
Liste deletebefore(Liste t, int v){
	Liste l=pointeuravantvaleur(t,v);
	if(l==NULL){
		printf("Impossible ! %d est la tete de la liste!\n",v);
	}else{
		int vas=l->val;
		Liste m=pointeuravantvaleur(t,vas);
		if(m==NULL){
			t=deletehead(t);
		}else{
			m->next=l->next;
			free(l);			
		}
	}
	return t;
}
Liste deleteafter(Liste t, int v){
	Liste l=pointeurvaleur(t,v);
	if(l->next==NULL){
		printf("Impossible ! %d est la queue de la liste!\n",v);
	}else{
		Liste m=l->next;
		l->next=l->next->next;
		free(m);
	}
	return t;
}
Liste insertpos(Liste t, int v, int val){
	Liste l=t;
	if(l==NULL){
		if(v==1){
			t->val=val;
			t->next=NULL;
			return t;
		}
		printf("Liste vide ! Action imposssible !\n");
		return t;
	}
	int i=1,g;
	while((i<v)&&(l!=NULL)){
		g=l->val;
		l = l->next;
		i+=1;
	}
	if(l==NULL){
		printf("La position %d n'existe pas, Action imposssible !\n",v);
		return t;
	}
	t=insertafter(t,g,val);
	return t;
}
Liste deletepos(Liste t, int v){
	Liste l=t;
	if(l==NULL){
		printf("Liste vide ! Action imposssible !\n");
	}
	int i=1,g;
	while((i<v)&&(l!=NULL)){
		g=l->val;
		l = l->next;
		i+=1;
	}
	if(l==NULL){
		printf("La position %d n'existe pas, Action imposssible !\n",v);
		return t;
	}
	t=deleteafter(t,g);
	return t;
}
//
void affichage(Liste t){
	Liste l=t;
	if(l==NULL){
		printf("Liste vide\n");
	}else{
		while(l!=NULL){
			printf("\"%d\"  ",l->val);
			l = l->next;         
		}
	}
}
