#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Produit.h"
#include <gtk/gtk.h>


/****initialisation****/
 void initialisation(Liste *liste)
{
    Produit * produit =(Produit*)malloc(sizeof(Produit));
    produit->t=1;
    produit->num=1000;
    produit->Q=1;
    produit->d.j=1;
    produit->d.m=1;
    produit->d.a=1;
    *(produit->ID)="kjguyf";
    produit->p=1;
    produit->next =NULL;
    liste->first =produit;
}
svoid add_produit(Liste *liste)
{ 
Liste *liste=(Liste *)data;
int n=0;
printf("donner le nombre de produit\n");
scanf("%i",&n);
Produit *nouveau =(Produit *)malloc(sizeof(Produit));
    
for (int i = 0; i < (n); ++i)
{
printf("produit numéro %i \n",i);
do {
    printf("donner le type du produit soit 0 pour un produit consommable soit 1 pour un produit non consommable \n");
    scanf("%i",&(nouveau->t));

}while((nouveau->t<0)||(nouveau->t>1));
printf("donner l ID du produit\n");
scanf("%s",(nouveau->ID));
printf("donner le prix du produit\n");
scanf("%f",&(nouveau->p));
do {
printf("donner le jours de fabrication\n");
scanf("%i",&((nouveau->d).j));

}while(((nouveau->d).j<0)||(nouveau->d).j>32);
do {

printf("donner le mois de fabrication\n");
scanf("%i",&((nouveau->d).m));
}while(((nouveau->d).m<0)||(nouveau->d).m>12);
do {
printf("donner l'année de fabrication\n");
scanf("%i",&((nouveau->d).a));
}while(((nouveau->d).a<0)||(nouveau->d.a)>2017);

printf("donner la quantité du produit\n");
scanf("%i",&(nouveau->Q));
nouveau->num=i;
/* Insertion du nouveau produit au début de la liste */
nouveau->next =liste->first;
liste->first= nouveau;
    
}

}
void afficher_liste(Liste *liste)
{

	Produit *prod=NULL;
	Produit *prev=NULL;
    prev=liste->first;
	prod=prev->next;
	printf(" le numéro du produit|| le type  || ID  ||le prix DT ||la date de fabrication||la quantité disponible  \n"    );
	while (prod!=NULL)
		{
            printf(" %i                   %i  ||  %s      ||      %.2f ||             %i/%i/%i    ||                 %i \n",prev->num,prev->t,prev->ID,prev->p,(prev->d).j,(prev->d).m,(prev->d).a,prev->Q);
            prev=prod;
            prod=prev->next;
		}

}
/****suppression du 1er element ****/
void delete_first(Liste *liste)
{
if (liste == NULL)
{
exit(EXIT_FAILURE);
}
if (liste->first != NULL)
{
Produit *aSupprimer = liste->first;
liste->first = liste->first->next;
free(aSupprimer);
}
}
/****suppression d'un element qlq de la liste different du premier****/
void delete_n(Liste *liste)
{
int a=0;
printf("donner le numéro du produit a supprimer\n");
scanf("%i",&a);
Produit *previous=NULL;
Produit *ptr=NULL;

if (liste->first->next != NULL && liste->first->num !=a)
{
	previous=liste->first;
	ptr=previous->next;
	while (ptr->num !=a && ptr!=NULL)
	{
		previous=ptr;
		ptr=previous->next;
	}
if(ptr != NULL)
	{
		previous->next=ptr->next;
		free(ptr);
	}
else
{
	printf("produit intouvable\n");
}
}

}
/****calculer la taille de la liste ****/
int taille(Liste *liste)
{
    Produit *var=liste->first;
    int j=0;
    while(var->next !=NULL)
        {
            j+=1;
            var=var->next;

        }

    return(j);
}
/*****mise ajour de la liste *****/
void maj(Liste *liste)
{
    //char id[40];
    int z,l=0;
    Produit *ptr=NULL;
    printf("donner le numero du produit a mdifier");
    scanf("%i",&l);
    ptr=liste->first;
    while ((ptr->num != l)&& (ptr!=NULL))
        {
				ptr=ptr->next;
        }

    printf("donner la case a modifier \n1/pour modifier l'ID\n2/pour modifier le type\n3/pour modifier la date\n4/pour modifier le prix\n5/pour modifier la quantité ");
    scanf("%i",&z);
    switch(z)
    {
        case 1:
        {
        printf("l'ancien ID est %s\n",ptr->ID);

        printf("donner le nouveau id");
        scanf("%s",ptr->ID);

        }break;
        case 2:
        {
            do
            {   printf("l'ancien type est %i\n",ptr->t);
                printf("donner le nouveau type");
                scanf("%i",&ptr->t);

            }while((ptr->t<0)||(ptr->t>1));



        }
        case 3:
        {
        do
        {
        printf("l'ancien jour de fabrication est %i\n",ptr->d.j);
        printf("donner le nouveau jour de fabrication jj ");
        scanf("%i",&ptr->d.j);
        printf("l'ancien mois de fabriction %i\n",ptr->d.m);
        printf("donner la nouveau mois de fabrication  mm");
        scanf("%i",&ptr->d.m);
        printf("l'ancienne année de fabrication est %i\n",ptr->d.a);
        printf("donner la nouvelle année de fabrication aa ");
        scanf("%i",&ptr->d.a);
        }while(((ptr->d.j<0)||(ptr->d.j>32))&&((ptr->d.m<0)||(ptr->d.m>12))&&((ptr->d.a<0)||(ptr->d.a>2017)));
        }break;
        case 4:
        {
        printf("l'ancienne quantité est %i\n",ptr->Q);
        printf("donner la nouvelle quantité");
        scanf("%i",&ptr->Q);




        }break;
        case 5:
        {
        printf("l'ancien prix est %f\n",ptr->p);
        printf("donner la nouveau prix");
        scanf("%2f",&ptr->p);


        }break;

    }





    }





