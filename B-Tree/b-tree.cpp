#include <iostream>
using namespace std;

class TreeNode {
  int *keys;
  int t;
  TreeNode **C;
  int n;
  bool leaf;

public:
  TreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;

    keys = new int[2 * t - 1];
    C = new TreeNode *[2 * t];

    n = 0;
  }
  void traverse() {
    int i;
    for (i = 0; i < n; i++) {
      if (leaf == false)
        C[i]->traverse();
      cout << " " << keys[i];
    }

    if (leaf == false)
      C[i]->traverse();
  }

  TreeNode *search(int k) {
    int i = 0;
    while (i < n && k > keys[i])
      i++;

    if (keys[i] == k)
      return this;

    if (leaf == true)
      return NULL;

    return C[i]->search(k);
  }

  void insertNonFull(int k) {
    int i = n - 1;

    if (leaf == true) {
      while (i >= 0 && keys[i] > k) {
        keys[i + 1] = keys[i];
        i--;
      }

      keys[i + 1] = k;
      n = n + 1;
    } else {
      while (i >= 0 && keys[i] > k)
        i--;

      if (C[i + 1]->n == 2 * t - 1) {
        splitChild(i + 1, C[i + 1]);

        if (keys[i + 1] < k)
          i++;
      }
      C[i + 1]->insertNonFull(k);
    }
  }

  void splitChild(int i, TreeNode *y) {
    TreeNode *z = new TreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
      z->keys[j] = y->keys[j + t];

    if (y->leaf == false) {
      for (int j = 0; j < t; j++)
        z->C[j] = y->C[j + t];
    }

    y->n = t - 1;
    for (int j = n; j >= i + 1; j--)
      C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
      keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];
    n = n + 1;
  }

  friend class BTree;
};

class BTree {
  TreeNode *root;
  int t;

   public:
  BTree(int temp) {
    root = NULL;
    t = temp;
  }

  void traverse() {
    if (root != NULL)
      root->traverse();
  }

  TreeNode *search(int k) {
    return (root == NULL) ? NULL : root->search(k);
  }

  void insert(int k) {
    if (root == NULL) {
      root = new TreeNode(t, true);
      root->keys[0] = k;
      root->n = 1;
    } else {
      if (root->n == 2 * t - 1) {
        TreeNode *s = new TreeNode(t, false);

        s->C[0] = root;

        s->splitChild(0, root);

        int i = 0;
        if (s->keys[0] < k)
          i++;
        s->C[i]->insertNonFull(k);

        root = s;
      } else
        root->insertNonFull(k);
    }
  }
};

int main() {
  BTree t(3);
  t.insert(1);
  t.insert(2);
  t.insert(3);
  t.insert(4);
  t.insert(5);
  t.insert(6);
  t.insert(7);
  t.insert(8);
  t.insert(9);
  t.insert(10);

  cout << "The B-tree is: ";
  t.traverse();

  int k = 10;
  (t.search(k) != NULL) ? cout << endl << k << " is found"
                        : cout << endl << k << " is not Found";

  k = 20;
  (t.search(k) != NULL) ? cout << endl << k << " is found"
                        : cout << endl << k << " is not Found";
}
