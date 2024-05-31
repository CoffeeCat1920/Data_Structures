#include <cstddef>
#include <iostream>

struct Node {

  Node* next;
  char data;

  Node(char data) {
    this->data = data;
    this->next = NULL;
  }

};

class Stack {
private:

  Node* head;
  int count;

public:

  Stack() {
    head = NULL;
    count = 0;
  }

  bool empty() {
    return (head == NULL);
  }

  void push(char data) {
    if (head == NULL) {
      head = new Node(data);
      count++;
      return;
    }
    else {
      Node* temp = head;
      head = new Node(data);
      head->next = temp;
      count++;
      return;
    }
  }

  char pop() {
    if (empty()) {
      return 0; 
    } 
    else {
      Node *temp = head->next;
      char data = head->data;
      delete head; 
      head = temp;
      count--;
      return data;
    }
  }

  int size() {
    return count;
  }

};

int main (int argc, char *argv[]) {

  std::string problem = "{[()]}"; 
  
  Stack openBracs, closeBlacs;

  for (int i = 0; i<=6; i++) {
    if ( (problem[i] == '{') || (problem[i] == '[') || (problem[i] = '(') ) {
      openBracs.push(problem[i]);
    }
    else {
      closeBlacs.push(problem[i]);
    }
  }

  if (openBracs.size() != closeBlacs.size()) {
    std::cout << "openBracs = " << openBracs.size() << " closeBlacs = " << closeBlacs.size() << std::endl;
    std::cout << "Not balance" << std::endl;
  }
  else {

    while (openBracs.empty() || closeBlacs.empty()) {

      if (openBracs.pop() != closeBlacs.pop()) {
        std::cout << "openBracs = " << openBracs.pop() << "closeBlacs = " << closeBlacs.pop() << std::endl;
        std::cout << "Not balance" << std::endl;
        return 0;
      }
      
    }

    std::cout << "Balance" << std::endl;

  }

  return 0;

}
