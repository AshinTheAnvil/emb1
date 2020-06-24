/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief C file for assignment Co1M1 - stats
 *
 * Implements  functions for calculating numerical data
 * A simple C-Programming example that exhibits a handful of basic c-programming
 * features to show how to calculate some statistics on a set of numbers:
 *     -Median
 *     -Mean
 *     -Maximum
 *     -Minimum
 * @author ashin
 * @date 24 June 2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  puts("***ARRAY***");
  print_array(test, SIZE);
  puts("\n****SORTED ARRAY****");
  print_array(sort_array(test, SIZE), SIZE);
  puts("\n****STATISTICS****");
  print_statistics(test);
  

}
void print_statistics(unsigned char *data){
  printf("Median  = %0.1f\n",find_median(data,SIZE));
  printf("Mean    = %0.2f\n",find_mean(data,SIZE));
  printf("Maximum = %d\n",find_maximum(data,SIZE));
  printf("Minimum = %d\n",find_minimum(data,SIZE));

}
void print_array(unsigned char * data, unsigned int length){
  for(int ii=0; ii<length; ii++){
    if(ii == length-1){
      printf("%d\n", data[ii]);
    }else{
      printf("%d,", data[ii]);
    }
  }
}

unsigned char *sort_array(unsigned char *data,unsigned int length){
   for(int i=length-1; i>=0; i--){
    for(int j=0; j<i; j++){
      if(data[j]>data[j+1]){
        unsigned char temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
      }
    }
  }  
  return data;
}

float find_median(unsigned char * data, unsigned int length){
  data = sort_array(data, length);
  float median=0.0;
  if(SIZE % 2 == 0){
    median = (data[length/2] + data[(length/2)-1])/2.0;
  }else{
    median = data[length/2];
  }
  return median;
}

float find_mean(unsigned char * data, unsigned int length){
  float sum = 0.0;
  for(int i=0; i<length; i++){
    sum += data[i];
  }
  return sum/length;
}

unsigned int find_maximum(unsigned char * data, unsigned int length){
  unsigned int maximum = 0;
   data = sort_array(data, length);
   maximum = data[length-1];
  
  return maximum;
}
 

unsigned int find_minimum(unsigned char * data, unsigned int length){
  unsigned int minimum = 0;
   data = sort_array(data, length);
   minimum = data[0];
  
  return minimum;
}


























