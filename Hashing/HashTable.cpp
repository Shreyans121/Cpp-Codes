#include <iostream>
#include "Hashing.h"
using namespace std;

int main() {
  hashtable <int> price;

  price.insert("Burger", 180);
  price.insert("Coke", 60);
  price.insert("Fries", 100);
  price.insert("Ice Cream", 85);
  price.insert("Ketchup", 5);

  price.print();

  int *p = price.search("Coke");
  if(p == NULL) {
    cout<<"Not Found";
  }
  else {
    cout<<"Price is "<<*p<<endl;
  }

  price["Whopper"] = 200;
  cout<<"Price of Whopper is ";
  cout<<price["Whopper"]<<endl;

  int updateP;
  cin>>updateP;

  cout<<"Updated Price of Whopper is ";
  cout<<price["Whopper"] + updateP<<endl;

  return 0;






}
