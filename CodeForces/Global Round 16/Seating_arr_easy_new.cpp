#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int insertionSort(int *vec, int m) {

   int temp;
   int j = 0;
   int ans = 0;

   for(int i = 1; i<m; i++) {

      temp = vec[i];
      j = i;

      while(j > 0 && vec[j-1]<temp) {

         vec[j] = vec[j-1];
         ans++;
         j--;
      }
      vec[j] = temp;
   }
   return ans;
}

int main(int argc, char const *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;
  cin>>t;
  while(t--) {
    int n, m;
    cin>>n>>m;

    int vec[100000];

    for(int i = 0; i<m; i++) {
      int temp;
      cin>>temp;

      vec[i] = temp;
    }

    cout<<insertionSort(vec, m)<<endl;
  }
  return 0;
}
