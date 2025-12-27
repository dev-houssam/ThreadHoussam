


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>



typedef struct{
    void (*callback)(void *);
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
} Person;


//Le static nous permet d'initialiser efficacement notre gestionnaire
static ThreadSet * thread_create(void * fun, void *args){
    static ThreadSet manager = {.init=0};
    
    if(fun == NULL && args == NULL && manager.init != 0){
        printf("Start Initialisation threads\n");
        ThreadSet * manager2 = (ThreadSet *) malloc(sizeof(ThreadSet));
        if(NULL == manager2){
            return NULL;
        }
        /*
        char initStr[10] = {0};
        char nbThreadStr[10] = {0};
        sprintf(initStr, "%d", manager.init);
        sprintf(nbThreadStr, "%d", manager.nbThread);
        */
        manager2->init =     manager.init;
        manager2->nbThread = manager.nbThread;
        for(int i = 0; i < manager2->nbThread; i++){
            printf("Init\n");
            //manager.set[i].callback(manager.argumentThread[i]);
            manager2->set[i] = manager.set[i];
            manager2->argumentThread[i] = manager.argumentThread[i];
        }
        manager2->currentThread = manager.nbThread;
        

        return manager2;
    }
    
    
    if(manager.init == 0) {
        manager.init = 1;
        printf("Initialisation\n");
        
        return &manager;
    }else{
        // Ajouter des threads Ici
        manager.set[manager.nbThread].callback = fun;
        manager.argumentThread[manager.nbThread] = args;
        manager.set[manager.nbThread].execution_time = 2; //2s
        manager.nbThread += 1;
        printf("Adding thread : [PID: %d]\n", manager.nbThread);
        return NULL;
    }
}

void init(){
    thread_create(NULL, NULL);
}


void * afficherPerson(void * args){
    Person * personne = (Person *) args;
    printf("Person name : %s \n", personne->nom);
}



//Avec des semaphores pour endormir ce sera parfait : mutex
static void thread_start(){
    ThreadSet * manager = thread_create(NULL, NULL);
    printf("Start thread : nb_%d\n", manager->nbThread);
    int min=0;
    int max=manager->nbThread;
    
    srand(time(NULL)); 

    
    if(manager->nbThread != 0){
        while(manager->currentThread){
            while(manager->set[manager->currentThread-1].execution_time){
                printf("Execution : %d \n", manager->currentThread);
                //Mutex:Lock()
                manager->set[manager->currentThread-1].callback(manager->argumentThread[manager->currentThread-1]);
                printf("Fin Execution ! \n");
                manager->set[manager->currentThread-1].execution_time--;
                //Mutex:UnLock()
                //Le sleep est inutile : juste pour la simulation
                sleep(manager->set[manager->currentThread-1].execution_time);
                
                int changeContext = rand() % (max - min + 1) + min;
                manager->currentThread = changeContext;
                printf("Save context : necessary : no need here \n");
            }
            manager->currentThread -= 1;
        }
    }else{
        printf("No threads available ! \n");
    }
}

void __attribute__((constructor)) init_function() {
    init();
}

void __attribute__((destructor)) cleanup() {
    thread_start();
}

int main()
{
    printf("Hello World in this sequential thread truc !!!\n");
    Person personne1 = {.nom="Stellare"};
    Person personne2 = {.nom="Sam"};
    Person personne3 = {.nom="Rachid"};
    thread_create(&afficherPerson, (void *) &personne1);
    thread_create(&afficherPerson, (void *) &personne2);
    thread_create(&afficherPerson, (void *) &personne3);
    
    
    return 0;
}








