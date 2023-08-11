#include <iostream>

typedef struct queue {
  void** queueArray;
  int maxSize;
  int count;
  int front;
  int rear;
}circ;

circ * createQueue(int size) {
  circ * q = (circ*)malloc( sizeof(circ) ); // the structure
  q->queueArray = (void**)malloc( size * sizeof(void*) );
  // the queue, an array of void pointers pointed to by a void pointer
  q->maxSize = size; // max size it can allow is passed in
  q->count = 0; // nothing in it
  q->front = 0; // points to first element, there is none
  q->rear = 0; // no last either

  return q;
}

void enqueue(circ * q, void * data) {

  if(q->count == 0) {
    q->front++;
  }
  
  if(q->count != q->maxSize) {
    q->rear++;
    if(q->rear > q->maxSize) {
      q->rear = 0;
    }
    //printf("data : %d\n", *(int*)data);
    q->queueArray[q->rear] = data;
    q->count++;
    //printf("queue : %d\n", *(int*)q->queueArray[q->rear]);
  }
}

void dequeue(circ * q) {
  void* delet = q->queueArray[q->front];
  q->front++;
  if(q->front == q->maxSize) {
    q->front = 0;
  }
  q->count--;
}



void* front(circ * q) {
  return (q->queueArray[q->front]);
}
void* rear(circ * q) {
  return q->queueArray[q->rear];
}

void destroyQueue(circ * q) {
  while(q->count > 1) {
    printf("Front  : %d\n", *(int*)front(q));
    dequeue(q);
  }
}
int main() {
  std::cout << "Hello World!\n";

  int size = 10;
  circ q = *createQueue(size);
  int v1[10];
  for(int i = 0; i < 10; i++) {
    v1[i] = i * 2;
    enqueue(&q, &v1[i]);
    printf("Rear  : %d\n", *(int*)rear(&q) );
  }
  
  for(int i = 0; i < 5; i++) {
    v1[i] = i * 15;
    dequeue(&q);
    enqueue(&q, &v1[i]);
    printf("Rear  : %d\n", *(int*)rear(&q) );
  }
  printf("size  : %d\n", q.count);
}