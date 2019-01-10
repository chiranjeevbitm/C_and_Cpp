#include <stdio.h>
int main()
{
    char ch[100];
    int i=0;
    FILE *fpr;
    fpr = fopen("/Users/chiranjeev/Documents/Atom C and C++/FileHandling_in_C/Sample.txt", "r");


    if (fpr == NULL)
    {
         puts("Input file cannot be opened");
    }
    fscanf(fpr,"%[^\n]", ch);
    printf("Alternate character\n");
    while(ch[i]!='\0')
    {
      printf("%c\n",ch[i]);
      i=i+2;
    }


    /* Closing both the files */
    fclose(fpr);
    return 0;
  }
