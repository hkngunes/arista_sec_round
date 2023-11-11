// Previous version of this code was giving segmentation fault and it is asked to find the errors in the code.

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
    iter++; // this iteration was not available here - 1 fault
  }
  return iter;
}

void testGetFirstWord(){
  char str[] = "This is my test string to test a new function.";  // This was defined as char*, this was the second fault.
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

// I found both but took nearly 40 mins.
