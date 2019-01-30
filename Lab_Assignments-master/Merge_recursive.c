/* Recursive C program for merge sort */
#include<stdlib.h> 
#include<stdio.h> 
#include<time.h>

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r); 

/* l is for left index and r is right index of the sub-array 
of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
if (l < r) 
{ 
	int m = l+(r-l)/2; //Same as (l+r)/2 but avoids overflow for large l & h 
	mergeSort(arr, l, m); 
	mergeSort(arr, m+1, r); 
	merge(arr, l, m, r); 
} 
} 

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* Function to print an array */
  
    
void printArray(int arr[], int size) 
{ 
    FILE *file;
    file = fopen("Data13.txt","w");
    int i; 
    for (i=0; i < size; i++) 
        fprintf(file,"%d \n", arr[i]); 
    fclose(file);

} 

/* Driver program to test above functions */
int main() 
{ 
	
    clock_t start,end;
    double timer;
    start = clock();
    FILE *file;
    file = fopen("Data11.txt","r");
    int n = 30000;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        fscanf(file,"%d\n",&arr[i]);
    }
    
    fclose(file);

	mergeSort(arr, 0, n - 1); 

	printf("\nSorted array is \n"); 
	printArray(arr, n); 
    end = clock();
    timer = ((double) (end-start)/CLOCKS_PER_SEC);
    printf("\nTime Taken Is:\n%f",timer);
    
	return 0; 
} 
