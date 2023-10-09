#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <fstream>

void heapify(int * array, int i, int size) {
	int left = 2 * i + 1;
	int right = 2 * (i + 1);
	int largest = i;
	if (left < size && array[left] > array[largest]) {
		largest = left;
	}
	if (right < size && array[right] > array[largest]) {
		largest = right;
	}
	if (largest != i && array[largest] > array[i] ) {
		int t = array[largest];
		array[largest] = array[i];
		array[i] = t;
		heapify(array, largest, size);
	}
  
}

void heapSort(int array[], int size) {
	int i = (size / 2) - 1;
	for (; i >= 0; i--) {
		heapify(array, i, size);
	}
  
	for (int x = size-1; x >= 0; x-- ) {
		int t = array[x];
		array[x] = array[0];
		array[0] = t;
		heapify(array, 0, x);
	}
}


void selectionSort(int array[], int size) {
	for (int step = 0; step < size - 1; step++) {
		int min_idx = step;
		for (int i = step + 1; i < size; i++) {

			// To sort in descending order, change > to < in this line.
			// Select the minimum element in each loop.
			if (array[i] < array[min_idx])
				min_idx = i;
		}

		// put min at the correct position
		int x = array[min_idx];
		array[min_idx] = array[step];
		array[step] = x;
	}
}

void insertionSort(int array[], int size) {
  int index = 1;
  while(index < size) {
    int t = array[index];
    int i = index - 1;
    for(;i >= 0 && t < array[i]; i--) {
      array[i+1] = array[i]; 
    }
    array[i+1] = t;
    index++;
  }
}

void shellSort(int array[], int size) {
  for(int inc = size / 2; inc > 0; inc = inc / 2) {

    for(int i = inc; i < size; i++) {
      int t = array[i];
      int j = i;
      
      for(j = i; j >= inc 
      && array[j - inc] > t;
      j -= inc) {
        array[j] = array[j - inc];
      }
      
      array[j] = t;
    }
    
  }
}

void bubbleSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < i; k++) {
			if (array[k] > array[i]) {
				int t = array[k];
				array[k] = array[i];
				array[i] = t;
			}
		}
	}
}


int partisan(int array[], int start, int end) {
  int pivot = array[end]; 
  int index = start - 1; 
  for(int i = start; i < end; i++) { 
    if(array[i] < pivot) { 
      index++; 
      int t = array[index];
      array[index] = array[i];
      array[i] = t;
    }
  }
  int t = array[index + 1];
  array[index + 1] = array[end];
  array[end] = t;
  return index + 1;
}

void quickSort(int array[], int top, int bottom) {
  if(top < bottom) {
    int pivot = partisan(array, top, bottom); // find a partition
    quickSort(array, top, pivot - 1); // quicksort top half
    quickSort(array, pivot + 1, bottom); // quicksort bottom half
  }
  
}

void merge(int array[], int start, int end) {
  
  int m = (end-start)/2 + start;
  int s1 = m - start + 1;
  int s2 = end - m;
  
  int A[s1];
  int B[s2];
  for (int i = 0; i < s1; i++) {
    A[i] = array[start + i];
  }  
  for (int i = 0; i < s2; i++) {
    B[i] = array[m + 1 + i];
  }
  int indexA = 0;
  int indexB = 0;
  int walker = start;
  while(indexA < s1 && indexB < s2) {
    if(A[indexA] <= B[indexB]) {
      array[walker] = A[indexA];
      indexA++;
    }
    else {
      array[walker] = B[indexB];
      indexB++;
    }
    walker++;
  }
  while(indexA < s1) {
    array[walker] = A[indexA];
    indexA++;
    walker++;
  }
  while(indexB < s2) {
    array[walker] = B[indexB];
    indexB++;
    walker++;
  }
}

void mergeSort(int array[], int start, int end) {
  if(start < end) {
    int mid = ( end - start ) / 2 + start;
    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, end);
    merge(array, start, end);
  }
}


void parray(int arry[], int size) {
  for (int i = 0; i < size; i++) {
		printf("%d, ", arry[i]);
	}
  puts("");
}

