#include<iostream>
using namespace std;

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:" << endl;
    for(int i = 0; i<n; i++) {
       cin >> arr[i];
    }
    int k;
    cout<<"Enter the elemnet to be searched: ";
    cin>>k;

    int index = search(arr, n, k);
    if (index == -1)
        cout << "Element is not present in the array";
    else
        cout << "Element found at index " << index;

    return 0;
}
