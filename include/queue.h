#ifndef QUEUE_H  
#define QUEUE_H  

#ifdef __cplusplus  
extern "C" {  
#endif  

typedef struct {  
    int front, rear, size;  
    int capacity;  
    int* array;  
} Queue;  

Queue queue_create(int capacity);  
int queue_enqueue(Queue* queue, int item);  
int queue_dequeue(Queue* queue, int* item);  
// int queue_is_empty(Queue* queue);  
// int queue_peek(Queue* queue, int* item);  
void queue_free(Queue* queue);  

#ifdef __cplusplus  
}  
#endif  

#endif