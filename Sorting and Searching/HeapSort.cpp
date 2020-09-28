#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int big = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[big])
        big = l;

    if (r < n && arr[r] > arr[big])
        big = r;

    if (big != i)
    {
        swap(arr[i], arr[big]);
        heapify(arr, n, big);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[100], n;
    cin>>n;

    for(int i = 0; i<n; i++)  {
      cin>>arr[i];
    }

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
}
