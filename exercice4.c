#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define TAILLE_NOM 50


typedef struct etudiant Etudiant ; 

struct etudiant
{
    char nom[TAILLE_NOM] ; 
    int dateNaissance ; 
    Etudiant *Psuiv ; 
};


Etudiant * ajouterChainon(Etudiant *etudiant) ; 


void main(void)
{

    Etudiant * nextEtudiant = NULL ; 
    Etudiant * currentEtudiant ; 

    currentEtudiant = ajouterChainon(currentEtudiant) ; 

    printf("------------------\n") ; 
    printf("nom : %s" , currentEtudiant->nom) ;
    printf("date de naissance: %d" , currentEtudiant->dateNaissance) ;

    free(currentEtudiant) ; 





}

Etudiant  * ajouterChainon(Etudiant *etudiant)
{
    Etudiant * pNouvEtudiant = (Etudiant * )malloc(sizeof(Etudiant)) ; 

    if ( pNouvEtudiant == NULL )
    {
        printf("Erreur lors de l'allocation de la memoire") ; 
        return etudiant ; 
    }
    printf(" nom du nouvel etudiant : ") ; 
    fgets(pNouvEtudiant->nom , sizeof(pNouvEtudiant->nom) , stdin) ; 
    printf("date de naissance : ") ; 
    scanf("%d" , &pNouvEtudiant->dateNaissance) ; 

    
    
    pNouvEtudiant->Psuiv = etudiant;


    return pNouvEtudiant ; 



}