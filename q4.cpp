// Here the class blueprint was given and asked to fill it. The test function is written by me, 
// in the orijinal question, there was several test functions and expected value was given directly.
// To test my code, i convert them to test function that takes inputs from user.

// In my solution i calculate sum and avr values in get function. But ı used i < (ind<w_size)?ind:w_size in the for condition,
// but it didnt work and i could not understand it. After closing with (), code is run successfully.
// Then it is asked to improve my solution but I could not offer a second solution. Then he said that maybe you can calculate sum
// in a different place. Than a define sum as class var and calculate it in put, however, i was forget to differ the previos value
// from sum. :(

#include "stdio.h"
#include "stdlib.h"

class LastRecent{
 public:
  unsigned int w_size,i_size;
  int sum;
  int* arr;
  LastRecent(int w_s){
    arr = (int*)malloc(w_size*sizeof(int));
    sum=0;
    w_size=w_s;
    i_size=0;
  }

  void put(int val){
    if(i_size >= w_size){
      sum -= *(arr+(i_size%w_size));
    }
    *(arr+(i_size%w_size)) = val;
    sum += val;
    i_size++;
  }

  float getAvr(){
    if(i_size >= w_size){
      return (float)sum/w_size;
    }
    return (float)sum/i_size;
  }

};

void testLastRecent(){
  unsigned int w_size=0;
  int inp,sum,ind;
  float avr,res;
  LastRecent* lr;
  int* inps;
  printf("Enter window_size: ");
  scanf("%ui", &w_size);
  while(w_size!=999){
    lr = new LastRecent(w_size);
    inps = (int*)malloc(3*w_size*sizeof(int));
    sum=0;
    ind=0;
    while(1){  
      printf("Fill list: ");
      scanf("%d",&inp);
      if(inp == 999){
	break;
      }
      if(ind>=w_size){
	sum-=*(inps+ind-w_size);
      }
      *(inps+ind) = inp;
      sum+=inp;
      ind++;
    }
    if(ind >w_size){
      avr = (float)sum/w_size;
    }else{
      avr = (float)sum/ind;
    }
    
    //test
    for(int i=0;i<ind;i++){
      lr->put(*(inps+i));
    }
    res = lr->getAvr();
    printf("Window size : %d\n",w_size);
    for(int i=0;i<ind-1;i++){
      printf("%d, ",*(inps+i));
    }
    printf("%d\n\n",*(inps+ind-1));
    if(res==avr){
      printf("Test passed: act(%f) - exp(%f)\n",res,avr);
    }else{
      printf("Test failed: act(%f) - exp(%f)\n",res,avr);
    }

    free(inps);
    //Continue?
    printf("Enter window size(999 exits): ");
    scanf("%ui",&w_size);
  }

}

int main(void){
  testLastRecent(); 
  return 0;
  
}
