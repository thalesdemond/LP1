#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// void isort(void* vector_, size_t vectorSize, void * aux, size_t elementSize, int (comp)(void*, void*))
// {
//     bool troca = true;
//     char * vector = vector_;
//     while(troca)
//     {
//         troca = false;
//         for(size_t i = 1; i < vectorSize; i++)
//         {
//             if(comp(&vector[(i-1)*elementSize], &vector[(i*elementSize)]) > 0)
//             {
//                 memcpy(aux, &vector[(i-1)*elementSize], elementSize);
//                 memcpy(&vector[(i-1)*elementSize], &vector[(i)*elementSize], elementSize);
//                 memcpy(&vector[(i)*elementSize], aux, elementSize);
//                 troca = true;
//             }
//         }
//     }
// }

void isort(void* vector_, size_t vectorSize, void * aux, size_t elementSize, int (comp)(void*, void*))
{
    char * vector = vector_;
    for(size_t element = 1; element < vectorSize; element++)
    {
        memcpy(aux, &vector[element*elementSize], elementSize);
        size_t indexAux = element;
        while(comp(aux, &vector[(indexAux-1)*elementSize]) < 0)
        {
            puts("1");
            memcpy(&vector[indexAux*elementSize], &vector[(indexAux-1)*elementSize], elementSize);
            if(!--indexAux)
            {
                break;
            }
        }
        puts("2");
        memcpy(&vector[indexAux*elementSize], aux, elementSize);
    }
}

#define length(x)           (sizeof(x)/sizeof(*x))
#define printIntList(a)\
do{\
    for(int i = 0; i < length(a); i++)\
    {\
        if(i)\
        {\
            printf(",");\
        }\
        printf(" %i", a[i]);\
    }\
    printf("\n");\
}while(0)

int intcomp(void* a_, void* b_)
{
    int * a = a_;
    int * b = b_;
    return *a > *b ? 1 : -1;
}

int main(void)
{

    int a[] = {2,4,1,2,3,8,8,7,3,4,5,12,45,112,3,3,123,2315,2534,6136,142,5,3,24,12,4,151,2,34,4,267,77653,1261,77655,34,6342,3,234,5234,674,3};
    int b;
    printIntList(a);
    isort(a, length(a), &b, sizeof(int), intcomp);
    printIntList(a);
}
