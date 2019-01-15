#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

struct stack
{
    int top;
    unsigned capacity;
    char *array;
};
struct stack* createStack(unsigned capacity)
{
  struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
  stack->capacity = capacity;
  int top = -1;
   stack->array = (char*) malloc(stack->capacity * sizeof(char));
  return stack;
}
int isFull(struct stack* stack)
{
  return stack->top == stack->capacity-1;
}
int isEmpty(struct stack* stack)
{
  return stack->top == -1;
}
void push(struct stack* stack,char item)
{
  if(isFull(stack))
  return;
  stack->array[++stack->top] =item;
}
char pop(struct stack* stack)
{
  if(isEmpty(stack))
  return INT_MIN;

  return stack->array[stack->top--];
}
void reverse(char str[])
{
  int n = strlen(str);
  struct stack* stack = createStack(n);
  int i;
  for(i= 0;i<n;i++)
  push(stack,str[i]);

  for(i= 0;i<n;i++)
  str[i] =pop(stack);

}
int main()
{
    char str[] = "GeeksQuiz ";

    reverse(str);
    printf("Reversed string is %s", str);

    return 0;
}
