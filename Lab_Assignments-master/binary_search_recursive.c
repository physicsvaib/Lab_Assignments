
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
  
int work(int arr[], int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
  
        // If the element is present at the middle itself 
        if (arr[mid] == x) { 
           
           printf("Number Found %d",mid+1);
           return mid;      
        
        }
        // If element is smaller than mid, then it can only be present 
        // in left subarray 
        if (arr[mid] > x) return work(arr, l, mid-1, x); 
  
        // Else the element can only be present in right subarray 
        return work(arr, mid+1, r, x); 
   } 
  
   // We reach here when element is not present in array 
   return -1; 
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
    int search;
    scanf("%d",&search);
    start = clock();
    work(arr,0,n-1,search);
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\n%f",timer);
    return 0; 
} 
