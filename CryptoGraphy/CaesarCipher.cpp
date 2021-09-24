#include<iostream>
#include<cstring>
using namespace std;

string encrypt(string plainText) {
  string cipher;

  for(auto ch: plainText) {
    if(isupper(ch)) {
      cipher += char(int((ch + 3) - 65) % 26 + 65);
    }
    else {
      cipher += char(int((ch + 3) - 97) % 26 + 97);
    }
  }

  return cipher;
}

string decrypt(string cipher) {
  string plainText;

  for(auto ch: cipher) {
    if(isupper(ch)) {
      plainText += char(int((ch + (26 - 3)) - 65) % 26 + 65);
    }
    else {
      plainText += char(int((ch + (26 - 3)) - 97) % 26 + 97);
    }
  }

  return plainText;
}

int main(int argc, char const *argv[]) {
  string plainText, cipher;

  cin>>plainText;
  cout<<"Encrypted Message: "<<encrypt(plainText)<<endl;

  cin>>cipher;
  cout<<"Decrypted Message: "<<decrypt(cipher)<<endl;


  return 0;
}
