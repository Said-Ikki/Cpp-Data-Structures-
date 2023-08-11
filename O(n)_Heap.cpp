#include <iostream>

void printHeap(int heap[], int size) {
  for(int i = 0; i < size - 1; i++) {
    printf("%d, ", heap[i]);
  }
  printf("%d\n\n", heap[size-1]);
}

void siftDown( int * heap, int size, int i ) {
  int left  = 2 * i + 1;
  int right = 2 * i + 2;
  int large = i;
  if(left < size && heap[left] > heap[right]) {
    large = left;
  }
  if(right < size && heap[right] > heap[left]) {
    large = right;
  }
  if(heap[large] > heap[i] && large != i) {
    int t = heap[i];
    heap[i] = heap[large];
    heap[large] = t;
    printf("%d %d\n", size, heap[large]);
    siftDown(heap, size, large);
  }
}

void buildHeap(int heap[], int size) {
  int reheapFrom = size/2 - 1;
  
  for(int i = reheapFrom; i >= 0; i--) {
    siftDown(heap, size, i);
  }
  printHeap(heap, size);
}



int main() {
  int values[] = {5, 10, 30, 20, 35, 40, 15};
  buildHeap(values, 7);
  
}