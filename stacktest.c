#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX 100

void checkEmpty(Stack s) {
  if(isEmpty(&s)) {
    fprintf(stdout, "Stack is empty.\n");
  }
  else {
    fprintf(stderr, "Error: Stack should be empty.\n");
    exit(1);
  }
}

void checkSize(Stack s, int n) {
  if(size(&s) == n) {
    fprintf(stdout, "Size of stack is %d.\n", n);
  }
  else {
    fprintf(stderr, "Error: Stack size is not equal to number of elements pushed.\n");
  }
}

int main() {
  Stack s;

  fprintf(stdout, "Running tests for stack of int...\n\n");

  /* Make a stack of int */
  init(&s, sizeof(int), MAX);

  /* Initially stack should be empty */
  checkEmpty(s);
  
  /* Now insert n integers */
  int i, n = 10;
  for(i = 1; i <= n; i++) {
    push(&s, (void *)&i);
  }

  /* size of stack should be n */
  checkSize(s, n);

  /* top element should be n */
  int t;
  t = *((int *)top(&s));
  if(t == n) {
    fprintf(stdout, "Top element is %d.\n", t);
  }
  else {
    fprintf(stderr, "Error: Top element is not equal to last pushed element.\n");
    fprintf(stderr, "Expected %d, got %d.\n", n, t);
    exit(1);
  }

  /* pop all elements */
  for(i = n; i >= 1; i--) {
    t = *((int *)pop(&s));
    if(i != t) {
      fprintf(stderr, "Error: Elements not being popped in LIFO manner.\n");
      fprintf(stderr, "Expected %d but got %d.\n", i , t);
      exit(1);
    }
  }

  /* Stack should be empty now */
  checkEmpty(s);
  
  destroy(&s);

  fprintf(stdout, "All tests passed for stack of int.\n\n");

  fprintf(stdout, "Running tests for stack of double...\n\n");
  /* Make a stack of double */
  init(&s, sizeof(double), MAX);

  /* Initially stack should be empty */
  checkEmpty(s);
  
  /* Now insert n double values */
  double values[] = {1.1, -0.5, 9.7, 11.0, 15.1, -72.7, 45.6, 10.1, 5.5, 8.3};

  for(i = 0; i < n; i++) {
    push(&s, (void *)(values + i));
  }

  /* size of stack should be n */
  checkSize(s, n);

  /* top element should be last pushed element */
  double d;
  d = *((double *)top(&s));
  if(d == values[n-1]) {
    fprintf(stdout, "Top element is %.1lf.\n", d);
  }
  else {
    fprintf(stderr, "Error: Top element is not equal to last pushed element.\n");
    fprintf(stderr, "Expected %.1lf, got %.1lf.\n", values[n-1], d);
    exit(1);
  }

  /* pop all elements */
  for(i = n-1; i >= 0; i--) {
    d = *((double *)pop(&s));
    if(values[i] != d) {
      fprintf(stderr, "Error: Elements not being popped in LIFO manner.\n");
      fprintf(stderr, "Expected %.1lf but got %.1lf.\n", values[i] , d);
      exit(1);
    }
  }

  /* Stack should be empty now */
  checkEmpty(s);
  
  destroy(&s);

  fprintf(stdout, "All tests passed for stack of double.\n\n");

  return 0;
}
