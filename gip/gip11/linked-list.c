#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head;

struct node *makeNode(int val) {
  struct node *node = NULL;
  node = malloc(sizeof(struct node));
  if (node != NULL) {
    node -> data = val;
    node -> next = NULL;
    return node;
  } else {
    return NULL;
  }
}

void print_list(struct node *head) {
  struct node *temp = head;
  printf("(");
  while(temp != NULL) {
    printf(" %d", temp -> data);
    temp = temp -> next;
  }
  printf(" )\n");
}

// ascending
void insert_sorted(int val) {
  struct node *temp = head;
  while (temp -> next != NULL && temp -> next -> data < val) {
    temp = temp -> next;
  }
  struct node *inserted = makeNode(val);
  inserted -> next = temp -> next;
  temp -> next = inserted;
}

struct node *reverse() {
  struct node *previous = NULL;
  struct node *current = head;
  struct node *next = NULL;
  while (current != NULL) {
    next = current -> next;
    current -> next = previous;
    previous = current;
    current = next;
  }
  return previous;
}

int main(void) {
  struct node *a = makeNode(1);
  head = a;
  struct node *b = makeNode(2);
  a -> next = b;
  struct node *c = makeNode(3);
  b -> next = c;
  struct node *d = makeNode(5);
  c -> next = d;
  print_list(head);
  insert_sorted(7);
  insert_sorted(7);
  insert_sorted(4);
  insert_sorted(49);
  print_list(head);

  print_list(reverse());
  return 1;
}