#include <stdio.h>
#include <stdbool.h>

#define TAILLE_NOM 100 
#define NB_CASES 9 

typedef struct objet Objet ; 
typedef struct pileObjet PileObjet ;
typedef struct inventaire Inventaire ;

struct objet 
{
    int identifiant ; 
    char nom[TAILLE_NOM] ;
    int poids ; 
    
} ; 

struct pileObjet 
{
    Objet objet ; 
    int quantite ; 
    
} ; 

struct inventaire
{
    PileObjet cases[NB_CASES] ;
    
} ; 


int indiceObjet(Inventaire inventaire1 , int reference , int nbObjets) ; 
void afficheInventaire(Inventaire inventaire) ;
PileObjet pileObtenue(Objet objetsDisponibles[], int nbObjets) ;
Inventaire invMiseAJour(Inventaire *inventaire, PileObjet pileObjet) ; 

char choixObtenu() ; 




int main()
{
    Objet objets[] = {
                    { 117, "arc", 1000 },
                    { 135, "epee courte", 1000 },
                    { 57, "fleche", 25 },
                    { 10, "torche", 500 },
                    { 215, "pelle", 4000 },
                    { 202, "grappin", 2000 },
                    { 194, "seau", 1000 }
                   } ;
                   
    Inventaire inventaire = {0} ; 

    FILE *fluxInv = fopen("inventaire.dat" , "a") ;

    if ( fluxInv == NULL )
    {
        printf("Erreur lors de l'ouverture du fichier\n") ; 
        return 1 ; 
    }


    

    

    fclose(fluxInv) ; 

                                 
    return 0;
}



int indiceObjet(Inventaire inventaire , int reference , int nbObjets)
{
    bool indiceTrouve ; 
    int indice ; 
    for ( int i = 0 ; i < nbObjets ; i++  )
    {
        if ( inventaire.cases[i].objet.identifiant == reference )
        {
            indice = i ; 
            indiceTrouve = true ; 
            break ; 
        }
    }
    
    if ( indiceTrouve )
    {
        return indice ; 
    }
    else
    {
        return -1 ; 
    }
    
    
}

void afficheInventaire(Inventaire inventaire)
{
    int totalPoids = 0 ; 
    for ( int i = 0 ; i < 4 ; i++) 
    {
        printf("%d x %s\n" , inventaire.cases[i].quantite ,inventaire.cases[i].objet.nom ) ; 
        totalPoids += inventaire.cases[i].objet.poids*inventaire.cases[i].quantite ; 
    }
    printf("total poids : %d" , totalPoids) ;
}

Inventaire invMiseAJour(Inventaire *inventaire, PileObjet pileObjet) {
    for (int i = 0; i < NB_CASES; i++) {
        if (inventaire->cases[i].objet.identifiant == pileObjet.objet.identifiant) {
            inventaire->cases[i].quantite += pileObjet.quantite;
            printf("Objet ajouté\n");
            return *inventaire;  
        }
    }
    for (int i = 0; i < NB_CASES; i++) {
        if (inventaire->cases[i].objet.identifiant == 0) {
            inventaire->cases[i] = pileObjet;
            printf("Objet ajouté\n");
            return *inventaire; 
        }
    }
 
    printf("Inventaire plein\n");
    return *inventaire; 
}

char choixObtenu() {
    char choix;
    printf("Menu :\n"
           "- C : charger l'inventaire\n"
           "- A : ajouter des elements\n"
           "- I : afficher l'inventaire\n"
           "- S : sauver l'inventaire\n"
           "- Q : quitter\n"
           ">>> choix : ");
    scanf(" %c", &choix); // Notez l'espace avant %c pour gérer les '\n'
    
    while (choix != 'Q' &&
           choix != 'A' &&
           choix != 'I' &&
           choix != 'C' &&
           choix != 'S') {
        printf("Choix impossible\n>>> choix : ");
        scanf(" %c", &choix); // Encore, l'espace avant %c
    }
    return choix;
}


void sauverInventaire( Inventaire inventaire , FILE *fluxInv , int taille )
{
    
    for ( int i = 0 ; i < taille ; i++ )
    {
        fprintf( fluxInv ,"case : %d\n nom : %s\n identifiant %d \n poids : %lf\n quantite : %d\n   ", 
        inventaire.cases[i] , inventaire.cases[i].objet.nom , inventaire.cases[i].objet.identifiant , 
        inventaire.cases[i].objet.poids, inventaire.cases[i].quantite ) ; 
    }
}
