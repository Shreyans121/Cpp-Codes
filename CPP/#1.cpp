// Given a list of numbers and a number k,
// return whether any two numbers from the list add up to k.

// For example, given [10, 15, 3, 7] and k of 17,
// return true since 10 + 7 is 17.

#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[10];
    int i = 0;
    while(cin>>arr[i]) {
        i++;
    }
    int n = i - 2;
    int k = arr[i-1];

    sort(arr, arr+n+1);

    int ptr1 = 0;
    int ptr2 = n;

    while(ptr1 < ptr2) {
        if(arr[ptr1] + arr[ptr2] == k) {
            cout<<true;
            return 0;
        }
        if(arr[ptr1] + arr[ptr2] < k) {
            ptr1++;
        }
        else {
            ptr2--;
        }
    }
    cout<<false;
    return 0;
}
