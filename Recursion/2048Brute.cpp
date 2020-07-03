#include <iostream>
#include <cmath>
using namespace std;

void add(string &str, int d) {
  switch(d) {
    case 0: str += "zero ";   break;
    case 1: str += "one ";   break;
    case 2: str += "two ";   break;
    case 3: str += "three ";   break;
    case 4: str += "four ";   break;
    case 5: str += "five ";   break;
    case 6: str += "six ";   break;
    case 7: str += "seven ";   break;
    case 8: str += "eight ";   break;
    case 9: str += "nine ";   break;
  }
}

void spell(string &str, int n, int len) {
  if(len == 0) {
    return;
  }
  int digit = floor(n/(pow(10, (len-1))));
  cout<<digit<<" "<<n - (digit*pow(10,(len-1)))<<endl;

  add(str, digit);

  spell(str, (n - (digit*pow(10,(len-1)))), len-1);
  return;
}

int main() {
  int n;
  cin>>n;
  string str;
  int t = n;
  int len = 0;
  while(t>0) {
    t = t/10;
    len++;
  }
  spell(str, n, len);
  cout<<str;
}
