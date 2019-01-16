
// C program for implementation of Bubble sort 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
  
    FILE *file;
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        fprintf(file,"%d \n", arr[i]); 

} 
  

  

// Driver program to test above functions 
int main() 
{ 
 

    file = fopen("Data2.txt","w");

    int n = 20000;
    int arr[n];
    for(int i =0;i<n;i++){
        arr[i] = rand();
    } 
    printArray(arr,n);
    fclose(file);
    return 0; 
} 
