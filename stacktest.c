#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX 100

int main() {
  /* Make a stack of int */
  Stack s;
  init(&s, sizeof(int), MAX);

  /* Initially stack should be empty */
  if(isEmpty(&s)) {
    fprintf(stdout, "Stack is empty initially.\n");
  }
  else {
    fprintf(stderr, "Error: Stack should be empty initially.\n");
    exit(1);
  }
 
  /* Now insert n integers */
  int i, n = 10;
  for(i = 1; i <= n; i++) {
    push(&s, (void *)&i);
  }

  /* size of stack should be n */
  if(size(&s) == n) {
    fprintf(stdout, "Size of stack is %d .\n", n);
  }
  else {
    fprintf(stderr, "Error: Stack size is not equal to number of elements pushed.\n");
  }

  /* top element should be n */
  int t;
  t = *((int *)top(&s));
  if(t == n) {
    fprintf(stdout, "Top element is %d .\n", t);
  }
  else {
    fprintf(stderr, "Error: Top element is not equal to last pushed element.\n");
    fprintf(stderr, "Expected %d, got %d .\n", n, t);
    exit(1);
  }

  /* pop all elements */
  for(i = n; i >= 0; i++) {
    int t = *((int *)pop(&s));
    if(i != t) {
      fprintf(stderr, "Error: Elements not being popped in LIFO manner.\n");
      fprintf(stderr, "Expected %d but got %d .\n", i , t);
      exit(1);
    }
  }

  /* Stack should be empty now */
  if(isEmpty(&s)) {
    fprintf(stdout, "Stack is empty after popping all elements.\n");
  }
  else {
    fprintf(stderr, "Stack should be empty after popping all elements.\n");
  }

  destroy(&s);
  return 0;
}
