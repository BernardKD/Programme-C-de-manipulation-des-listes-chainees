#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"td112.h"
int main(){
	Liste t;
	t=init();
	int v,n,m,i,val;
	printf("\t\tMANIPULATIONS SUR LES LISTES CHAINEES\n");
	do{
		printf("1- Enregistrer des entiers\n2- Afficher la liste enregistree\n3- Inserer un entier en tete\n4- Inserer un entier entier en queue\n5- Supprimmer un entier en tete\n6- Supprimmer un entier en queue\n7- Inserer un entier apres une valeure\n8- Insere un entier avant une valeure\n9- Supprimmer un entier apres une valeure\n10- Supprimmer un entier avant une valeure\n11- Inserer un entier a une position quelconque\n12- Supprimmer un entier a une position quelconque\n0- Quitter\n");
		printf("Entrez le chiffre coresspondant a votre a votre choix : ");
		scanf("%d",&n);	
		switch (n)
		{
		case 1 :
			printf("Entrez le nombre d'entiers a enregistrer :");
			scanf("%d",&m);
			i=0; 
			while(i<m){
				printf("Entrez l'entier %d a enregistrer : ",i+1);
				scanf("%d",&v);
				t=inserthead(t,v);
				i += 1;
			}
			printf("\nEnregistrement effectuee avec succes !\n");
			break;

		case 2 :
			printf("Liste des entiers : ");
			affichage(t);
			printf("\nOperations effectuees avec succes !\n");
			break;

		case 3 :
			printf("Entrez l'entier a enregistrer : ");
			scanf("%d",&v);
			t=inserthead(t,v);
			printf("\nInsertion en tete effectuee avec succes !\n");
			break;
		
		case 4 :
			printf("Entrez l'entier a enregistrer : ");
			scanf("%d",&v);
			t=insertbottom(t,v);
			printf("\nInsertion en queue effectuee avec succes !\n");
			break;

		case 5 :
			t=deletehead(t);
			printf("\nSuppression en tete effectuee avec succes !\n");
			break;

		case 6 :
			t=deletebottom(t);
			printf("\nSuppression en queue effectuee avec succes !\n");
			break;

		case 7 :
			printf("Entrez l'entier apres lequel enregistrer : ");
			scanf("%d",&v);
			int d = chercherval(t,v);
			if(d!=0){
				printf("Operation impossible !\n");
			}else{
				printf("Entrez l'entier a enregistrer : ");
				scanf("%d",&val);
				t=insertafter(t,v,val);
				printf("\nInsertion apres effectuee avec succes !\n");
			}
			break;
		
		case 8 :
			printf("Entrez l'entier avant lequel enregistrer : ");
			scanf("%d",&v);
			int x = chercherval(t,v);
			if(x!=0){
				printf("Operation impossible !\n");
			}else{
				printf("Entrez l'entier a enregistrer : ");
				scanf("%d",&val);
				t=insertbefore(t,v,val);
				printf("\nInsertion avant effectuee avec succes !\n");
			}
			break;

		case 9 :
			printf("Entrez l'entier apres lequel supprimmer : ");
			scanf("%d",&v);
			d = chercherval(t,v);
			if(d!=0){
				printf("Operation impossible !\n");
			}else{
				t=deleteafter(t,v);
				printf("\nSuppression apres effectuee avec succes !\n");
			}
			break;
		
		case 10 :
			printf("Entrez l'entier avant lequel supprimmer : ");
			scanf("%d",&v);
			x = chercherval(t,v);
			if(x!=0){
				printf("Operation impossible !\n");
			}else{
				t=deletebefore(t,v);
				printf("\nSuppression avant effectuee avec succes !\n");
			}
			break;

		case 11 :
			printf("Entrez la position ou inserer l'entier : ");
			scanf("%d",&v);
			printf("Entrez l'entier a inserer a cette position : ");
			scanf("%d",&val);
			t=insertpos(t,v,val);
			break;
		
		case 12 :
			printf("Entrez la position ou supprimer l'entier : ");
			scanf("%d",&v);
			t=deletepos(t,v);
			break;

		case 0 :
			printf("Au Revoir !");
			break;

		default:
			printf("Ereur ! Veuillez choisir une option valable.\n");
			break;
		}
		printf("\n");
	}while(n!=0);
	return 0;
}
