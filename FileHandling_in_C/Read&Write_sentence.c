#include<stdio.h>

int main()
{
    FILE *fp;
    char sentence[100];
    fp = fopen("/Users/chiranjeev/Documents/Atom C and C++/FileHandling_in_C/test2.txt","w");
    printf("Enter data \n" );

    gets(sentence);


    fclose(fp);
    if ((fp = fopen("/Users/chiranjeev/Documents/Atom C and C++/FileHandling_in_C/test2.txt", "r")) == NULL)
  {
      printf("Error! opening file");
      // Program exits if file pointer returns NULL.
      exit(1);
  }

  // reads text until newline
  fscanf(fp,"%[^\n]", sentence);

  printf("Data from the file:\n%s", sentence);
  fclose(fp);

    return 0;
}
