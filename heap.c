#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
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
        // El montículo está lleno, aumenta su capacidad
        pq->capac = pq->capac * 2 + 1;
        pq->heapArray = (heapElem*)realloc(pq->heapArray, sizeof(heapElem) * pq->capac);
        if (pq->heapArray == NULL) {
            printf("Error: No se pudo asignar memoria para la expansión del montículo.\n");
            exit(1);
        }
    }

    // Agregar el nuevo elemento al final del montículo
    int index = pq->size;
    pq->heapArray[index].data = data;
    pq->heapArray[index].priority = priority;
    pq->size++;

    // Reordenamiento para mantener las propiedades del montículo
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (pq->heapArray[index].priority > pq->heapArray[parentIndex].priority) {
            // Intercambiar el elemento actual con su padre
            heapElem temp = pq->heapArray[index];
            pq->heapArray[index] = pq->heapArray[parentIndex];
            pq->heapArray[parentIndex] = temp;
            index = parentIndex;
        } else {
            break;  // La propiedad del montículo está restaurada
        }
    }
}

void heap_pop(Heap* pq){
    if (pq->size <= 0) {
        // El montículo está vacío, no se puede eliminar nada
        printf("El montículo está vacío, no se puede eliminar el elemento de mayor prioridad.\n");
        return;
    }

    // Reemplazar la raíz con el último elemento
    pq->size--;
    pq->heapArray[0] = pq->heapArray[pq->size];

    // Realizar el proceso de "heapify" para mantener las propiedades del montículo
    int index = 0;
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < pq->size && pq->heapArray[leftChild].priority > pq->heapArray[largest].priority) {
            largest = leftChild;
        }

        if (rightChild < pq->size && pq->heapArray[rightChild].priority > pq->heapArray[largest].priority) {
            largest = rightChild;
        }

        if (largest != index) {
            // Intercambiar el elemento actual con el hijo de mayor prioridad
            heapElem temp = pq->heapArray[index];
            pq->heapArray[index] = pq->heapArray[largest];
            pq->heapArray[largest] = temp;
            index = largest;
        } else {
            break;  // La propiedad del montículo está restaurada
        }      
    }
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
