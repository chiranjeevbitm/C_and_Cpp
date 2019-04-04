

int getMiddle(Node *head) {
  if (head == NULL) {
    return -1;
  }
  Node *slow = head;
  Node *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}