/****sauvgarder****/
void sauvgarder(Liste *liste)
{
    FILE *fichier1;
    fichier1=fopen("fichier1.ods","w");//ouvrire le fichier en mode ecriture
    Produit *prod=NULL;
	prod=liste->first;

    if (fichier1!=NULL)//verifier si le fichier est ouvert
    {
    while(prod->next!=NULL)
    {
    fprintf(fichier1,"  l'ID %s\n ",prod->ID);
    fprintf(fichier1," La_quantité %i\n ",prod->Q);
    fprintf(fichier1," le_Prix %f \n",prod->p);
    fprintf(fichier1,"  le_jour_de_fabrication %i\n ",prod->d.j);
    fprintf(fichier1," le_mois_de_fabrication %i\n",prod->d.m);
    fprintf(fichier1,"  l'année_de_fabrication %i\n",prod->d.a);
    fprintf(fichier1,"  le_type %i\n",prod->t);
    fprintf(fichier1,"  son_numéro %i\n",prod->num);
    fprintf(fichier1,"\n");
    prod=prod->next;
    }
    fclose(fichier1);
    }
}
void ajouteramonpanier(Liste *liste,int n)
{
FILE *commande;
int q;
char nom[40],adresse[100];
Produit *prod=liste->first;
commande=fopen("client.txt","w");
printf("donner votre pseudo");
scanf("%s",nom);
printf("donner votre adresse");
scanf("%s",adresse);
printf("donner la quantite desirée");
scanf("%i",&q);

if (commande!=NULL)
{
while( prod->num != n && prod!= NULL)
{
prod=prod->next;
}
fprintf(commande,"mon pseudo est:%s/l'adresse est:%s le produit commandé est:%s la quantité désirée est:%i ",nom,adresse,prod->ID,q);

}
}
/***afficher_le premier_menu****/
int  premier_menu()
{
            int a=0;
            printf("                     $$ Bienvenue a notre entreprise F&I $$");
            printf("\n                       --------------------------");
            printf("\n                           Choisir votre choix:\n");
            printf("                               ******************\n");
            printf("                               * 1- ENTREPRISE  *\n");
            printf("                               *                *\n");
            printf("                               * 2- CLIENT      *\n");
            printf("                               *                *\n");
            printf("                               * 0- Quitter     *\n");
            printf("                               ******************\n");
            printf("\n");
            do
            {
                scanf("%i",&a);
            }while((a<0)||(a>2));
            return(a);
}
/***deuxieme menu****/
int deuxieme_menu()
{
            int x;
            printf(       "\n           $$ Bienvenue dans l'espace entrprise $$\n");
            printf("                                 +++ MENU +++        \n");
            printf("                         **********************************\n");
            printf("                         * 1- ajouter produits            *\n");
            printf("                         *                                *\n");
            printf("                         *2- Afficher produits            *\n");
            printf("                         *                                *\n");
            printf("                         *3- Mettre a jours un produit    *\n");
            printf("                         *                                *\n");
            printf("                         *4- Supprimer un produit         *\n");
            printf("                         *                                *\n");
            printf("                         *5- Retourner au menu principal  *\n");
            printf("                         **********************************\n");
            printf("\n");
            do
            {
                printf("\n\n\nSaisir votre choix (entre 1 et 5): ");
                scanf("%d",&x);
            }while ( ( x < 1 ) || ( x > 5 ) );
            return(x);
}
int troisieme_menu()
{
    int a;
                        printf("                 BIENVENU CHER CLIENT QUE DESIREZ VOUS ?\n");
                        printf("                         ****************************\n");
                        printf("                         *1-afficher les produits   *\n");
                        printf("                         *                          *\n");
                        printf("                         *2-ajouter a mon panier    *\n");
                        printf("                         *                          *\n");
                        printf("                         *3-donner votre avis       *\n");
                        printf("                         *                          *\n");
                        printf("                         *0-QUITER                  *\n");
                        printf("                         ****************************\n");
                        do
                        {
                            scanf("%i",&a);
                        }while((a<0)||(a>3));

                        return(a);
}
/***commenter*****/

