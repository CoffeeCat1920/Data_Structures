#include <cstddef>
#include <iostream>
#include <vector>

struct Node {

  int data;
  Node *left, *right;

  Node() {
    data = 0;
  }

  Node(int data) {
    this->data = data;
  }

};

class BinarySearchTree {

private:

  Node* root;

  // insertion logic
  Node* insert(Node* root, int data) {
    if (root == NULL) {
      return new Node(data);
    }
    else {
      if (root->data>=data) {
        root->left = insert(root->left, data);
        return root;
      }
      else {
        root->right = insert(root->right, data);
        return root;
      }
    }
  }

  // inorder printing
  void inorder(Node* root) {
    if (root==NULL) {
      return;
    }
    else {
      inorder(root->left);
      std::cout << root->data << " ";
      inorder(root->right);
    }
    return;
  }

  // postorder printing
  void postorder(Node* root) {
    if (root==NULL) {
      return;
    }
    else {
      postorder(root->left);
      postorder(root->right);
      std::cout << root->data << " ";
    }
  }

  std::vector<int> entries(Node* root, std::vector<int> vec) {
    if (root==NULL) {
      return vec;
    }
    else {
      entries(root->left, vec);
      vec.push_back(root->data); 
      entries(root->right, vec);
    }
    return vec;
  }

  // size of tree
  int size(Node* root) {
    if (root==NULL) {
      return 0;
    }
    else {
      int leftsize = 0;
      int rightsize = 0;
      leftsize += size(root->left);
      rightsize += size(root->right);
      return 1 + leftsize + rightsize;
    }
  }

  // Depths
  
  // Max
  int maxDepth(Node* root) {
    if (root==NULL) {
      return 0;
    }
    else {
      int left = maxDepth(root->left);
      int right = maxDepth(root->right);
      if (left>right) return(1+left); 
      else return(1+right);
    }
  }
  
  // Min
  int minDepth(Node* root) {
    if (root==NULL) {
      return 0;
    }
    else {
      int left = minDepth(root->left);
      int right = minDepth(root->right);
      if (left<right) return(1+left);
      else return (1+right);
    }
  }

  // nodes having equal sum to given data
  int hasPathSum(Node* node, int sum) {
    if (node == NULL) {
      return(sum == 1);
    }
    else {
      int subSum = sum - node->data;
      return(hasPathSum(node->left, subSum) || hasPathSum(node->right, subSum));
    }
  }

  // resursive mirror
  void mirror(Node* root) {
    if (root==NULL) {
      return;
    }
    else {
      mirror(root->left);
      mirror(root->right);
      Node* temp = root->left;
      root->left = root->right;
      root->right = temp;
    }
  }

  // attach a duplicate tree at the end of our tree
// attach a duplicate tree at the end of our tree
  Node* doubleTree(Node* root) {
    if (root == NULL) {
      return NULL;
    }
    else {
      Node* duplicateNode = new Node(root->data);
      duplicateNode->left = doubleTree(root->left);
      duplicateNode->right = doubleTree(root->right);
      return duplicateNode;
    }
  }
public:

  BinarySearchTree() {
    root = NULL;
  }

  // insertion
  void insert(int data) {
    root = insert(root, data);
  }

  // printing
  void print() {
    std::cout << "\ninorder: ";
    inorder(root);
    std::cout << "\npostorder: ";
    postorder(root);
    std::cout << "\n";
  }
  
  // size 
  int size() {
    int count = size(root);
    return count;
  }

  // max depth
  void maxDepth() {
    std::cout << "\nmax depth: ";
    std::cout << maxDepth(root);
  }

  // min depth
  void minDepth() {
    std::cout << "\nmin depth: ";
    std::cout << minDepth(root);
  }
  
  void hasPathSum(int data) {
    std::cout << hasPathSum(root, data);
  }

  // mirror
  void mirror() {
    mirror(root);
    return;
  }
  
  void doubleTree() {
    doubleTree(root);
    return;
  }

  std::vector<int> entries() {
    std::vector<int> temp;
    temp = entries(root, temp); 
    return temp;
  }

};

bool sameTree(BinarySearchTree tree1, BinarySearchTree tree2) {
  
  std::vector<int> list1 = tree1.entries();
  std::vector<int> list2 = tree2.entries();
 
  int size1 = tree1.size();
  int size2 = tree2.size();

  if (size1!=size2) {
    return false;
  }
  else {
    for (int i=0; i<=size1-1; i++) {
      if (list1[i]!=list2[i]) {
        return false;
      }
    } 
    return true;
  }

}

int main (int argc, char *argv[]) {
  BinarySearchTree tree1, tree2;
  tree1.insert(2);
  tree1.insert(1);
  tree1.insert(3);
  tree2.insert(2);
  tree2.insert(1);
  tree2.insert(3);
  tree2.insert(12);
  bool result = sameTree(tree1, tree2);
  std::cout << result << std::endl;
  return 0;
}
