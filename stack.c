#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init(Stack *s, int elemSize, int maxElements) {
  byte *storage;

  /* Try to allocate memory */
  storage = (byte *)malloc(elemSize * maxElements);
  if(storage == NULL) {
    fprintf(stderr, "Insufficient memory to initialize stack.\n");
    exit(1);
  }

  /* Initialize an empty stack */
  s->top = 0;
  s->maxElements = maxElements;
  s->elemSize = elemSize;
  s->storage = storage;
}

int isEmpty(Stack *s) {
  /* top is 0 for an empty stack */
  return (s->top == 0);
}

int size(Stack *s) {
  return s->top;
}

void push(Stack *s, void *elem) {
  if(s->top == s->maxElements) {
    fprintf(stderr, "Element can not be pushed: Stack is full.\n");
    exit(1);
  }
  int start = s->top * s->elemSize, i;
  for(i = 0; i < s->elemSize; i++) {
    *(s->storage + start + i) = *((byte *)(elem + i));
  }
  s->top = s->top + 1;
}

void* pop(Stack *s) {
  if(isEmpty(s)) {
    fprintf(stderr, "Can not pop from an empty stack.\n");
    exit(1);
  }
  void *elem = top(s);
  s->top = s->top - 1;
  return elem;
}

void* top(Stack *s) {
  if(isEmpty(s)) {
    fprintf(stderr, "Can not pop from an empty stack.\n");
    exit(1);
  }
  int start = (s->top - 1) * s->elemSize, i;
  byte *elem;
  elem = (byte *)malloc(s->elemSize);
  for(i = 0; i < s->elemSize; i++) {
    *(elem + i) = *(s->storage + start + i);
  }
  return (void *)elem;
}

void destroy(Stack *s) {
  free(s->storage);
  s->top = 0;
}
