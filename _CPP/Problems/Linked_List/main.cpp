#include <iostream>

struct Node {
  int data;
  Node* next;
};

class LinkedList {
private:
  Node* head;
public:
  LinkedList() {
    head = NULL;
  }
  LinkedList operator+(LinkedList const& obj) {
    LinkedList temp;
    Node* tempHead = temp.head;
    while (tempHead->next!=NULL) {
      tempHead=tempHead->next; 
    }
    tempHead->next=obj.head;
    return temp;
  }
  Node* getHead() {
    return head;
  }
  Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
  } 
  void addNode(int data) {
    if (head==NULL) {
      head = newNode(data);
      return;
    }
    else {
      Node* temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next=newNode(data);
      return;
    }
  } 
  void printList() {
    if (head==NULL) {
      return;
    } 
    else {
      Node* temp = head;
      while (temp!=NULL) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
      }
    }
    return;
  }
  int count() {
    if (head==NULL) {
      return 0;
    }
    else {
      Node* temp = head;
      int count=0;
      while (temp!=NULL) {
        count++; 
        temp = temp->next;
      }
      return count;
    }
  }
  int GetNth(int index) {
    if (head==NULL) {
      return 0;
    }
    else {
      if (this->count()<=index) {
        return 0;
      }
      else {
        Node* temp = head;
        for (int i=0; i<index; i++) {
          temp = temp->next;
        }
        return temp->data;
      }
    }
  }
  bool DeleteList() {
    if (head==NULL) {
      return true;
    }
    else {
      Node* temp = head;
      while (temp!=NULL) {
        Node* temp1 = temp->next;
        delete temp;
        temp = temp1;
      }
      head = NULL;
      return true;
    }
  }
  int Pop() {
    if (head==NULL) {
      return 0;
    }
    else {
      Node* temp = head;
      Node* next = temp->next;
      int a = temp->data;
      delete temp;
      head = next;
      return a;   
    }
  }
  void InsertNth(int index, int data) {
    if (head==NULL) {
      addNode(data);
    }
    else {
      if (index==0) {
        Node* temp = head;
        Node* temp1 = newNode(data);
        head = temp1;
        temp1->next = temp;
        return;
      }
      else {
        Node* temp = head;
        for (int i=0; i<index-1; i++) {
          temp = temp->next;
        }
        Node *temp1 = newNode(data);
        Node *next = temp->next;
        temp->next = temp1;
        temp1->next = next;
      }
    }
  }
  void Sort() {
    if (head==NULL) {
      return;
    }
    else {
      Node* temp = head;
      Node* temp1;
      while (temp!=NULL) {
        temp1=temp->next;
        while (temp1!=NULL) {
          if (temp->data>=temp1->data) {
            int tempdata = temp->data;
            temp->data = temp1->data;
            temp1->data = tempdata;
          }
          temp1=temp1->next;
        }
        temp=temp->next;
      }
    }
    return;
  }
  void SortInput(int data) {
    if (head==NULL) {
      return;
    }
    else {
      this->Sort();
      Node* temp=head, *insert=newNode(data), *previous, *next;
      while (temp->next->data<=data) {
        temp=temp->next;
      }
      previous = temp; 
      next = temp->next;
      previous->next = insert;
      insert->next = next;
    }
  }
  void Concatinate(LinkedList* list) {
    Node* temp = head;
    while (temp->next!=NULL) {
      temp = temp->next;
    }
    temp->next = list->head;
    list->head = NULL; 
  }
}; 

int main (int argc, char *argv[]) {
  LinkedList list1, list2, list3; 
  list1.addNode(1);
  list1.addNode(2);
  list1.addNode(3);
  list2.addNode(4);
  list2.addNode(5);
  list2.addNode(6);
  list3 = list1 + list2;
  list3.printList();
  return 0;
}
