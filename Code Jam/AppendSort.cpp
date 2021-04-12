#include<iostream>
#include<cmath>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;

  int num = 1;

  while(t--) {
    int n;
    cin>>n;

    int arr[100];
    for(int i = 0; i<n; i++) {
      int ip;
      cin>>arr[i];
    }

    int ans = 0;
    int prev, curr;

    prev = arr[0];

    for(int i = 1; i<n; i++) {
      // cout<<prev<<" "<<arr[i]<<endl;
      if(arr[i] < prev) {
        string str1, str2;
        str1 = to_string(prev);
        str2 = to_string(arr[i]);

        int n1 = str1.length();

        for(int j = 0; str2[j] != '\0'; j++) {
          if(str1[j] == str2[j]) {
            if(str2[j+1] == '\0') {
              if(str1[n1 - 1] == '9') {
                int power = n1 - j;
                ans += (power);

                while(power--) {
                  arr[i] = arr[i]*10;
                }
                // cout<<str1[j]<<" compare "<<str2[j]<<" in loop 1 if 3 << "<<ans<<endl;
                break;
              }
              else {
                ans += (n1 - j - 1);
                arr[i] = prev + 1;
                // cout<<str1[j]<<" compare "<<str2[j]<<" in loop 1 if 4 << "<<ans<<endl;
              }
            }

          }
          else if(str1[j] < str2[j]) {
            int power = n1 - j - 1;
            ans += (power);

            while(power--) {
              arr[i] = arr[i]*10;
            }
            // cout<<arr[i]<<endl;
            // cout<<n1-j-1<<endl;
            // cout<<mul<<endl;
            // arr[i] = arr[i]*mul;
            // cout<<arr[i]<<endl;
            // cout<<str1[j]<<" compare "<<str2[j]<<" in loop 1 if1 < "<<ans<<endl;
            break;
          }
          else if(str1[j] > str2[j]) {
            int n2 = str2.length();
            int power = n1 - j - (n2 - j - 1);
            ans += (power);

            while(power--) {
              arr[i] = arr[i]*10;
            }
            // cout<<str1[j]<<" compare "<<str2[j]<<" in loop 1 if2 > "<<ans<<endl;
            break;
          }
        }
        // cout<<"exit loop 1 "<<prev<<" curr - "<<arr[i]<<" ans - "<<ans<<endl;
      }
      else if(arr[i] == prev) {
        arr[i] *= 10;
        ans++;
      }
      prev = arr[i];
    }

    cout<<"Case #"<<num<<": "<<ans<<endl;
    num++;
  }
  return 0;
}
