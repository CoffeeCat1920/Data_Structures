#include <iostream>

struct ListNode {
  ListNode* next;
  int data;
  ListNode(int data) {
    this->data = data;
    this->next = NULL;
  }
};

ListNode* reverseKGroup(ListNode* head, int k) {
  if (head == NULL) {
    return head;
  } 
  else {
    ListNode *hare = head, *tortoise = head;
    while (hare != NULL) {
      for (int i=0; i<k; i++) {
        if (hare != NULL)
        hare = hare->next;
      }
      tortoise->data = hare->data;
      tortoise = hare;
    }
    return head;
  }
}

int main (int argc, char *argv[]) {
  ListNode* head = NULL, *temp = head;
  int data;
  for (int i = 1; i<6; i++) {
    std::cout << "Enter the " << i << ":";
    std::cin>>data;
    if (temp==NULL) {
      temp = new ListNode(data);
    }
    else {
      temp = new ListNode(data);
    }
      temp=temp->next;
      std::cout << "\n";
  }
  while (head!=NULL) {
    std::cout << head->data << " ";
    head=head->next;
  }
  std::cout << "\n";
  return 0;
}
