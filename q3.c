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
