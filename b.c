#include<stdio.h>
#include<stdlib.h>

int main(){

    FILE *file;
    file = fopen("Data.txt","r");
    int n = 100000;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        fscanf(file,"%d\n",&arr[i]);
    }
    for(int i=0;i<10;i++){
        printf("%d\n",arr[i]);

    }

    fclose(file);

}