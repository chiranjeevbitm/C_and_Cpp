
// FUnction
struct node *reverse(struct node *head, int k) {
  node *cur = head;
  node *prev = NULL;
  node *prevPrevStart = NULL;
  node *prevStart = NULL;

  int i = 0;
  while (cur) {
    if (i == k - 1)
      head = cur;

    if (i % k == 0) {
      if (prevPrevStart)
        prevPrevStart->next = prev;

      prevPrevStart = prevStart;
      prevStart = cur;
      prev = nullptr;
    }

    node *nextNode = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nextNode;
    i++;
  }

  if (prevPrevStart)
    prevPrevStart->next = prev;

  return head;
}
}
