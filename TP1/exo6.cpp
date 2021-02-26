#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
    // your code
};

struct DynaTableau{
    //int* donnees;
    int size;
    int donnees[10];
    // your code
};


Liste *initialise()
{
    Liste *liste = (Liste*)malloc(sizeof(Liste));
    Noeud *noeud= (Noeud*)malloc(sizeof(Noeud));
    noeud->donnee = 0;
    noeud->suivant = NULL;
    liste->premier = noeud;

    return liste;
}

bool est_vide(const Liste* liste)
{
    if(liste==NULL){
        return true;
    }   
    return false;
}

void affiche(Liste* liste)
{
    if(liste == NULL){
        cout << "liste vide fonction affiche()" << endl;
        exit(1);
    }
    Noeud *current = liste->premier;
    if(current == NULL){cout << "le suivant est NULL"<<endl;}
    while (current!=NULL) {
         cout<< current->donnee <<"\n";
         current=current->suivant;
    }
}

void ajoute(Liste* liste, int valeur)
{
    Noeud *newNoeud = (Noeud*)malloc(sizeof(Noeud));
    if (liste == NULL || newNoeud == NULL)
    {
        cout << "not enough memory" << endl;
        exit(1);
    }
    newNoeud->donnee = valeur;
    newNoeud->suivant = liste->premier;
    liste->premier = newNoeud;
}


int recupere(const Liste* liste, int n)
{
    if(liste == NULL){
        cout << "liste vide fonction recupere()" << endl;
        exit(1);
    }
    Noeud *current = liste->premier;
    for (int i = 0; i < n && current !=0; ++i)
    {
        current = current->suivant;
    }
    return current->donnee;
    return 0;
}

int cherche(const Liste* liste, int valeur)
{
    if(liste == NULL){
        cout << "liste vide fonction cherche()" << endl;
        exit(1);
    }
    Noeud *current = liste->premier;
    int index = 0;
    while(current!=NULL){
        if(current->donnee == valeur){
            return index+1;
        }
        current=current->suivant;
        index++;
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{
    if(liste == NULL){
        cout << "liste vide fonction stocke()" << endl;
        exit(1);
    }
    Noeud *current = liste->premier;
    for (int i = 0; i < n && current !=0; ++i)
    {
        current = current->suivant;
    }
    current->donnee=valeur;
}

void ajoute(DynaTableau* tableau, int valeur)
{
    //int *current=tableau->donnees;
    if(tableau->size<10){
        tableau->donnees[tableau->size]=valeur;
        tableau->size++;
    }
    else{
        cout << "tableau rempli"<<endl;
        exit(1);
    }
}


void initialise(DynaTableau* tableau, int capacite)
{
    tableau = (DynaTableau*)malloc(sizeof(DynaTableau));
    tableau->size = 0;
}

bool est_vide(const DynaTableau* tableau)
{
    if(tableau==NULL){
        return true;
    }
    return false;
}

void affiche(const DynaTableau* tableau)
{
    int compteur = 0;
    for (int i = 0; i < tableau->size; ++i)
    {
        cout << tableau->donnees[i] << endl;
    }
    
}

int recupere(const DynaTableau* tableau, int n)
{
    if(n<=tableau->size){
        return tableau->donnees[n];
    }
    return 0;
}

int cherche(const DynaTableau* tableau, int valeur)
{
    int compteur =0;
    while(compteur<=tableau->size){
        if(tableau->donnees[compteur]==valeur){
            return compteur+1;
        }
        compteur++;
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    if(n<=tableau->size){
        tableau->donnees[n]=valeur;
    }
}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{
    Noeud *current = liste->premier;
    Noeud *nouveau =(Noeud*)malloc(sizeof(Noeud));
    nouveau->donnee=valeur;
    nouveau->suivant=NULL;
    while(current->suivant!=NULL){
        current=current->suivant;
    }
    current->suivant=nouveau;
}

//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    if(liste !=NULL){
        if(liste->premier !=0){
            Noeud *first = liste->premier;
            liste->premier=liste->premier->suivant;
            return first->donnee;
        }
    }
        return 0;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{
    //même que la fonction ajoute pour les listes 
    Noeud *newNoeud = (Noeud*)malloc(sizeof(Noeud));
    if (liste == NULL || newNoeud == NULL)
    {
        cout << "not enough memory" << endl;
        exit(1);
    }
    newNoeud->donnee = valeur;
    newNoeud->suivant = liste->premier;
    liste->premier = newNoeud;  
}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
    Noeud *current = liste->premier;
    while(current->suivant->suivant!=NULL){
        current=current->suivant;
    }
    int last = current->suivant->donnee;
    free(current->suivant);
    return last;
}


int main()
{
    Liste *liste = initialise();
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (est_vide(liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(liste, i*7);
        ajoute(&tableau, i*5);
    }
    if (est_vide(liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    cout << "Elements initiaux de la liste :" << endl;
    affiche(liste);
    cout << "Elements initiaux du DynaTableau :" << endl;
    affiche(&tableau);
    cout << endl;

    std::cout << "5e valeur de la liste " << recupere(liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à la position " << cherche(liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à la position " << cherche(&tableau, 15) << std::endl;

    stocke(liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7 dans la liste :" << std::endl;
    affiche(liste);
    std::cout << "Elements après stockage de 7 dans le DynaTableau :" << std::endl;
    affiche(&tableau);
    std::cout << std::endl;

    Liste *pile; // DynaTableau pile;
    Liste *file; // DynaTableau file;

    pile = initialise();
    file = initialise();

    for (int i=1; i<=7; i++) {
        pousse_file(file, i);
        pousse_pile(pile, i);
    }
    cout << "affichage de la file : "<<endl;
    affiche(file);
    cout << "affichage de la pile : "<<endl;
    affiche(pile);
    int compteur = 7;
    while(!est_vide(file) && compteur > 0)
    {
        cout << endl;
        std::cout << retire_file(file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis avec la file là ..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(pile) && compteur > 0)
    {
        std::cout << retire_pile(pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis avec la pile là..." << std::endl;
    }
    
    return 0;
}
