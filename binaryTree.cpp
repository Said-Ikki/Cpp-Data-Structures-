#include <iostream>
#include <iostream>

typedef struct BTNode {
  struct BTNode * left;
  struct BTNode * right;
  int data;
}node;

// -------------------------------
// -----------Queue---------------
// -------------------------------

typedef struct QUEUE_NODE {
  node * data;
  struct QUEUE_NODE * next;
} q_node;

typedef struct QUEUE_HEAD {
  int count;
  q_node * first;
  q_node * last;
} queue;

queue createQueue() {
  queue * q = (queue*)malloc(sizeof(queue));
  q->count = 0;
  q->first = 0;
  q->last = 0;
  return *q;
}

void enqueue(queue * q, node * data) {
  q_node * n = (q_node*)malloc(sizeof(q_node));
  n->data = data;
  n->next = 0;
  if(q->count == 0) {
    q->first = n;
    q->last = n;
  }
  else {
    q->last->next  = n;
    q->last = n;
  }
  q->count++;
}

void dequeue(queue * q) {
  q_node * delta = q->first;
  q->first = q->first->next;
  free(delta);
  q->count--;
}

node * front(queue * q) {
  return q->first->data;
}

node * end(queue * q) {
  return q->last->data;
}
// ------------------------------
// ----------Binary Tree---------
// ------------------------------



typedef struct BTheader {
  int count;
  node * root;
}head;

head createBT() {
  head * h = (head*)malloc( sizeof(head) );
  h->root = 0;
  h->count = 0;
  
  return *h;
}

void horizontalInsertion(node * parent, node * TBI) {
  queue q = createQueue();
  bool inserted = false;
  enqueue(&q, parent);
  while(inserted == false) {
    node * t1 = ((front(&q)))->left;
    node * t2 = ((front(&q)))->right;
    enqueue( &q, t1 );
    enqueue( &q, t2 );
    if( front(&q)->left == 0 ) {
      front(&q)->left = TBI;
      inserted = true;
    }
    else if((front(&q))->right == 0) {
      (front(&q))->right = TBI;
      inserted = true;
    }
    else {
      dequeue(&q);
    }
  }
}

void bread(node * root) {
  queue q = createQueue();
  enqueue(&q, root);
  while(q.count != 0) {
    if(front(&q) != 0) {
      printf("%d, ", front(&q)->data);
    }
    node * t1 = 0;
    node * t2 = 0;
    if( ((front(&q)))->left != 0 ) {
      t1 = ((front(&q)))->left;
      enqueue( &q, t1 );
    }
    if( ((front(&q)))->right != 0 ) {
      t2 = ((front(&q)))->right;
      enqueue( &q, t2 );
    }
    
    dequeue( &q );
  }
}

void insert(head * h, int data) {
  node * n = (node*)malloc(sizeof(node));
  n->data = data; 
  n->left = 0;
  n->right = 0;
  if(h->count == 0) {
    h->root = n;
    h->count++;
    return;
  }
  horizontalInsertion(h->root, n);
  h->count++;
}

void traverse(node * n, int count) {
  if(n == 0) {
    return;
  }
  
  traverse(n->left, count+1);
  for(int i = 0; i < count; i++) {
    printf("  ");
  }
  printf("%d\n", n->data);
  traverse(n->right, count+1);
  
  
}

int main() {
  head h = createBT();
  insert(&h, 1);
  insert(&h, 2);
  insert(&h, 2);
  insert(&h, 3);
  insert(&h, 3);
  insert(&h, 3);
  insert(&h, 3);
  insert(&h, 4);
  insert(&h, 4);
  traverse(h.root, 0);
  puts("");
  bread(h.root);
}