int main() {
	
	
	int sec = 0;
  bool end = false;
  int s = 1;

  int sortThis[] =  {301, 321, 487, 
    402, 114, 492, 
    299, 142, 179, 
    384, 352, 388, 
    302, 333, 95, 
    270, 378, 311, 
    448, 197, 374, 
    319, 263, 275, 
    46, 436, 282, 
    403, 87, 380, 
    43, 267, 494, 
    281, 168, 370};
  
printf("\nMerge Sort\n");
  mergeSort(sortThis, 0, 36);
  for(int i = 0; i < 36; i++) {
    printf("%d \n", sortThis[i]);
    
  }
  
while(end == false) {
    
  
  
	std::cout << "Enter Array Size\nEnter a Negative Number to End\n";
	
	std::cin >> s;
  if(s < 0) {
    end = true;
    break;
  }
	int* arr1 = (int*)malloc( s * sizeof(int) );
	int* arr2 = (int*)malloc(s * sizeof(int));
	int* arr3 = (int*)malloc(s * sizeof(int));
	int* arr4 = (int*)malloc(s * sizeof(int));
	int* arr5 = (int*)malloc(s * sizeof(int));
	int* arr6 = (int*)malloc(s * sizeof(int));
	int* arr7 = (int*)malloc(s * sizeof(int));
	for (int i = 0; i < s; i++) {
		arr1[i] = rand() % 100;
		arr2[i] = rand() % 100;
		arr3[i] = rand() % 100;
		arr4[i] = rand() % 100;
		arr5[i] = rand() % 100;
		arr6[i] = rand() % 100;
		arr7[i] = rand() % 100;
	}
	//printf("Unsorted\n");
	//for (int i = 0; i < s; i++) {
	//	printf("%d, ", arr1[i]);
	//}
	printf("n = %d \n\n", s);

	printf("Select Sort\n");
	auto start = std::chrono::steady_clock::now();
	selectionSort(arr1, s);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double>  time = end - start;
	printf("Time(s) : %lf\n", time);
	//for (int i = 0; i < s; i++) {
		//printf("%d, ", arr1[i]);
	//}

  start = std::chrono::steady_clock::now();
	heapSort(arr2, s);
  end = std::chrono::steady_clock::now();
  std::chrono::duration<double>  time1 = end - start;
	printf("\nHeap Sort\n");
  printf("Time(s) : %lf\n", time1);

  printf("\nInsertion Sort\n");
  start = std::chrono::steady_clock::now();
  insertionSort(arr3, s);
  end = std::chrono::steady_clock::now();
  std::chrono::duration<double>  time2 = end - start;
  printf("Time(s) : %lf\n", time2);
  
  printf("\nShell Sort\n");
  start = std::chrono::steady_clock::now();
  shellSort(arr4, s);
  end = std::chrono::steady_clock::now();
  std::chrono::duration<double>  time3 = end - start;
  printf("Time(s) : %lf\n", time3);

  printf("\nQuick Sort\n");
  start = std::chrono::steady_clock::now();
  quickSort(arr5, 0, s);
  end = std::chrono::steady_clock::now();
  std::chrono::duration<double>  time4 = end - start;
  printf("Time(s) : %lf\n", time4);

  printf("\nMerge Sort\n");
  start = std::chrono::steady_clock::now();
  mergeSort(arr6, 0, s);
  end = std::chrono::steady_clock::now();
  std::chrono::duration<double>  time5 = end - start;
  printf("Time(s) : %lf\n", time5);

  printf("\nBubble Sort\n");
  start = std::chrono::steady_clock::now();
  bubbleSort(arr7, s);
  end = std::chrono::steady_clock::now();
  std::chrono::duration<double>  time6 = end - start;
  printf("Time(s) : %lf\n\n", time6);

  //char results[600] = ;
  
  std::ofstream MyFile("results.txt", std::ios::in | std::ios::out | std::ios::ate);

  double t  = (double)time.count();
  double t1 = (double)time1.count();
  double t2 = (double)time2.count();
  double t3 = (double)time3.count();
  double t4 = (double)time4.count();
  double t5 = (double)time5.count();
  double t6 = (double)time6.count();

  std::cout << "\nn = " << s << std::endl <<
"==================================" 
    << std::endl <<
    "Select    | " << t  << std::endl <<
    "Heap      | " << t1 << std::endl <<
    "Insertion | " << t2 << std::endl <<
    "Shell     | " << t3 << std::endl <<
    "Quick     | " << t4 << std::endl <<
    "Merge     | " << t5 << std::endl <<
    "Bubble    | " << t6 << std::endl << "==================================" 
    << std::endl;
  
  MyFile << "n = " << s << std::endl <<
"==================================" 
    << std::endl <<
    "Algorithm | Time(s)" << std::endl <<
"----------------------------------\n" <<
    "Select    | " << t  << std::endl <<
    "Heap      | " << t1 << std::endl <<
    "Insertion | " << t2 << std::endl <<
    "Shell     | " << t3 << std::endl <<
    "Quick     | " << t4 << std::endl <<
    "Merge     | " << t5 << std::endl <<
    "Bubble    | " << t6 << std::endl <<"==================================\n" 
    << std::endl;

  MyFile.close();
} // while

  
  
} // main

