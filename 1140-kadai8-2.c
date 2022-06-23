/* 例題 8-3 のプログラムリスト */

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
  int element;
  struct cell *next;
} CELL;

void *push(int x, CELL *init)
{
  CELL *q, *r;
  r = (CELL *)malloc(sizeof(CELL));
  q = init;
  init = r;
  r->element = x;
  r->next = q;
  return (init);
}

void *pop(CELL *init)
{
  CELL *q;
  if (init != NULL)
  {
    q = init;
    init = init->next;
    free(q);
    return (init);
  }
  else
  {
    printf("スタックは空です。\n");
    exit(1);
  }
}

void printstack_data(CELL *init)
{
  CELL *p;
  p = init;
  printf("\t");
  printf("スタックの中 [ ");
  while (p != NULL)
  {
    printf("%d", p->element);
    printf(" ");
    p = p->next;
  }
  printf("]\n");
  fflush(stdout);
}

void printstack_add(CELL *init)
{
  CELL *p;
  p = init;
  printf("\t");
  printf("スタックの中 [ ");
  while (p != NULL)
  {
    printf("%p", p->next);
    printf(" ");
    p = p->next;
  }
  printf("]\n");
  fflush(stdout);
}

int main(void)
{
  CELL *init;
  CELL *q;
  int x, cmd;

  init = NULL;

  while (1)
  {
    fprintf(stderr, "番号を入力してください (1) PUSH, (2) POP, (3) SHOW(data), (4) SHOW(add), (5)EXIT -> ");
    scanf(" %d", &cmd);

    switch (cmd)
    {
    case 1:
      printf("\tpushする整数を入力して下さい -> ");
      scanf("%d", &x);
      init = push(x, init);
      break;
    case 2:
      q = init;
      if (q != NULL)
      {
        printf("\tpopします\n");
        init = pop(init);
        q = init;
      }
      else
      {
        fprintf(stderr, "\tスタックは空のためpopできません\n");
      }
      break;
    case 3:
      printstack_data(init);
      break;
    case 4:
      printstack_add(init);
      break;
    case 5:
      fprintf(stderr, "\t終了します");
      return 0;
    default:
      fprintf(stderr, "\t1から5までの番号を入力して下さい\n");
    }
  }

  return 0;
}