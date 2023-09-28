#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    if (heap == NULL) {
        printf("Error: No se pudo asignar memoria para el montículo.\n");
        exit(1);  // Terminar el programa si no se puede asignar memoria
    }

    heap->capacity = 3;  // Capacidad inicial de 3 casillas
    heap->size = 0;      // El montículo está vacío al principio
    heap->heapArray = (heapElem*)malloc(sizeof(heapElem) * heap->capacity);
    
    return heap;
}
