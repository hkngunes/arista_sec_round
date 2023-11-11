// Here there was only the first print and it is asked the result of this print. I said 13, but result is 24.

#include "stdio.h"

typedef struct _s{
  char a;
  long b;
  int c;
} S;

int main(){
  S x = {};
  printf("Size of struct : %lu\n", sizeof(S));
  printf("Address of char a : %p\n", &(x.a));
  printf("Address of long b : %p\n", &(x.b));
  printf("Address of int c : %p\n", &(x.c));
  return 0;
}
