/*
  Implements a queue. Using linked lists.
  Does the same thing as queues_args.c, but sets head and tail as global variables.
  This works properly.
  Why?
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
void insert(int num);
int rem();
void print_queue();
void set_head(struct Node *ptr);
void set_tail(struct Node *ptr);
struct Node* get_head();
struct Node* get_tail();

// Head and tail declared globally.
struct Node *head = NULL,
            *tail = NULL;

int main(void) {
  // struct Node *head = (struct Node *)calloc(1, sizeof(struct Node)),
  //             *tail = (struct Node *)calloc(1, sizeof(struct Node));



  print_queue(head);

  int i = 0;
  srand(0);

  for(i = 0;i < 15; i++) {
    insert(rand() % 100);
  }

  print_queue(head);

  for(i = 0; i < 10;i++) {
    printf("removed: %d\n", rem());
  }
  print_queue(head);


  return 0;
}

void insert(int num) {
  /*
    Inserts an element into a queue.
    Inputs: num, int, number to be inserted into the queue.
    Returns: Nothing.

    The function should be able to update the head and tail pointers, since they
    are global variables.
  */

  struct Node *temp = (struct Node *)calloc(1, sizeof(struct Node));
  temp->next = NULL;
  temp->num = num;

  // if(temp == NULL)
  //   printf("temp NULL\n");

  if(head == NULL) {
    head = temp;
  }

  if(tail != NULL) {
    tail->next = temp;
  }
  tail = temp;
}

int rem() {
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

void print_queue() {
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

void set_head(struct Node *ptr) {
  head = ptr;
}

void set_tail(struct Node *ptr) {
  tail = ptr;
}

struct Node* get_head() {
  return head;
}

struct Node* get_tail() {
  return tail;
}
