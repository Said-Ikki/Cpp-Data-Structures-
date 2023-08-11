#include <iostream>

typedef struct variable {
  float coeff;
  float power;
} var;

typedef struct n {
  var data;
  struct n * next;
} node;

typedef struct h {
  int count;
  node * first;
} head;

head createList() {
  head * h = (head*)malloc( sizeof(head) );
  h->count = 0;
  h->first = 0;
  return *h;
}
/*
node * location(head * h, var val) {
  node * t = h->first;
  while(t->next != 0 || 
    t->next->data.power > val.power) {
    t = t->next;
  }
  return t;
}

void insert(head * h, var data) {
  node * n = (node*)malloc( sizeof(node) );
  n->data = data;
  if(h->count == 0) {
    h->first = n;
    n->next = 0;
  }
  else {
    //node * store = location(h, data);
    n->next = store->next;
    store->next = n;
  }
  h->count++;
}
*/
void insert(head * h, var data) {
  node * n = (node*)malloc( sizeof(node) );
  n->data = data;
  n->next = h->first;
  h->first = n;
  h->count++;
}

node * findPos(node * n, var data) {
  if(n->next == 0) {
    return n;
  }
  if(n->next->data.power > data.power) {
    return findPos(n->next, data);
  }
  else if(n->next->data.power <= data.power) {
    return n;
  }
}

void Insort(head * h, var data) {
  node * n = (node*)malloc( sizeof(node) );
  n->data = data;
  if(h->count == 0 || h->first->data.power < data.power) {
    n->data = data;
    n->next = h->first;
    h->first = n;  
  }
  else {
    node * temp = findPos(h->first, data);
    n->next = temp->next;
    temp->next = n;
  }


  h->count++;
}

void traverse(node * n) {

  if(n->data.coeff != 0) {
    
    if(n->data.power != 0) {
      if(n->data.power != 1) {
         printf("%.0fx^%.0f", n->data.coeff, n->data.power);
      }
      else {
        printf("%.0fx", n->data.coeff);
      }
    }
    else {
      printf("%.0f", n->data.coeff);
    }
  }
  else {
    printf("0");
  }
  
  if(n->next != 0) {
    
    printf(" + ");
    traverse(n->next);
  }
}

void derivative(node * n) {
  n->data.coeff = n->data.coeff * n->data.power;
  n->data.power--;
  if(n->next != 0) {
    derivative(n->next);
  }
}

void derive(head * h) {
  derivative(h->first);
}

void antiderivative(node * n) {
  n->data.power++;
  n->data.coeff = n->data.coeff / n->data.power;
  if(n->data.power == 0) {
    n->data.coeff = 1;
  }
  if(n->next != 0) {
    antiderivative(n->next);
  }
}

void integrate(head * h) {
  antiderivative(h->first);
}

int main() {
  head h = createList();
  Insort(&h, {5, 2});
  Insort(&h, {3, 1});
  Insort(&h, {8, 3});
  Insort(&h, {2, 0});
  Insort(&h, {78, 15});
//insert(&h, {coeff, power} );
  //insert(&h, {5,     2} );
  //insert(&h, {4,     1} );
  //insert(&h, {1,     0} );
  //insert(&h, {3,     3} );
  traverse(h.first);
  derive(&h);
  printf("\n\nDerivative\n");
  traverse(h.first);
  integrate(&h);
  printf("\n\nIntegral\n");
  traverse(h.first);
}