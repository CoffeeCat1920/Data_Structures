#include <cstddef>
#include <exception>
#include <iostream>

struct BTNode {
  int data;
  BTNode* left;
  BTNode* right;

  BTNode(int data, BTNode* left, BTNode* right) {
    this->data = data;
    this->right = right;
    this->left = left;
  }

  BTNode(int data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }

  BTNode() {
    data = 0; 
    left = NULL;
    right = NULL;
  }

};

class Tree {
private: 
  BTNode* root;

  BTNode* insert(BTNode* root, int data) {

    if (root==NULL) {
      return new BTNode(data);
    } 
    else {
      if (root->data < data) {
        root->right = insert(root->right, data);
      }
      else {
        root->left = insert(root->left, data);
      }
    }
    return root;

  }

  void print(BTNode* root) {
    if (root==NULL) return;
    print(root->left);
    std::cout << root->data;
    print(root->right);
  } 

  BTNode* smallest(BTNode* root) {
    if (root->left==NULL) {
      return root;
    }
    else {
      BTNode* small = smallest(root->left);
      return small;
    }
  }

public:

  Tree() {
    root = NULL;
  }
 
  void insert(int data) {
    root = insert(root, data);
    return;
  }

  void print() {
    print(root);
    return;
  }

  BTNode* smallest() {
    return smallest(root);
  }

  BTNode* getRoot() {
    return root;
  }

};

void join(BTNode* a, BTNode* b) {

  a->right = b;
  b->left = a;

}

BTNode* append(BTNode* a, BTNode* b) {

  BTNode* aLast, *bLast;

  if (a==NULL) return b;
  if (b==NULL) return a;

  aLast = a->left;
  bLast = b->left;

  join(aLast, b);
  join(bLast, a);

  return a;

}

BTNode* treeToList(BTNode* root) {
  
  BTNode* aList, *bList;

  if (root==NULL) {
    return NULL;
  }

  aList = treeToList(root->left);
  bList = treeToList(root->right);

  root->left = root;
  root->right = root;

  aList = append(aList, root);
  aList = append(aList, bList);

  return aList;

}

void printList(BTNode* head) {
  if (head == NULL) {
    return;
  }
  else {
    BTNode* current = head;
    
    // Traverse forward
    do {
        std::cout << current->data << " ";
        current = current->right;
    } while (current != head);
  }
}

int main (int argc, char *argv[]) {

  Tree tree;

  BTNode* list;

  tree.insert(4);
  tree.insert(2);
  tree.insert(5);
  tree.insert(3);
  tree.insert(1);

  list = treeToList(tree.getRoot());

  printList(list);
  
  return 0;
}
