#ifndef PRODUIT_H_INCLUDED
#define PRODUIT_H_INCLUDED
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

                 } ;
typedef struct Liste Liste;
struct Liste   {
                    Produit *first;
               };
/****initialisation****/
void initialisation(Liste *li);
/****ajout d'un produit****/
//void add_produit(Liste *liste);
void add_produit(Liste *liste);
/****calculer la taille de la liste****/
int taille(Liste *liste);
/****affichage de la liste*****/
void afficher_liste(Liste *liste);
/****afficher le premier element de la liste****/
void delete_first(Liste *liste);
/****suppression d'un element qlq de la liste different du premier****/
void delete_n(Liste *liste);
/***mise a jours****/
void maj(Liste *liste);
/****sauvgarder****/
void sauvgarder(Liste *liste);
/****ajouter au panier****/
void ajouteramonpanier(Liste *liste,int n );
int  premier_menu();
int deuxieme_menu();
int troisieme_menu();
#endif // PRODUIT_H_INCLUDED
