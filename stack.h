#ifndef STACK_H
#define STACK_H

typedef struct Stack {
  int top;
  void *storage;
  int elemSize;
  int maxElements;
} Stack;

/* Function for initializing the Stack */
void init(Stack *s, int elemSize, int maxElements);

/* Function for checking whether the stack is empty */
/* Returns non-zero value if stack is not empty */
int isEmpty(Stack *s);

/* Function for returning number of elements in the stack */
int size(Stack *s);

/* Inserts an element at top of stack */
void push(Stack *s, void *elem);

/* Removes an element from top of stack */
/* Returns a pointer to the element removed */
void* pop(Stack *s);

/* Returns a pointer to the top element without removing it from stack */
void* top(Stack *s);

/* Deallocates the memory allocated to stack */
void destroy(Stack *s);

#endif
