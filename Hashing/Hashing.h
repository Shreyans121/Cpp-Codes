#include <iostream>
#include <cstring>
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
  int curr_size;
  int table_size;

  hashFn(T key) {

    return key % table_size;
  }

  void rehash() {
    node<T>** oldtable = table;
    int oldtableSize = table_size;
    table_size = 2 * table_size;
    table = new node<T>*[table_size];

    for(int i = 0; i<table_size; i++) {
      table[i] = NULL;
    }
    curr_size = 0;

    //Shift the elements form old table to new table
    for(int i = 0; i<oldtableSize; i++) {
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
  hashtable (int ts = 7) {
    table_size = ts;
    table = new node<T>*[table_size];
    curr_size = 0;

    //Initializing the table elements with NULL ptr
    for(int i = 0; i<table_size; i++) {
      table[i] = NULL;
    }
  }

  void insert(T key, T value) {
    int idx = hashFn(key);

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
    for(int i = 0; i<table_size; i++) {
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
    int idx = hashFn(key);
    node<T>*temp = table[idx];
    while(temp != NULL) {
      if(temp -> key == key)
        return &temp -> value;
      temp = temp -> next;
    }
    return NULL;
  }

  void erase(T key) {
    int idx = hashFn(key);
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
    int curr_count = 0;
    int max_count = 0;
    int number;
    for(int i = 0; i<table_size; i++) {
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
