Generic Stack Implementation in C
=================================

Stack : Last in First Out (LIFO) dynamic set.
An array based implementation is done.

This directory contains following files:
* stack.h: declarations of all the functions on stack
  Type declarations:
  * byte: byte is equivalent to unsigned char (which occupies 1 Byte).
  * struct Stack:
    * top: This stores number of elements present in the stack (which is also equal to the index of top element).
    * storage: an array of bytes to store all stack elements.
    * elemSize: size (in bytes) of one element of stack.
    * maxElements: Maximum elements that can be inserted in the stack.

  Methods defined:
  * init: Initializes the stack of a particular data-type. It takes size of the type and max elements as parameters.
  * isEmpty: Checks if the stack is empty. 
  * size: Returns number of elements present in the stack.
  * push: Pushes an element into the stack. It takes a void pointer as a element. This pointer must point to element to be inserted.
  * pop: Removes the top element from the stack and returns a void pointer to the removed value.
  * top: Returns a void pointer to the value at top of stack without actually removing the element.
  * destroy: Destroys the memory allocated to stack.

* stack.c: Implementation of functions defined in stack.h
  * init:
    Uses malloc to allocate (elemSize*maxElements) bytes to storage. Also makes top to 0.
  * isEmpty:
    Checks if top is 0.
  * size:
    Returns top.
  * push:
    First checks if space is available. Then copies the element given in parameter byte by byte on top of stack. Increases top by 1.
  * pop:
    First checks if stack is empty. Then calls top fn to get top element, decreases top by 1 and returns the element.
  * top:
    Checks if stack is empty. Allocates elemSize bytes to a new element. Copies elemSize bytes from top of stack into element and then returns a void pointer to it.
  * destroy:
    frees the memory allocated to storage.

* stacktest.c: Checks all the methods defined using a stack of integers and a stack of doubles.

* Makefile: `make` compiles everything. Other options: `make run` and `make compile`.
