#include <cstddef>
#include <iostream>
#include <vector>

struct BTNode {

  int data;
  BTNode* left;
  BTNode* right;

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
  
  // adding elements to a tree
  BTNode* insert(BTNode* root, int data) {
    if (root == NULL) {
      return new BTNode(data);
    }
    else {
      if (root->data<data) {
        root->right = insert(root->right, data);
      }
      else {
        root->left = insert(root->left, data);
      }
      return root;
    }
  }
  
  // inorder traversal of a tree
  void inorder(BTNode* root) {
    if (root == NULL) {
      return;
    }
    else {
      inorder(root->left);
      std::cout << root->data << ", ";
      inorder(root->right);
    }
  }
  
  // total number of nodes in a tree
  int size(BTNode* root) {
    if (root==NULL) {
      return 0;
    }
    else {
      return (size(root->left) + 1 + size(root->right));
    }
  }

  // the deepest a tree go
  int maxDepth(BTNode* root) {
    if (root==NULL) {
      return 0;
    }
    else {
      int left = 1 + maxDepth(root->left);
      int right = 1 + maxDepth(root->right);
      if (left>=right) return left;
      else return right;
    }
  }
 
  // minimum value in a tree
  int maxValue(BTNode* root) {
    if (root->right==NULL) {
      return root->data; 
    }
    else {
      return maxValue(root->right);
    }
  }

  // minimum value in a tree
  int minValue(BTNode* root) {
    if (root->left==NULL) {
      return root->data; 
    }
    else {
      return minValue(root->left);
    }
  }

  // mirror the tree
  void mirror(BTNode* root) {
    if (root->left==NULL && root->right==NULL) {
      return;
    }
    else {
      BTNode* node = NULL;
      node = root->left;
      root->left = root->right;
      root->right = node; 
      mirror(root->left);
      mirror(root->right);
    }
  }

  // double trouble
  void doubleTree(BTNode* root) {
    if (root==NULL) {
      return;
    }
    else {

      doubleTree(root->left);
      doubleTree(root->right);

      BTNode* oldLeft = root->left;
      root->left = new BTNode(root->data);
      root->left->left = oldLeft; 

    }
  }
  
  // check is a tree has a root-to-leaf path
  bool hasPathSum(BTNode*root, int sum, int i) {

    if (root == NULL) {

      if (i == sum) {
        return true;
      }

      return false; 

    } 
    else {

      i += root->data;

      return ( hasPathSum(root->left, sum, i) || hasPathSum(root->right, sum, i) );

    }

  }

  void printPaths(BTNode* node, std::vector<int> path) {
     
  }

  bool isBST(BTNode* node) {
    if (node == NULL) {
      return true;
    }
    else if (node->left != NULL && maxValue(node->left) > node->data ) {
      return false; 
    }
    else if (node->right != NULL && minValue(node->right) > node->data) {
      return false;
    }
    return true;
  }

public:

  Tree() {
    root = NULL;
  }

  BTNode* getroot() {
    return root;
  }

  void insert(int data) {
    this->root = this->insert(root, data);
  }

  void print() {
    std::cout << "Inorder: ";
    inorder(root);
    std::cout << "\n";
  }

  int size() {
    return size(root);
  }

  int maxDepth() {
    return maxDepth(root);
  }

  int minValue() {
    return minValue(root);
  } 

  void mirror() {
    mirror(root);
  }

  void doubleTree() {
    doubleTree(root);
  }
  
  bool hasPathSum(int sum) {
    return hasPathSum(root, sum, 0);
  }

  bool isBST() {
    return isBST(root);
  }
};


bool sameTree(BTNode* a, BTNode* b) {

  if (a == NULL && b == NULL) {
    return true;
  }
  else if (a != NULL && b != NULL) {
    return ( a->data == b->data && sameTree( a->left, b->left ) && sameTree( a->right, b->right ) );
  }

  return false;

}

int main (int argc, char *argv[]) {

  Tree tree;

  BTNode* shitTree = new BTNode(1);

  tree.insert(4);
  tree.insert(5);
  tree.insert(2);
  tree.insert(3);
  tree.insert(1);

  shitTree->right = new BTNode(2);
  shitTree->left = new BTNode(3);

  std::cout << tree.isBST() << std::endl;

  return 0;
}
