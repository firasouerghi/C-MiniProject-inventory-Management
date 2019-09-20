#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct{
                GtkWidget *label;
                GtkWidget *edit;
        }Data;

typedef struct DATE DATE;
struct DATE   {
                    int a,j,m;
              };
typedef struct Produit Produit;
struct Produit   {
                    float p;
                    int t,num,Q;
                    Produit *next;
                    char ID[40];
                    DATE d;
                    Data sec;
                 } ;
typedef struct Liste Liste;
struct Liste   {
                    Produit *first;
               };
/****initialisation****/
void initialisation(Liste *liste)
{
	Produit * produit =(Produit*)malloc(sizeof(Produit));
    produit->t=0;
    produit->num=000;
    produit->Q=0;
    produit->d.j=0;
    produit->d.m=0;
    produit->d.a=0;
    *(produit->ID)="0000000000";
    produit->p=0;
    produit->next =NULL;
    liste->first =produit;
}
/****ajout d'un produit****/
void add_produit(GtkWidget *widget ,gpointer data)
{

Liste *liste=data;
int n=0;
printf("donner le nombre de produit\n");
scanf("%i",&n);
for (int i = 0; i < (n); ++i)
{
Produit *nouveau =(Produit *)malloc(sizeof(Produit));
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
nouveau->num=n-i;
/* Insertion du nouveau produit au début de la liste */
nouveau->next =liste->first;
liste->first= nouveau;
    
}
printf("merci vous avez rempli vos produits\n");
}
void afficher_liste(GtkWidget *widget ,gpointer data)
{
	Liste *liste=(Liste *)data;
	Produit *prod=NULL;
	Produit *prev=NULL;
    prev=liste->first;
	prod=prev->next;
	printf(" le numéro     || le type  || ID  ||le prix DT ||la date de fabrication||la quantité disponible  \n"    );
	while (prod!=NULL)
		{
            printf("    %i          %i  ||  %s      ||      %.2f ||             %i/%i/%i    ||                 %i \n",prev->num,prev->t,prev->ID,prev->p,(prev->d).j,(prev->d).m,(prev->d).a,prev->Q);
            prev=prod;
            prod=prev->next;
		}

}
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

void delete_n(Liste *liste,int n)
{

Produit *previous=NULL;
Produit *ptr=NULL;

if (liste->first->next != NULL )
{
	previous=liste->first;
	ptr=previous->next;
	while (ptr!=NULL && ptr->num!=n)
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
void delete(GtkWidget *widget , gpointer data)
{
	int n=0;
	Liste *liste=(Liste *)data;
	printf("donner le numero du produit a supprimer\n");
	scanf("%i",&n);
	if (n==liste->first->num)
	{
		delete_first(liste);
	}
	else
	{
		delete_n(liste,n);
	}
}
void maj(GtkWidget *widget , gpointer data)
{
    
    int z,l=0;
    Liste *liste=(Liste *)data;
    Produit *ptr=NULL;
    printf("\ndonner le numero du produit a mdifier\n");
    scanf("%i",&l);
    ptr=liste->first;
    while ((ptr->num != l) && (ptr->next!=NULL))
        {
				ptr=ptr->next;
        }
    if(ptr->next!=NULL)
    {
    	printf("donner la case a modifier \n1/pour modifier l'ID\n2/pour modifier le type\n3/pour modifier la date\n4/pour modifier la quantité\n5/pour modifier le prix\n6/pour modifier le numéro\n ");
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
            	{
            	    printf("l'ancien type est %i\n",ptr->t);
                	printf("donner le nouveau type");
                	scanf("%i",&ptr->t);

            	}while((ptr->t<0)||(ptr->t>1));
			}break;
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
        		printf("l'ancien prix est %.f\n",ptr->p);
        		printf("donner la nouveau prix");
        		scanf("%f",&ptr->p);
			}break;
    		case 6:
    		{
    			printf("l'ancien numéro est %i\n",ptr->num );
    			printf("donner le nouveau numéro\n");
    			scanf("%i",&ptr->num);
    		}break;
    	}	
    }    
    else
	{
    	printf("VERIFIER BIEN QUE LE NUMERO EST VALIDE");
	}
}
void sauvgarder(GtkWidget *widget ,gpointer data)
{
    Liste *liste=(Liste *)data;
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
void ajouteramonpanier(GtkWidget *widget ,gpointer data)
{

float s=0;	
Liste *liste=(Liste *)data;	
FILE *commande;
int q ,n;
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
printf("donner le numéro du produit désiré\n");
scanf("%i",&n);

while( (prod->num!=n) && (prod->next!= NULL))
{
prod=prod->next;
}
if(prod->next==NULL)
{
	printf("VÉRIFIER LE NUMERO SVP");
}
else 
{
s=(float)prod->p *q;	
fprintf(commande,"mon pseudo est:%s/l'adresse est:%s le produit commandé est:%s la quantité désirée est:%i/votre facture est de:%.2f ",nom,adresse,prod->ID,q,s);
printf("votre facture est :%.2fDT\n",s );

}
	fclose(commande);

}

}
void commenter(GtkWidget *widget ,gpointer data)
{
	FILE *commenter=NULL;
	commenter=fopen("commentaire.txt","w");
	if(commenter!=NULL)
	{
		char ch[200];
		printf("votre commentaire nous fera un grand plaisire \n");
		scanf("%s",ch);
		//fgets(ch,sizeof(ch),stdin);
		fprintf(commenter,"%s",ch);

	}
		fclose(commenter);

}


