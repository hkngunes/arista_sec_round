#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void foundWords(const char* words[], const char *rows[], int size ){
  int ind = 0;
  while(words[ind]){
    const char* word = words[ind++];
    for(int i=0;i<size;i++){
      for(int j = 0; j < sizeof(rows[0]); j++){
	if(rows[i][j]==word[0]){
	  int k = 0;
	  while(word[k] != '\0' && word[k] == rows[i][j+k]){
	    k++;
	  }
	  if(word[k]=='\0'){
	    printf("Found %s at row %d offset %d\n",word,i,j);
	  }
	}
      }
    }
  }
}

void testFoundWords(){
  const char *rows[] = {
    "123abcar",
    "lemoncar",
    "2garlic4",
    "caycatar",
    "cercetle",
    "2drflemo",
    "f3garlic"
  };

  const char *words[5] = {
    "car",
    "cat",
    "lemon",
    "garlic",
    NULL
  };

  foundWords(words, rows, 7);
}

int main(){
  testFoundWords();
  return 0;
}
