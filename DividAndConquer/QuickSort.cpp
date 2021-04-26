#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

class Solution
{
    public:
    
    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high) // this function will return pivot position whose left and right side elements are smaller and greater then pivot element respectively
    {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high- 1; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        //returning the partitioning index.
        return (i + 1);
    }
};

int main()
{
    int arr[1000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}


// example 
// 4 1 3 9 2 7

// running 
Pivot position = 4 and Pivot element 7
4 1 3 2 7 9 
Pivot position = 1 and Pivot element 2
1 2 3 4 
Pivot position = 3 and Pivot element 4
3 4 
res -> 1 2 3 4 7 9 
