
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
    bubbleSort(arr, n); 
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\nTime Taken By For 100k Bubble Sort Is:\n%f",timer);

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
    bubbleSort(arr2, n); 
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\nTime Taken By For 200k Bubble Sort Is:\n%f",timer);

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
    bubbleSort(arr3, n); 
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\nTime Taken By For 300k Bubble Sort Is:\n%f",timer);

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
    bubbleSort(arr5, n); 
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\nTime Taken By For 500k Bubble Sort Is:\n%f",timer);
    return 0; 
} 
