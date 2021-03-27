#include <bits/stdc++.h>
#include <random>
using namespace std;

static bool resp[100][10000];

double sigmoid(double x) {
     double sig;
     sig = 1 / (1 + exp(-x));
     return sig;
}

double rand_double() {
  random_device rd;
  default_random_engine generator(rd());
  uniform_real_distribution<double> distribution(-3.00,3.00);

  return distribution(generator);
}

int cheating(string resp[100], int p) {
  vector<double> skill(100);
  vector<double> diff(10000);
  vector<vector<int>> apt;

   for(int i = 0; i<100; i++) {
     skill[i] = rand_double();
   }

   for(int i = 0; i<10000; i++) {
     diff[i] = rand_double();
   }

   for(int i = 0; i<100; i++) {
     for(int j = 0; j<10000; j++) {
       break;
     }
   }

}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, p;
  cin>>t>>p;

  int num = 1;

  while(t--) {
    string resp_str[100];

    for(int i = 0; i<100; i++) {
      cin>>resp_str[i];
      cout<<i<<endl;
    }

    cout<<"hi";


    for(int i = 0; i<100; i++) {
      for(int j = 0; j<10000; j++) {
        if(resp_str[i][j] == '0') {
          resp[i][j] = false;
        }
        else {
          resp[i][j] = true;
        }
      }
    }

    cout<<endl<<resp[0][5];

    // cout<<"Case #"<<num<<": "<<cheating(resp, p)<<endl;
    num++;
  }

  return 0;
}
