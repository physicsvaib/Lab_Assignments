
// C program for implementation of Bubble sort 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
  
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
  
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 
  
int work(int arr[], int n)
    {
       int first, last, middle, search;  
       printf("Enter value to find\n");
       scanf("%d", &search);

       first = 0;
       last = n - 1;
       middle = (first+last)/2;
     
       while (first <= last) {
          if (arr[middle] < search)
             first = middle + 1;    
          else if (arr[middle] == search) {
             printf("%d found at location %d.\n", search, middle+1);
             break;
          }
          else
             last = middle - 1;
     
          middle = (first + last)/2;
       }
       if (first > last)
          printf("Not found! %d isn't present in the list.\n", search);
     
       return 0;  
    }


// Driver program to test above functions 
int main() 
{ 
    clock_t start,end;
    double timer;
    int n = 100000;
    int arr[n];
    for(int i =0;i<n;i++){
        arr[i] = rand();
    } 
    bubbleSort(arr, n); 
    printf("Sorted array: \n arr[40000] : %d\n",arr[40000]); 
        start = clock();

    work(arr,n);
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\n%f",timer);
    return 0; 
} 