void destroy(GtkWidget *widget,gpointer data)
{
	gtk_main_quit();
}
void entreprise(GtkWidget *bouton1,gpointer data)
{
    Liste *liste=(Liste *)data;
    int argc;
    char  **argv;
    GtkWidget *b1=NULL;
    GtkWidget *b2=NULL;
    GtkWidget *b3=NULL;
    GtkWidget *b4=NULL;
    GtkWidget *b5=NULL;
    GtkWidget *contain=NULL;
    GtkWidget *entreprise=NULL;
    const gchar *texte="verifier votre mot de passe SVP";
    const gchar*mdp="*********";
    const gchar *txt;
    /* On prend le texte de la boite d'edition */
    txt= gtk_entry_get_text ( GTK_ENTRY(liste->first->sec.edit) );
    /* On affiche le texte dans le label */
    if (strcmp(mdp,txt)==0)
    {
        gtk_init(&argc,&argv);
        entreprise=gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(entreprise),"bienvenue dans l'espace entreprise");
        g_signal_connect(G_OBJECT(entreprise),"destroy",G_CALLBACK(destroy),NULL);
        gtk_container_set_border_width(GTK_CONTAINER(entreprise),100);
        contain=gtk_vbox_new(FALSE,0);
        gtk_container_add(GTK_CONTAINER(entreprise),contain);
        b1=gtk_button_new_with_label("ajouter les produits");
        b2=gtk_button_new_with_label("afficher les produits");
        b3=gtk_button_new_with_label("mettre a jours un produit");
        b4=gtk_button_new_with_label("supprimer un produit");
        b5=gtk_button_new_with_label("sauvgarder");
        gtk_box_pack_start(GTK_BOX(contain),b1,TRUE,TRUE,0);
        gtk_box_pack_start(GTK_BOX(contain),b2,TRUE,TRUE,0);
        gtk_box_pack_start(GTK_BOX(contain),b3,TRUE,TRUE,0);
        gtk_box_pack_start(GTK_BOX(contain),b4,TRUE,TRUE,0);
        gtk_box_pack_start(GTK_BOX(contain),b5,TRUE,TRUE,0);
        g_signal_connect(G_OBJECT(b1),"clicked",G_CALLBACK(add_produit),liste);
        g_signal_connect(G_OBJECT(b2),"clicked",G_CALLBACK(afficher_liste),liste);
        g_signal_connect(G_OBJECT(b3),"clicked",G_CALLBACK(maj),liste);
        g_signal_connect(G_OBJECT(b4),"clicked",G_CALLBACK(delete),liste);
        g_signal_connect(G_OBJECT(b5),"clicked",G_CALLBACK(sauvgarder),liste);
        gtk_widget_show_all(entreprise);
        gtk_main();
    
       
    }
    else
    {
        gtk_label_set_text ( GTK_LABEL(liste->first->sec.label), texte );
    }

}
void client(GtkWidget *widget,gpointer data)
{
    int argc;
    char **argv;
    Liste *liste=NULL;
    liste=(Liste *)data;
    GtkWidget *client=NULL;
    GtkWidget *b1=NULL;
    GtkWidget *b2=NULL;
    GtkWidget *b3=NULL;
    GtkWidget *container=NULL;
    gtk_init(&argc,&argv);
    client=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(client),"ESPACE CLIENT");
    g_signal_connect(G_OBJECT(client),"destroy",G_CALLBACK(destroy),NULL);
    gtk_container_set_border_width(GTK_CONTAINER(client),100);
    container=gtk_vbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(client),container);
    b1=gtk_button_new_with_label("afficher les produits");
    b2=gtk_button_new_with_label("ajouter a mon pagner");
    b3=gtk_button_new_with_label("donner votre avis");

    gtk_box_pack_start(GTK_BOX(container),b1,TRUE,TRUE,0);
    gtk_box_pack_start(GTK_BOX(container),b2,TRUE,TRUE,0);
    gtk_box_pack_start(GTK_BOX(container),b3,TRUE,TRUE,0);
    
    g_signal_connect(G_OBJECT(b1),"clicked",G_CALLBACK(afficher_liste),liste);
    g_signal_connect(G_OBJECT(b2),"clicked",G_CALLBACK(ajouteramonpanier),liste);
    g_signal_connect(G_OBJECT(b3),"clicked",G_CALLBACK(commenter),liste);
    
    gtk_widget_show_all(client);
    gtk_main();
}
int main(int argc, char  *argv[])
{
    //initialisation d'une fenetre
    
    GtkWidget *boite;
    GtkWidget *window;
    GtkWidget *bouton1;
    GtkWidget *bouton2;
    GtkWidget *container;
    Liste *liste=(Liste *)malloc(sizeof(Liste));
    initialisation(liste);
    //l'initialisation de gtk
    gtk_init(&argc,&argv);  
    
    //creation d'une fenetre
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //titre de la console
    gtk_window_set_title(GTK_WINDOW(window),"welcome to our application");
    //metre les bords de la fenetre
    gtk_container_set_border_width(GTK_CONTAINER(window),100);
    container=gtk_vbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(window),container);
    bouton1=gtk_button_new_with_label("ESPACE ENTREPRISE");
    bouton2=gtk_button_new_with_label("ESPACE CLIENT");
    
    boite = gtk_vbox_new(FALSE, 5);
    liste->first->sec.label = gtk_label_new(NULL);
    liste->first->sec.edit = gtk_entry_new();

    gtk_box_pack_start(GTK_BOX(container),bouton1,TRUE,TRUE,0);
    gtk_box_pack_start( GTK_BOX(container),liste->first->sec.label, TRUE, TRUE, 0);
    gtk_box_pack_start( GTK_BOX(container),liste->first->sec.edit, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(container),bouton2,TRUE,TRUE,0);
    //etablir la connection entre le signal et le bouton
    //g_signal_connect(bouton1, "button-press-event", (GCallback)entreprise, liste);
    g_signal_connect(G_OBJECT(bouton1),"clicked",G_CALLBACK(entreprise),liste);
    g_signal_connect(G_OBJECT(bouton2),"clicked",G_CALLBACK(client),liste);
    //etablir la connection entre la le bouton croix et la fonction destry
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(destroy),NULL);
    //affichage de la fenetre 
    gtk_widget_show_all(window);
    /***indisponsable***/
    gtk_main();

    
    return EXIT_SUCCESS;
}
