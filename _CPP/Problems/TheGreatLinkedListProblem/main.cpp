#include <cstddef>
#include <iostream>
#include <string>

struct Node {

  int data;
  Node *small, *large; 

  Node(int data) {
    this->data = data;
    large = NULL;
    small = NULL;
  }

};

class OrderedBinaryList {
private:

  // root
  Node* root;

  // insertion
  Node* insert(Node* root, int data) {
    if (root == NULL) {
      return new Node(data); 
    }
    else {
      if (root->data<data) {
        root->large = insert(root->large, data);
        return root;
      }
      else {
        root->small = insert(root->small, data);
        return root;
      }
    }
    return NULL;
  }

  // print
  void print(Node* root) {
    if (root==NULL) {
      return;
    }
    else {
      std::cout << root->data << std::endl;
      print(root->small);
      print(root->large);
    }
  }


  Node* smallest(Node* root) {
    if (root->small==NULL) {
      return root;
    }
    else {
      smallest(root->small);
    }
    return NULL;
  }

  Node* largest(Node* root) {
    if (root->large==NULL) {
      return root;
    }
    else {
      largest(root->large);
    }
    return NULL;
  }

  void printList(Node* root) {
    if (root==NULL) {
      return;
    }
    else {
      std::cout << root->data << " ";
      if (root->large==root) return;
      printList(root->large);
    }
  }

public:
  
  OrderedBinaryList() {
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


  void printList() {
    printList(root);
    return;
  }

};

int main (int argc, char *argv[]) {
  OrderedBinaryList list;
  list.insert(4);
  list.insert(2);
  list.insert(5);
  list.insert(1);
  list.insert(3);
  list.print();
  return 0;
}
