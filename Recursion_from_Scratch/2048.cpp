#include<iostream>
using namespace std;

char str[10][15] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void spell(int x) {
  if(x <= 0) {
    return;
  }
  spell(x/10);
  cout<<str[x%10]<<" ";
  return;
}

int main(int argc, char const *argv[]) {
  int x;
  cin>>x;

  spell(x);
  return 0;
}
