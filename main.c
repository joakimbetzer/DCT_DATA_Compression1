#include "contiki.h"
#include "Data.h"
#include <math.h>
#include <stdio.h> /* For printf() */

//declaring variables/funcions
void encoding();

/*---------------------------------------------------------------------------*/
PROCESS(start, "Start the process ");
AUTOSTART_PROCESSES(&start);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(start, ev, data)
{
  long t1;
  long t2;
  long tTotal;
  PROCESS_BEGIN();
  t1 = clock_seconds();
  encoding();
  t2 = clock_seconds();
  tTotal = t2 - t1;
  printf("Total time for execution: %lu \n", tTotal);
  PROCESS_END();
}

void encoding()
{
  double y[16][32];
  for(int k = 0; k < 16; k++){ 
      for(int m = 0; m < 32; m++) { 
          for(int n = 0; n < 32; n++) {
              y[k][m] += XSignal512[k*32 + n] * HSignal[m][n];
        }
      }      
  }
  int d1 = 0;

  for(int d2 = 0; d2 < 16; d2++){
      for(int d = 0; d < 4; d++){
        printf("%d:",d1);
        printf("%f\n",y[d2][d]);
        d1 = d1 + 1;}
  }
}

//Attempt to do it with the given algorithm, worked for 1st point
/*
void actualEncoding(int length) 
{
  double piConstant = M_PI/8;
  int k;
  int n = 0;
  int h = 8;
  //dividing signals into subsets
  for (k = 0; k < 512; k++){
    encodedList[k] = 0;
    int i = 0;
    //applying DCT transform on each subset
    while (n < h && h <= 512){ 
      encodedList[k] = encodedList[k] + XSignal512[n] * cos(piConstant * ((i + 0.5) * k));
      i++;
      n++;
    }
    if (h <= 512){
      h = n + 8;
    }
    
    if (k == 0){
      encodedList[k] = encodedList[k] * sqrt((1.0/8.0));
    } else {
      encodedList[k] = encodedList[k] * sqrt((2.0/8.0));
    }
    printf("n value: %d\n h value: %d\n encodedlist: %lf\n", n, h, encodedList[k]);
  }
  printf("Done with DCT transformation! \n");
}*/