#include <iostream>


typedef struct node {
  node* link;
  void* data;
} node;

typedef struct queue {
  node* top;
  node* bottom;
  int count;
} queue;

queue createQueue() {
  queue* q = (queue*)malloc( sizeof(queue) );
  q->count = 0;
  q->top = 0;
  q->bottom = 0;
  return *q;
}

void enqueue(queue* queue, void* data) {
  node* firstOut = (node*)malloc( sizeof(node) );
  firstOut->data = data;
  

  if(queue->count == 0) {
    queue->top = firstOut;
    queue->bottom = firstOut;
  }
  else if (queue->count > 0) {
    // queue->bottom->link = firstOut;

    queue->top->link = firstOut;
    //queue->bottom->link = queue->top->link;
    
    queue->top = firstOut; // keep as is
  }
  queue->count++;
}

void dequeue(queue* q) {
  void* freeUp = q->bottom;
  
  if(q->count > 1) {
    q->bottom = q->bottom->link;
  }
  else if(q->count == 1) {
    q->bottom = 0;
    q->top = 0;
  }
  q->count--;
  free(freeUp);
}


bool emptyQueue(queue* q) {
  return !(q->count == 0);
}

void* lastInLine(queue* q) {
  return q->top->data;
}
void* firstInLine(queue* q) {
  return q->bottom->data;
}

int main() {
  int data[] = {1, 2, 3, 4, 5};
  queue q = createQueue();

  puts("\nEnqueue\n");
  for(int i = 0; i < 5; i++) {
    enqueue(&q, &data[i]);
    printf("First : %d\n", *(int*)firstInLine(&q));
    printf("Last  : %d\n", *(int*)lastInLine(&q));
  }
  puts("\nDequeue\n");
  for(int i = 0; i < 4; i++) {
    dequeue(&q);
    printf("First : %d\n", *(int*)firstInLine(&q));
    printf("Last  : %d\n", *(int*)lastInLine(&q));
  }
}