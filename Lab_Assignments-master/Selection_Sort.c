
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
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 
  
  
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 
  

// Driver program to test above functions 
int main() 
{ 
    clock_t start,end;
    double timer;
    start = clock();
FILE *file;
    file = fopen("Data.txt","r");
    int n = 100000;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        fscanf(file,"%d\n",&arr[i]);
    }
    
    fclose(file);
    selectionSort(arr, n); 
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\nTime Taken By Selection Sort For 100k Is:\n%f",timer);
    

        start = clock();
FILE *file2;
    file2 = fopen("Data2.txt","r");
    n = 200000;
    int arr2[n];
    for(int i=0;i<n;i++)
    {
        fscanf(file2,"%d\n",&arr2[i]);
    }
    
    fclose(file2);
    selectionSort(arr2, n); 
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\nTime Taken By Selection Sort For 200k Is:\n%f",timer);

        start = clock();
FILE *file3;
    file3 = fopen("Data3.txt","r");
    n = 300000;
    int arr3[n];
    for(int i=0;i<n;i++)
    {
        fscanf(file3,"%d\n",&arr3[i]);
    }
    
    fclose(file3);
    selectionSort(arr3, n); 
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\nTime Taken By Selection Sort For 300k Is:\n%f",timer);

        start = clock();
FILE *file5;
    file5 = fopen("Data5.txt","r");
    n = 500000;
    int arr5[n];
    for(int i=0;i<n;i++)
    {
        fscanf(file5,"%d\n",&arr5[i]);
    }
    
    fclose(file5);
    selectionSort(arr5, n); 
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\nTime Taken By Selection Sort For 500k Is:\n%f",timer);
    return 0; 
} 
