#include <iostream>

typedef struct AVL_NODE {
  int data;
  AVL_NODE * less;
  AVL_NODE * large;
  int balance;
}node;

typedef struct AVL_HEAD {
  int count;
  node * root;
}head;

head createAVL() {
  head * h = (head*)malloc(sizeof(head));
  h->root = 0;
  h->count = 0;
  return *h;
}


node * rotateLess(node * root) {
  node * lessSide = root->less;
  root->less = lessSide->large;
  lessSide->large = root;
  return lessSide;
}

node * rotateLarge(node * root) {
  node * largeSide = root->large;
  root->large = largeSide->less;
  largeSide->less = root;
  return largeSide;
}

node * lessBalance(node * root) {
  
  switch(root->less->balance) {
    case(1):
      root->balance = 0;
      root->less->balance = 0;
      root = rotateLess(root);
      
    break;
    case(-1):
      root->balance = 0;
      root->less->balance = 0;
      root->less = rotateLarge(root->less);
      root = rotateLess(root);
    break;
  }
  return root;
}
node * largeBalance(node * root) {
  switch(root->large->balance) {
    case(-1):
      root->balance = 0;
      root->large->balance = 0;
      root = rotateLarge(root);
      
    break;
    case(1):
      root->balance = 0;
      root->large->balance = 0;
      root->large = rotateLess(root->large);
      root = rotateLarge(root);
    break;
  }
  return root;
}

node * findAndPlavl(node * root, node * New) {
  if(root->data > New->data) {
    if(root->less == 0) {
      root->less = New;
      //return root;
    }
    else {
      root->less = findAndPlavl(root->less, New);
    }
    switch(root->balance) {
      case(0):
        root->balance++; // less = +1, large = -1
        break; // less = right = +, left = large = -
      case(-1):
        root->balance++;
      case(1):
        node * temp = lessBalance(root);
        root = temp;
        break;
    }
  }
  if(root->data < New->data) {
    if(root->large == 0) {
      root->large = New;
      ///return root;
    }
    else {
      root->large = findAndPlavl(root->large, New);
    }
    switch(root->balance) {
      case(0):
        root->balance--;
        break;
      case(1):
        root->balance--;
        break;
      case(-1):
        node * temp = largeBalance(root);
        root = temp;
        return root;
        break;
    }
  }
  return root;
}

void insertAVL(head * h, int data) {
  node * n = (node*)malloc(sizeof(node));
  n->balance = 0;
  n->data = data;
  n->less = 0;
  n->large = 0;
  if(h->count == 0) {
    h->root = n;
  }
  else {
    h->root = findAndPlavl(h->root, n);
  }
  h->count++;
}

void traverse(node * n, int count) {
  if(n == 0) {
    return;
  }
  //for(int i = 0; i < count; i++) {
    //printf("  "); // prints it tabulated
  //}
  //printf("%d\n", n->data);
  traverse(n->less, count+1);
  for(int i = 0; i < count; i++) {
    printf("  "); // makes it look like a sideways tree like this
  }
  printf("%d\n", n->data);
  traverse(n->large, count+1);
}

node * findLargest(node * n) {
  if(n->large == 0) {
    return n;
  }
  if(n->large != 0) {
    return findLargest(n->large);
  }
}
// less = right = +, left = large = -
node * deleteRebAVLance(node * n) {
  switch(n->balance) {
    case(1):
      n->balance--;
      break;
    case(0):
      n->balance--;
      break;
    case(-1):
      switch(n->large->balance) {
        case(-1):
          n->less = rotateLess(n->less);
          n = rotateLarge(n);
          break;
        case(1):
          n = rotateLess(n);
          break;
      }
      break;
  }
}

node * searchAndDestravl(node * n, int key) {
  if(n->data > key) {
    n->less = searchAndDestravl(n->less, key);
  }
  if(n->data < key) {
    n->large = searchAndDestravl(n->large, key);
  }
  if(n->data == key) {
    node * delta = n;
    if(n->less == 0) {
      node * undertaker = n->large;
      free(delta);
      return undertaker;
    }
    else if(n->large == 0) {
      node * undertaker = n->less;
      free(delta);
      return undertaker;
    }
    else {
      delta = findLargest(n->less);
      n->data = delta->data;
      n->less = searchAndDestravl(n->less, delta->data);
      
    }
  }
  return n;
}

void DeleteAVL(head * h, int key) {
 
  if(h->count == 1 && h->root->data == key) {
    node * delta = h->root;
    h->root = 0;
    free(delta);
  }
  else {
    node * replac = searchAndDestravl(h->root, key);
  }
  h->count--;
}

int main() {
  head h = createAVL();
  insertAVL(&h, 10);
  insertAVL(&h, 20);
  insertAVL(&h, 5);
  insertAVL(&h, 4);
  insertAVL(&h, 5);
  insertAVL(&h, 3);
  insertAVL(&h, 70);
  insertAVL(&h, 8);
  insertAVL(&h, 37);
  insertAVL(&h, 53);
  puts("----");
  traverse(h.root, 0);
  puts("----");

  DeleteAVL(&h, 37);
  DeleteAVL(&h, 70);
  puts("----");
  traverse(h.root, 0);
  puts("----");
}