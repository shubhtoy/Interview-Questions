#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1], M[n2];
    //copying elements into the temp arrays L and M
    for (int i=0; i<n1;i++)
    {
        L[i] = arr[p+i];
    }
    for (int j=0; j<n2;j++)
    {
        M[j] = arr[q+1+j];
    }
    int i,j,k;
    i = 0;
    j = 0;
    k = p;
    //now we sort and group the elements
    while(i < n1 && j < n2)   //both i and j are in the bounds
    {
        if(L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    //if any one of L or M is exhausted
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int m = (l+(r-1))/2;
        int m1 = (l+(m-1))/2;
        int m2 = (m+r)/2;
        mergeSort(arr,l,m1);
        mergeSort(arr,m1+1,m);
        mergeSort(arr,m+1,m2);
        mergeSort(arr,m2+1,r);
        merge(arr,l,m,r);
    }
}

void displayArr(int arr[], int cap)
{
    printf("\n");
    for(int i=0;i<cap;i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {1, 4, 7, 2, 9, 6};
    int cap = sizeof(A)/ sizeof(A[0]);
    printf("\nThe input array is: ");
    displayArr(A, cap);
    mergeSort(A,0,cap-1);
    printf("The sorted array is: ");
    displayArr(A, cap);
    return 0;
}