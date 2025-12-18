

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

typedef struct{
    void (*callback)();
    int execution_time;
} Thread;

typedef struct{
    Thread set[10];
    int nbThread;
    int currentThread;
    int contextThread[10];
    void * argumentThread[10];
    int init;
} ThreadSet;


typedef struct{
    char nom[32];
} Personne;


//Le static nous permet d'initialiser efficacement notre gestionnaire
static void thread_create(void * fun, void *args){
    static ThreadSet manager = {.init=0};
    
    if(manager.init == 0) {
        manager.init = 1;
        printf("Initialisation\n");
        
        return;
    }else{
        // Ajouter des threads Ici
    }
}

void init(){
    thread_create(NULL, NULL);
}


void * afficherPersonne(void * args){
    Personne * personne = (Personne *) args;
    printf("Nom de la personne : %s \n", personne->nom);
}



int main()
{
    init();
    printf("Hello World");
    init();
    Personne personne = {.nom="Houssam"};
    thread_create( afficherPersonne, (void *) &personne);

    return 0;
}









