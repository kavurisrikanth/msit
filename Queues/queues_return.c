/*
  Implements a queue. Using linked lists.
  This version contains a problem. Even though I'm sending the head and tail
  pointers into the insert function, they are not updated by the time control
  reaches the calling function. Why?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Basic node structure
struct Node {
  int num;
  struct Node *next;
  // struct Node *prev;
};

/*
  FUNCTION DECLARATIONS
*/
// struct Node** insert(int num, struct Node *head, struct Node *tail);
// struct Node** rem(struct Node *head, struct Node *tail, int *val);
void insert(int num, struct Node *head, struct Node *tail, struct Node *temp);
int rem(struct Node *head, struct Node *tail);
void print_queue(struct Node *head);
// void set_head(struct Node *ptr);
// void set_tail(struct Node *ptr);
// struct Node* get_head();
// struct Node* get_tail();



int main(void) {
  // struct Node *head = (struct Node *)calloc(1, sizeof(struct Node)),
  //             *tail = (struct Node *)calloc(1, sizeof(struct Node));

  // Declare head and node pointers.
  // Don't assign memory to them; the nodes will be created as values are added.
  struct Node *head = NULL,
              *tail = NULL,
              *temp = NULL;

  print_queue(head);

  int i = 0;
  srand(0);

  // Insert 15 random numbers into the queue.
  for(i = 0;i < 15; i++) {
    insert(rand() % 100, head, tail, temp);
  }

  print_queue(head);

  // and then remove 10 of them
  for(i = 0; i < 10;i++) {
    printf("removed: %d\n", rem(head, tail));
  }
  print_queue(head);


  return 0;
}

void insert(int num, struct Node *head, struct Node *tail, struct Node *temp) {
  /*
    Inserts an element into a queue.
    Inputs: num, int, number to be inserted into the queue.
            head, struct Node *, head of the queue
            tail, struct Node *, end of the queue
    Returns: Nothing.

    The function should be able to update the head and tail pointers, since it
    is call-by-reference.
  */

  // Create a new node to add to the queue.
  temp = (struct Node *)calloc(1, sizeof(struct Node));
  temp->next = NULL;
  temp->num = num;

  // if(temp == NULL)
  //   printf("temp NULL\n");

  // If the queue is empty, the new node is the first.
  if(head == NULL) {
    head = temp;
  }

  // Queue is not empty, so add the new node at the end.
  if(tail != NULL) {
    tail->next = temp;
  }
  tail = temp;
}

int rem(struct Node *head, struct Node *tail) {
  /*
    Removes a node from the queue.
    Inputs: head, struct Node *, head of the queue
            tail, struct Node *, end of the queue
    Returns: int, the value of the element that was just removed.
  */

  // If both head and tail are NULL, then there
  // is nothing in the queue.
  assert(head != NULL && tail != NULL);

  int ans = head->num;
  struct Node *temp = head;

  head = head->next;
  temp->next = NULL;
  free(temp);
  temp = NULL;

  return ans;
}

void print_queue(struct Node *head) {
  /*
    Prints a queue.
    Inputs: head, struct Node *, head of the queue
    Returns: Nothing.
  */

  struct Node *temp = head;

  if(temp == NULL)
    printf("\nQueue is empty.");
  else {
    printf("\nQueue: ");
    while(temp != NULL) {
      printf("%d ", temp->num);
      temp = temp->next;
    }
  }
  printf("\n");
}

// void set_head(struct Node *ptr) {
//   head = ptr;
// }
//
// void set_tail(struct Node *ptr) {
//   tail = ptr;
// }
//
// struct Node* get_head() {
//   return head;
// }
//
// struct Node* get_tail() {
//   return tail;
// }
