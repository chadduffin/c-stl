#include "stack.h"

void stack_create(STACK **stack) {
  ERROR_NULL(stack);

  *stack = (STACK*)(malloc(sizeof(STACK)));

  vector_create(&((*stack)->vector_));
}

void stack_delete(STACK **stack) {
  ERROR_NULL(stack);
  ERROR_NULL(*stack);
  ERROR_NULL((*stack)->vector_);

  vector_delete(&((*stack)->vector_), NULL);

  free(*stack);

  *stack = NULL;
}

bool stack_empty(STACK *stack) {
  ERROR_NULL(stack);
  ERROR_NULL(stack->vector_);

  return vector_empty(stack->vector_);
}

void stack_push(STACK *stack, DATA data) {
  ERROR_NULL(stack);
  ERROR_NULL(stack->vector_);

  vector_push_back(stack->vector_, data);
}

void stack_pop(STACK *stack) {
  ERROR_NULL(stack);
  ERROR_NULL(stack->vector_);

  vector_pop_back(stack->vector_);
}

unsigned int stack_size(STACK *stack) {
  ERROR_NULL(stack);
  ERROR_NULL(stack->vector_);

  return vector_size(stack->vector_);
}

DATA* stack_top(STACK *stack) {
  ERROR_NULL(stack);
  ERROR_NULL(stack->vector_);

  return vector_back(stack->vector_);
}

