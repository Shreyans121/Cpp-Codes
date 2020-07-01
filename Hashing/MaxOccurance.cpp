#include <iostream>
using namespace std;

template <typename T>
class node {
public:
  T key;
  T value;
  node<T>* next;

  node(T key, T val) {
    this -> key = key;
    value = val;
    next = NULL;
  }
  ~node() {
    if(next!=NULL) {
      delete next;
    }
  }
};

template <typename T>
class hashtable {
  node<T>** table;
  long long int curr_size;
  long long int table_size;

  T hashFn(T key) {
    return key % table_size;
  }

  void rehash() {
    node<T>** oldtable = table;
    long long int oldtableSize = table_size;
    table_size = 2 * table_size;
    table = new node<T>*[table_size];

    for(long long int i = 0; i<table_size; i++) {
      table[i] = NULL;
    }
    curr_size = 0;

    //Shift the elements form old table to new table
    for(long long int i = 0; i<oldtableSize; i++) {
      node<T>*temp = oldtable[i];
      while(temp != NULL) {
        insert(temp -> key, temp -> value);
        temp = temp -> next;
      }
      if(oldtable[i] != NULL) {
        delete oldtable[i];
      }
    }
    delete [] oldtable;
  }

public:
  hashtable (long long int ts = 1003) {
    table_size = ts;
    table = new node<T>*[table_size];
    curr_size = 0;

    //Initializing the table elements with NULL ptr
    for(long long int i = 0; i<table_size; i++) {
      table[i] = NULL;
    }
  }

  void insert(T key, T value) {
    long long int idx = hashFn(key);

    node<T>* n = new node<T>(key, value);
    //Inserting new node at Head
    n -> next = table[idx];
    table[idx] = n;
    curr_size++;

    //Rehash...
    float load_factor = curr_size/(1.0*table_size);
    if(load_factor > 0.5) {
      rehash();
    }
  }

  void print() {
    for(long long int i = 0; i<table_size; i++) {
      cout<<"Bucket "<<i<<" -> ";
      node<T>*temp = table[i];
      while(temp != NULL) {
        cout<<temp -> key<<"("<<temp -> value<<")"<<" -> ";
        temp = temp -> next;
      }
      cout<<endl;
    }
  }

  T* search(T key) {
    long long int idx = hashFn(key);
    node<T>*temp = table[idx];
    while(temp != NULL) {
      if(temp -> key == key)
        return &temp -> value;
      temp = temp -> next;
    }
    return NULL;
  }

  void erase(T key) {
    long long int idx = hashFn(key);
    node<T>*temp = table[idx];
    node<T>*prev = temp;
    if(temp -> key == key) {
      table[idx] = temp -> next;
      temp -> next = NULL;
      delete temp;
      return;
    }

    while(temp != NULL) {
      temp = temp -> next;
      if(temp -> key == key) {
        prev -> next = temp -> next;
        temp -> next = NULL;
        delete temp;
        break;
      }
      prev = prev -> next;
    }
  }

  T& operator[](T key) {
    T*f = search(key);
    if(f == NULL) {
      T val;
      insert(key, val);
      f = search(key);
    }
    return *f;
  }

  T maxOccurance() {
    long long int curr_count = 0;
    long long int max_count = 0;
    long long int number;
    for(long long int i = 0; i<table_size; i++) {
      node<T>*temp = table[i];
      while(temp != NULL) {
        if(temp -> value > max_count) {
          max_count = temp -> value;
          number = temp -> key;
        }
        temp = temp -> next;
      }
    }
    return number;
  }

};


int main() {
  hashtable <long long int> no;

  long long int n;
  cin>>n;

  for(long long int i = 0; i<n; i++) {
    long long int ip;
    cin>>ip;
    long long int*f = no.search(ip);
    if(f == NULL) {
      no[ip] = 1;
    }
    else {
      no[ip]++;
    }
  }
  cout << no.maxOccurance();
}
