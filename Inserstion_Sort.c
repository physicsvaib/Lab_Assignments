
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
  
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n) 
{ 
   int i, key, j; 
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1; 
  
       /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
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
    insertionSort(arr, n); 
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\nTime Taken By Insertion Sort For 100k Is:\n%f",timer);

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
    insertionSort(arr2, n); 
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\nTime Taken By Insertion Sort For 200k Is:\n%f",timer);

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
    insertionSort(arr3, n); 
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\nTime Taken By Insertion Sort For 300k Is:\n%f",timer);

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
    insertionSort(arr5, n); 
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\nTime Taken By Insertion Sort For 500k Is:\n%f",timer);
    
    return 0; 
} 
