#include "stdio.h"
#include "stdlib.h"

char* getFirstWord(char* str){
  char *start,*iter;
  start = iter = str;
  while(*iter != '\0' && *iter != ' '){
    iter++;
  }
  if(*iter == ' '){
    *iter = '\0';
    iter++;
  }
  return iter;
}

void testGetFirstWord(){
  char str[] = "This is my test string to test a new function.";
  char* curr = str;
  while(*curr != '\0'){
    char* word = getFirstWord(curr);
    printf("%s, ",curr);
    curr = word;
  }
}

int main(){
  testGetFirstWord();
  return 0;
}
