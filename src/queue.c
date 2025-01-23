#include "queue.h"  
#include <stdlib.h>  

Queue queue_create(int capacity) {  
    Queue queue;  
    queue.size = 0;  
    queue.front = 0;  
    queue.rear = capacity - 1;
    queue.capacity = capacity;  
    queue.array = (int*) malloc(queue.capacity * sizeof(int));
    if (!queue.array) {  
        // Handle memory allocation failure  
        queue.capacity = 0;  
        return queue;
    }   
    return queue;  
}  

int queue_enqueue(Queue* queue, int item) {  
    if (queue->size == queue->capacity) {  
        return 0; 
    }  
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;  
    queue->size++;  
    return 1; 
}  
 
int queue_dequeue(Queue* queue, int* item) {  
    if (queue->size == 0) {  
        return 0;
    }  
    if (item) {  
        *item = queue->array[queue->front];  
    }  
    queue->front = (queue->front + 1) % queue->capacity;  
    queue->size--;  
    return 1;
}  

void queue_free(Queue* queue) {  
    free(queue->array);  
    queue->array = NULL; 
}