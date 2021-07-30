#include <iostream>
#include <vector>
using namespace std;

bool isWaveArray(vector<int> arr, int n){
    bool result = false;
    if (arr[1] > arr[0] && arr[1] > arr[2]) {
        for (int i = 1; i < n - 1; i += 2) {

            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                result = true;
            }
            else {
                result = false;
                break;
            }
        }
        if (result == true && n % 2 == 0) {
            if (arr[n - 1] <= arr[n - 2]) {
                result = false;
            }
        }
    }
    else if (arr[1] < arr[0] && arr[1] < arr[2]) {
        for (int i = 1; i < n - 1; i += 2) {

            if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                result = true;
            }
            else {
                result = false;
                break;
            }
        }
        if (result == true && n % 2 == 0) {
            if (arr[n - 1] >= arr[n - 2]) {
                result = false;
            }
        }
    }
    return result;
}

int Solve(vector<int> arr){
    int n = arr.size();
    if(isWaveArray(arr,n))
        return 0;
    int count = 0;
    vector<int> temp(n);
    for(int i=0;i<n;i++){
        temp = arr;
        temp.erase(i+temp.begin());
        if(isWaveArray(temp,n-1))
            count+=1;
    }
    return count == 0 ? -1 : count;
}

int main() {
    int n;
    cin>>n;
    vector<int> trees(n);
    for(int i=0;i<n;i++)
        cin>>trees[i];
    cout<<Solve(trees)<<endl;
}
