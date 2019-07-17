
#include<stdio.h>
int main(int argc, char  *argv[]) {
  int c[10];
  int i,j,temp,greatest;
  j=0;
  for(i=1;i<argc;i++)
  {
    temp =atoi(argv[i]);
    c[j] = temp;
    j++;
  }
  greatest = c[0];
  for(i=0;i<10;i++)
  {
    if(c[i]>greatest)
    greatest =c[i];
  }
 printf("greatest of 10 numbers is %d\n", greatest);
  return 0;
}
