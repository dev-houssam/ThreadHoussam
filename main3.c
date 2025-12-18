


#include <stdio.h>
#include <stdlib.h>


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
static ThreadSet thread_create(void * fun, void *args){
    static ThreadSet manager = {.init=0};
    
    if(fun == NULL && args == NULL && manager.init != 0){
        printf("Start Initialisation threads\n");
        char initStr[10] = {0};
        char nbThreadStr[10] = {0};
        sprintf(initStr, "%d", manager.init);
        sprintf(nbThreadStr, "%d", manager.nbThread);
        ThreadSet manager2;
        manager2.init =     atoi(initStr);
        manager2.nbThread = atoi(nbThreadStr);
        return manager2;
    }
    
    
    if(manager.init == 0) {
        manager.init = 1;
        printf("Initialisation\n");
        
        return manager;
    }else{
        // Ajouter des threads Ici
        manager.set[manager.nbThread].callback = fun;
        manager.set[manager.nbThread].execution_time = 10; //10ms
        manager.nbThread += 1;
        printf("Ajout de thread : [PID: %d]\n", manager.nbThread);
    }
}

void init(){
    thread_create(NULL, NULL);
}


void * afficherPersonne(void * args){
    Personne * personne = (Personne *) args;
    printf("Nom de la personne : %s \n", personne->nom);
}

static void thread_start(){
    printf("Lancement thread : n_");

    ThreadSet manager = thread_create(NULL, NULL);
    printf("Lancement thread : n_%d", manager.nbThread);
    if(manager.nbThread != 0){
        while(manager.nbThread){
            while(1){
                manager.set[manager.nbThread].callback(manager.argumentThread[manager.nbThread]);
            }
            manager.nbThread -= 1;
        }
    }
    printf("Aucun thread dispo ! \n");
}

int main()
{
    init();
    printf("Hello World\n");
    Personne personne = {.nom="Houssam"};
    thread_create(afficherPersonne, (void *) &personne);
    thread_create(afficherPersonne, (void *) &personne);

    thread_start();
    
    return 0;
}









