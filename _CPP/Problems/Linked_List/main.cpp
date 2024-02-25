#include <cstddef>
#include <iostream>
#include <vector>

struct Node {
  int data;
  Node* next;
};

class LinkedList {
private:
  Node* head;
public:
  LinkedList() {
    head = nullptr;
  }

  LinkedList operator+(LinkedList const& obj) {
    LinkedList result;
    Node* tempHead = result.head;
    while (tempHead->next != nullptr) {
      tempHead = tempHead->next;
    }
    tempHead->next = obj.head;
    return result;
  }

  Node* getHead() {
    return head;
  }

  Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
  }

  void deleteNode(int index) {
    if (head == nullptr) {
      return;
    } else if (index == 1) {
      Node* temp = head;
      Node* next = temp->next;
      delete temp;
      head = next;
      return;
    } else if (count() == index) {
      Node* temp = head;
      while (temp->next->next != nullptr) {
        temp = temp->next;
      }
      delete temp->next;
      temp->next = nullptr;
      return;
    } else if (count() < index) {
      return;
    } else {
      Node* temp = head;
      for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
      }
      Node* next = temp->next->next;
      Node* previous = temp;
      delete temp->next;
      previous->next = next;
    }
  }

  void addNode(int data) {
    if (head == nullptr) {
      head = createNode(data);
      return;
    } else {
      Node* temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = createNode(data);
      return;
    }
  }

  void pushFront(int data) {
    Node* temp = head;
    Node* newNode = createNode(data);
    head = newNode;
    newNode->next = temp;
    return;
  }

  void printList() {
    if (head == nullptr) {
      return;
    } else {
      Node* temp = head;
      while (temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
      }
    }
    return;
  }

  int count() {
    if (head == nullptr) {
      return 0;
    } else {
      Node* temp = head;
      int count = 0;
      while (temp != nullptr) {
        count++;
        temp = temp->next;
      }
      return count;
    }
  }

  int getDataAt(int index) {
    if (head == nullptr) {
      return 0;
    } else {
      if (count() <= index) {
        return 0;
      } else {
        Node* temp = head;
        for (int i = 0; i < index; i++) {
          temp = temp->next;
        }
        return temp->data;
      }
    }
  }

  bool deleteList() {
    if (head == nullptr) {
      return true;
    } else {
      Node* temp = head;
      while (temp != nullptr) {
        Node* temp1 = temp->next;
        delete temp;
        temp = temp1;
      }
      head = nullptr;
      return true;
    }
  }

  int pop() {
    if (head == nullptr) {
      return 0;
    } else {
      Node* temp = head;
      Node* next = temp->next;
      int a = temp->data;
      delete temp;
      head = next;
      return a;
    }
  }

  void insertAt(int index, int data) {
    if (head == nullptr) {
      addNode(data);
    } else {
      if (index == 0) {
        Node* temp = head;
        Node* temp1 = createNode(data);
        head = temp1;
        temp1->next = temp;
        return;
      } else {
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
          temp = temp->next;
        }
        Node* temp1 = createNode(data);
        Node* next = temp->next;
        temp->next = temp1;
        temp1->next = next;
      }
    }
  }

  void sort() {
    if (head == nullptr) {
      return;
    } else {
      Node* temp = head;
      Node* temp1;
      while (temp != nullptr) {
        temp1 = temp->next;
        while (temp1 != nullptr) {
          if (temp->data >= temp1->data) {
            int tempdata = temp->data;
            temp->data = temp1->data;
            temp1->data = tempdata;
          }
          temp1 = temp1->next;
        }
        temp = temp->next;
      }
    }
    return;
  }

  void insertSorted(int data) {
    if (head == nullptr) {
      return;
    } else {
      sort();
      Node* temp = head, *insert = createNode(data), *previous, *next;
      while (temp->next->data <= data) {
        temp = temp->next;
      }
      previous = temp;
      next = temp->next;
      previous->next = insert;
      insert->next = next;
    }
  }

  void concatenate(LinkedList* list) {
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = list->head;
    list->head = nullptr;
  }

  LinkedList split() {
    if (head == nullptr) {
      LinkedList list;
      return list;
    } else if (count() < 2) {
      LinkedList list;
      list.head = head;
      return list;
    } else {
      Node* slowPointer = head;
      Node* fastPointer = head;
      while (fastPointer != nullptr) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
      }
      Node* cutPoint = slowPointer, *next = slowPointer->next;
      slowPointer->next = nullptr;
      LinkedList list;
      list.head = next;
      return list;
    }
  }

  void deleteDuplicate() {
    if (head==NULL) {
      return;
    }
    else {
      Node* temp1 = head, *temp2 = head;
      int n = 0, m;
      while (temp1!=NULL) {
        temp2 = temp1->next;
        m = n;
        while (temp2!=NULL) {
          m++;
          if (temp1->data==temp2->data) {
            deleteNode(m);
            return;
          }
          temp2 = temp2->next;
        }
        temp1 = temp1->next;
        n++;
      }
    }
  }

  void moveNode(LinkedList *list) {
    list->pushFront(this->pop());
  }

  std::vector<LinkedList> alternatingSplit() {
    std::vector<LinkedList> alteLists;
    LinkedList list1;
    LinkedList list2;
    Node* temp=head;
    int n=0;
    while (temp!=NULL) {
      if (n==0 || n%2==0) {
        list1.addNode(this->getDataAt(n)); 
      }
      else {
        list2.addNode(this->getDataAt(n));
      }
      temp = temp->next;
      n++;
    }
    alteLists.push_back(list2);
    alteLists.push_back(list1);
    return alteLists;
  }

};

LinkedList shuffleMerge(LinkedList list1, LinkedList list2) {
  LinkedList list;
  Node *temp1=list1.getHead(), *temp2=list2.getHead();
  while (temp1!=NULL && temp2!=NULL) {
    if (temp1!=NULL) list.addNode(temp1->data); 
    if (temp2!=NULL) list.addNode(temp2->data);
    if (temp1!=NULL) temp1=temp1->next;
    if (temp2!=NULL) temp2=temp2->next;
  }
  while (temp1!=NULL) {
    list.addNode(temp1->data);
    temp1=temp1->next;
  }
  while (temp2!=NULL) {
    list.addNode(temp2->data);
    temp2=temp2->next;
  }
  return list;
}

int main (int argc, char *argv[]) {
  LinkedList list1, list2, list3; 
  list1.addNode(1);
  list1.addNode(3);
  list1.addNode(5);
  list2.addNode(2);
  list2.addNode(4);
  list3 = shuffleMerge(list1, list2);
  list3.printList();
  return 0;
}
