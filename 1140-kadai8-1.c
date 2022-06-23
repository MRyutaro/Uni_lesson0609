#include <stdio.h>
#define STACK_SIZE 10

int array[STACK_SIZE];
int stack_ptr = 0;

void initstack(void)
{
  stack_ptr = 0;
}

int chkempty(void)
{
  return stack_ptr == 0;
}

int chkfull(void)
{
  return stack_ptr == STACK_SIZE;
}

void push(int x)
{
  array[stack_ptr] = x;
  stack_ptr++;
}

int pop(void)
{
  int x = array[stack_ptr - 1];
  stack_ptr--;
  return x;
}

void printstack(void)
{
  int i;
  printf("\t");
  printf("スタックの中 [ ");
  for (i = 0; i < stack_ptr; i++)
  {
    printf("%d", array[i]);
    if (i != stack_ptr - 1)
      printf(" ");
  }
  printf(" ]\n");
}

int main(void)
{
  int i, x, cmd;
  initstack();

  while (1)
  {
    fprintf(stderr, "番号を入力してください (1) PUSH, (2) POP, (3) SHOW (4) EXIT -> ");
    scanf(" %d", &cmd);

    switch (cmd)
    {
    case 1:
      if (chkfull() == 0)
      {
        printf("\tpushする整数を入力して下さい -> ");
        scanf("%d", &x);
        push(x);
      }
      else
      {
        fprintf(stderr, "\tスタックはフルのためプッシュできません\n");
      }
      break;

    case 2:
      if (chkempty() == 0)
      {
        printf("\t%d をpopしました\n", pop());
      }
      else
      {
        fprintf(stderr, "\tスタックは空のためポップできません\n");
      }
      break;
    case 3:
      printstack();
      break;
    case 4:
      fprintf(stderr, "\t終了します");
      return 0;
    default:
      fprintf(stderr, "\t1から4までの番号を入力して下さい\n");
    }
  }
  return 0;
}