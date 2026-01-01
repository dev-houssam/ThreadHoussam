#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>

//64 bits * 500

#define SIZE_CLASS 500


typedef struct {
    void ** dataclass; // Method + attribut
    char * name;
} Class;


uint64_t monTest(){
    printf("Salut !!!\n");

    return 0;
}

uint64_t monTest2(){
    printf("HAHAHAHAHAHAHAHA !!!\n");

    return 0;
}

Class * createClass(const char * className){
    Class * _class_ = (Class *) malloc(sizeof(Class));
    assert(_class_ != NULL && "NULL");
    _class_->dataclass = (uint64_t **) malloc(sizeof(uint64_t*) * SIZE_CLASS);
    assert(_class_->dataclass != NULL && "NULL");
    _class_->name = (char *) malloc(sizeof(char) * strlen(className));
    assert(_class_->name != NULL && ":NULL:");
    memset(_class_->dataclass, NULL, SIZE_CLASS);
    
    //_class_->dataclass[0] = (uint64_t* (*)()) &monTest;
    //_class_->dataclass = 1 + _class_->dataclass;
    
    //_class_->dataclass[1] = (uint64_t* (*)()) &monTest2;
    
    return _class_;
}

#define exec(A, B) uint64_t * (*B)(void);\
    B = A;\
    B();

int main()
{
    printf("Hello World Class !!!\n");
    
    Class * class = createClass("Chat");
    /*
    *((uint64_t *) class->dataclass);
    
    printf("%p == %p\n", &monTest, class->dataclass );
    
    (*(&monTest))();
    
    printf("===========\n");
    
    uint64_t * ptr = class->dataclass;
    exec(class->dataclass, ptr3);
    
    exec(class->dataclass, ptr4);
    exec(class->dataclass, ptr5);
    exec(class->dataclass, ptr6);*/
    //(uint64_t * (*ptr2) * class->dataclass);
    //(*((uint64_t*) class->dataclass))();
    
    return 0;
}







