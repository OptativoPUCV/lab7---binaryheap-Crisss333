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
    if (pq->size <= 0) {
        printf("El montículo está vacío, no se puede obtener el elemento de mayor prioridad.\n");
        return NULL;
    }
    // El elemento de mayor prioridad está en la raíz (primera casilla)
    return pq->heapArray[0].data;    
}



void heap_push(Heap* pq, void* data, int priority){
    if (pq->size >= pq->capac) {
        // Aumentar la capacidad del montículo al doble más uno
        int nueva_capacidad = pq->capac * 2 + 1;
        pq->heapArray = (heapElem*)realloc(pq->heapArray, sizeof(heapElem) * nueva_capacidad);
        if (pq->heapArray == NULL) {
            printf("Error: No se pudo aumentar la capacidad del montículo.\n");
            exit(1);  // Terminar el programa si no se puede asignar memoria
        }
        pq->capac = nueva_capacidad;
    }

    // Insertar el nuevo elemento en la última posición del arreglo
    int currentIndex = pq->size;
    pq->heapArray[currentIndex].data = data;
    pq->heapArray[currentIndex].priority = priority;
    pq->size++;

    // Reorganizar el montículo para mantener la propiedad de montículo min
    while (currentIndex > 0) {
        int parentIndex = (currentIndex - 1) / 2;
        if (pq->heapArray[currentIndex].priority < pq->heapArray[parentIndex].priority) {
            // Intercambiar el elemento con su padre si su prioridad es menor
            heapElem temp = pq->heapArray[currentIndex];
            pq->heapArray[currentIndex] = pq->heapArray[parentIndex];
            pq->heapArray[parentIndex] = temp;
            currentIndex = parentIndex;
        } else {
            break;  // El elemento está en la posición correcta
        } 
    } 
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    if (heap == NULL) {
        printf("Error: No se pudo asignar memoria para el montículo.\n");
        exit(1);  // Terminar el programa si no se puede asignar memoria
    }

    heap->capac = 3;  // Capacidad inicial de 3 casillas
    heap->size = 0;      // El montículo está vacío al principio
    heap->heapArray = (heapElem*)malloc(sizeof(heapElem) * heap->capac);

    if (heap->heapArray == NULL) {
        printf("Error: No se pudo asignar memoria para el arreglo de elementos del montículo.\n");
        exit(1);  // Terminar el programa si no se puede asignar memoria
    }
    
    return heap;
}
