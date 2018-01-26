// Copyright (c) 2018 by litstockz. All Rights Reserved.
#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

void bubbleSort(int arr[], int n)
{
    // 如果为空或者数组长度小于2
    if (n == 1)
        return;

    //
    for (int e = n-1 ; e > 0; e--)
    {
      for (int i=0; i<e; i++)
          if (arr[i] > arr[i+1])
              swap(arr[i], arr[i+1]);
    }
}

/* Function to print an array */
void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array : \n");
    printArray(arr, n);
    return 0;
}
